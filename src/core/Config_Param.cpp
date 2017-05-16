/**
 * @file    Config_Param.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include "Config_Param.hpp"

// Boost Libraries
#include <boost/algorithm/string.hpp>

// C++ Libraries
#include <sstream>
#include <stdexcept>


/********************************/
/*          Constructor         */
/********************************/
Config_Param::Config_Param()
  : m_class_name("Config_Param"),
    m_key_name("base")
{

}

/********************************/
/*          Constructor         */
/********************************/
Config_Param::Config_Param(const std::string&  key_name )
  : m_class_name("Config_Param"),
    m_key_name(key_name)
{
}


/***************************************/
/*          Get the Value Name         */
/***************************************/
std::string Config_Param::Get_Value_Name() const
{
    // Check actual value name
}

/****************************************/
/*          Get the Sub Config          */
/****************************************/
std::map<std::string,Config_Param> Config_Param::Get_Sub_Configs()const
{
    // Check if null
    return m_sub_configs;
}


/*************************************************/
/*          Query for a Key/Value Pair           */
/*************************************************/
void Config_Param::Query_KV_Pair(const std::string& key_name,
                                 std::string&       value_name,
                                 const std::string& default_value,
                                 const bool&        write_if_not_found)
{
    // split the key
    std::vector<std::string> keys = Parse_Key(key_name);

    // Initialize output to the default
    value_name = default_value;


    // Check if valid subkeys
    if( keys.size() > 1 )
    {
        // Check if sub-config exists
        if( m_sub_configs.find(keys[0]) != m_sub_configs.end() )
        {
            m_sub_configs[keys[0]].Query_KV_Pair(key_name,
                                                 value_name,
                                                 default_value,
                                                 write_if_not_found);
        }

        // Otherwise, check if we need to add
        else if( write_if_not_found )
        {
            std::string subkey = Pop_Key_Front(key_name);
            m_sub_configs[keys[0]] = Config_Param(keys[0]);
            m_sub_configs[keys[0]].Add_KV_Pair( subkey, value_name, "");
        }


    }

    // Otherwise if the base key
    else if( keys.size() == 1 )
    {
        // Check if the key exists
        if( m_kv_pairs.find(keys[0]) != m_kv_pairs.end() )
        {
            m_kv_pairs[keys[0]] = value_name;
        }

        // Otherwise, check if we need to add
        else if( write_if_not_found )
        {
            m_kv_pairs[keys[0]] = default_value;
        }

    }
}

/**************************************/
/*          Add Key/Value Pair        */
/**************************************/
void Config_Param::Add_KV_Pair( const std::string&  key_name,
                                const std::string&  value_name,
                                const std::string&  comment_name )
{
    // Parse Key
    std::vector<std::string> keys = Parse_Key(key_name);

    // Check if valid subkeys
    if( keys.size() > 1 )
    {
        // Pop the keyname
        std::string subkey = Pop_Key_Front(key_name);

        // Make sure the key exists, if not, add
        if( m_sub_configs.find(keys[0]) == m_sub_configs.end())
        {
            // Add new key
            m_sub_configs[keys[0]] = Config_Param( keys[0] );
        }

        // Append Subkey
        m_sub_configs[keys[0]].Add_KV_Pair( subkey, value_name, comment_name);
    }

    // Check if one valid key
    else if( keys.size() == 1 )
    {
        m_kv_pairs[keys[0]] = value_name;
        m_comment_pairs[keys[0]] = comment_name;
    }
}

/************************************/
/*          Parse the Key           */
/************************************/
std::vector<std::string>  Config_Param::Parse_Key(const std::string &key_name)
{
    // Create output list
    std::vector<std::string> output;

    // Split the string
    boost::split(output,key_name,boost::is_any_of("."));

    // Check empty strings
    if( output.size() == 1 && output[0] == "")
    {
        output.clear();
    }

    // Return output
    return output;
}


/******************************/
/*        Subtract Key        */
/******************************/
std::string Config_Param::Pop_Key_Front( const std::string& key_name )
{
    // Remaining Key
    std::string rem_key = "";


    // Check if subkey is inside key-name
    if( key_name.size() > 0 )
    {
        std::vector<std::string> keylist = Parse_Key(key_name);
        if( keylist.size() > 1)
        {
            rem_key = key_name.substr(keylist[0].size()+1);
        }
        else if( keylist.size() == 1 )
        {
            rem_key = key_name;
        }
        else{
            throw std::runtime_error("Unknown condition");
        }
    }

    return rem_key;
}

/****************************/
/*      Print to String     */
/****************************/
std::string Config_Param::ToString( const int& indent )const
{
    // create indent
    std::string gap( indent, ' ');

    // Create stream
    std::stringstream sin;

    // Print the Key Name
    sin << gap << "Key: " << m_key_name << std::endl;

    // Print Internal key/value pairs
    sin << gap << " - Internal Key/Value Pairs" << std::endl;
    for( auto kv : m_kv_pairs )
    {
        std::string key = kv.first;
        std::string val = kv.second;
        std::string com = "";
        if( m_comment_pairs.find(key) != m_comment_pairs.end()){
            com = m_comment_pairs.find(key)->second;
        }

        sin << gap << gap << "  - Key: " << key << ", Value: " << val << ", Comments: " << com << std::endl;
    }

    // Print Sub-Configs
    sin << gap << " - Internal Sub-Configurations" << std::endl;
    for( auto cf : m_sub_configs )
    {
        sin << cf.second.ToString(indent + 4);
    }

    return sin.str();
}

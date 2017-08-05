/**
 * @file    Config_Param.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include "Config_Param.hpp"


// Boost Libraries
#include <boost/algorithm/string.hpp>
#include <boost/filesystem.hpp>


// C++ Libraries
#include <iostream>
#include <sstream>
#include <stdexcept>


// Project Libraries
#include "../utility/String_Utilities.hpp"

namespace bf=boost::filesystem;

/********************************/
/*          Constructor         */
/********************************/
Config_Param::Config_Param()
  : m_class_name("Config_Param"),
    m_key_name(""),
    m_parent_key(""),
    m_change_tracking(false),
    m_has_changed(false)
{
}

/********************************/
/*          Constructor         */
/********************************/
Config_Param::Config_Param(const std::string&  key_name,
                           const std::string&  parent_key,
                           const bool&         change_tracking )
  : m_class_name("Config_Param"),
    m_key_name(key_name),
    m_parent_key(parent_key),
    m_change_tracking(change_tracking),
    m_has_changed(false)
{
}


/*******************************/
/*      Get the Parent Key     */
/*******************************/
std::string Config_Param::Get_Parent_Key()const
{
    std::string parent_key;

    if( m_parent_key != "")
    {
        parent_key = m_parent_key + ".";
    }
    parent_key += m_key_name;
    return parent_key;
}



/****************************************/
/*          Get the Sub Config          */
/****************************************/
std::map<std::string,Config_Param> Config_Param::Get_Sub_Configs()const
{
    // Check if null
    return m_sub_configs;
}


/*************************************************************/
/*              Get the Configuration File List              */
/*************************************************************/
std::map<std::string,std::string> Config_Param::Get_Config_List()const
{
    // Output maps
    std::map<std::string,std::string> sub_output;
    std::map<std::string,std::string> output;

    // Get the parent key
    std::string parent_key = Get_Parent_Key();
    std::string full_key;

    // Iterate over kv pairs
    for( auto it = m_kv_pairs.begin(); it != m_kv_pairs.end(); it++ )
    {
        if( parent_key != "" ){
            full_key = parent_key + ".";
        }
        full_key += it->first;
        output[full_key] = it->second;
    }

    // Iterate over sub-configs
    for( auto it = m_sub_configs.begin(); it != m_sub_configs.end(); it++ )
    {
        sub_output = it->second.Get_Config_List();

        // Merge the lists
        output.insert( sub_output.begin(), sub_output.end());
    }

    // return full list
    return output;
}


/*************************************************/
/*          Query for a Key/Value Pair           */
/*************************************************/
std::string  Config_Param::Query_KV_Pair(const std::string& key_name,
                                         bool&              value_found )const
{
    // Default values
    std::string output = "";
    value_found = false;

    // split the key
    std::vector<std::string> keys = Parse_Key(key_name);


    // Check if valid subkeys
    if( keys.size() > 1 )
    {
        // Check if sub-config exists
        if( m_sub_configs.find(keys[0]) != m_sub_configs.end() )
        {
            std::string subkey = Pop_Key_Front(key_name);
            output = m_sub_configs.find(keys[0])->second.Query_KV_Pair(subkey,
                                                                       value_found );
        }
    }

    // Otherwise if the base key
    else if( keys.size() == 1 )
    {
        // Check if the key exists
        if( m_kv_pairs.find(keys[0]) != m_kv_pairs.end() )
        {
            output = m_kv_pairs.find(keys[0])->second;
            value_found = true;
        }
    }

    return output;
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
            std::string subkey = Pop_Key_Front(key_name);
            m_sub_configs[keys[0]].Query_KV_Pair(subkey,
                                                 value_name,
                                                 default_value,
                                                 write_if_not_found);
        }

        // Otherwise, check if we need to add
        else if( write_if_not_found )
        {
            std::string subkey = Pop_Key_Front(key_name);
            m_sub_configs[keys[0]] = Config_Param(keys[0], Get_Parent_Key(), m_change_tracking);
            m_sub_configs[keys[0]].Add_KV_Pair( subkey, value_name, "");

            // Detect if we are tracking changes.
            if( m_change_tracking )
            {
                m_has_changed = true;
            }
        }


    }

    // Otherwise if the base key
    else if( keys.size() == 1 )
    {
        // Check if the key exists
        if( m_kv_pairs.find(keys[0]) != m_kv_pairs.end() )
        {
            value_name = m_kv_pairs[keys[0]];
        }

        // Otherwise, check if we need to add
        else if( write_if_not_found )
        {
            m_kv_pairs[keys[0]] = default_value;

            if( m_change_tracking )
            {
                m_has_changed = true;
            }
        }

    }
}

/**************************************/
/*          Add Key/Value Pair        */
/**************************************/
void Config_Param::Add_KV_Pair( const std::string&  key_name,
                                const std::string&  value_name,
                                const std::string&  comment_name,
                                const bool&         override )
{
    // Parse Key
    std::vector<std::string> keys = Parse_Key(key_name);

    // Check if valid subkeys
    if (keys.size() > 1)
    {
        // Pop the keyname
        std::string subkey = Pop_Key_Front(key_name);

        // Make sure the key exists, if not, add
        if (m_sub_configs.find(keys[0]) == m_sub_configs.end())
        {

            // Add new key
            m_sub_configs[keys[0]] = Config_Param(keys[0],
                                                  Get_Parent_Key(),
                                                  m_change_tracking);

            if( m_change_tracking )
            {
                m_has_changed = true;
            }
        }

        // Append Subkey
        m_sub_configs[keys[0]].Add_KV_Pair(subkey,
                                           value_name,
                                           comment_name,
                                           override);
    }

    // Check if one valid key
    else if (keys.size() == 1)
    {
        // Check if key exists
        if (m_kv_pairs.find(keys[0]) != m_kv_pairs.end())
        {
            if (override)
            {
                m_kv_pairs[keys[0]] = value_name;
                m_comment_pairs[keys[0]] = comment_name;


                if (m_change_tracking) {
                    m_has_changed = true;
                }
            }

        }

        // If no matching key is found
        else
        {
            m_kv_pairs[keys[0]] = value_name;
            m_comment_pairs[keys[0]] = comment_name;

            if( m_change_tracking )
            {
                m_has_changed = true;
            }
        }
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
    sin << gap << " - Change Tracking: " << std::boolalpha << m_change_tracking << std::endl;
    sin << gap << " - Has Changed: " << std::boolalpha << m_has_changed << std::endl;

    // Print Internal key/value pairs
    sin << gap << " - Internal Key/Value Pairs" << std::endl;
    for( auto it = m_kv_pairs.cbegin(); it != m_kv_pairs.end(); it++ )
    {
        std::string key = it->first;
        std::string val = it->second;
        std::string com = "";
        if( m_comment_pairs.find(key) != m_comment_pairs.end()){
            com = m_comment_pairs.find(key)->second;
        }

        sin << gap << gap << "  - Key: " << key << ", Value: " << val << ", Comments: " << com << std::endl;
    }

    // Print Sub-Configs
    sin << gap << " - Internal Sub-Configurations" << std::endl;
    for( auto cf = m_sub_configs.begin(); cf != m_sub_configs.end(); cf++ )
    {
        sin << cf->second.ToString(indent + 4);
    }

    return sin.str();
}

/************************************/
/*          Write to Stream         */
/************************************/
void Config_Param::Write_Stream(std::ostream &fout) const
{
    // Iterate over key/value pairs
    for( auto p : m_kv_pairs )
    {
        // Find key and value
        std::string key = p.first;
        std::string val = p.second;
        std::string full_key;
        if( m_parent_key != "" ){
            full_key = m_parent_key + "." + m_key_name + "." + key;
        }
        else
        {
            full_key = m_key_name + "." + key;
        }

        // Find the comment
        std::string com;
        if( m_comment_pairs.find(key) != m_comment_pairs.end())
        {
            com = m_comment_pairs.find(key)->second;
        }

        // Write to stream
        fout << com << std::endl;
        fout << full_key << " = " << val << std::endl;
        fout << std::endl;
    }

    // Iterate over sub-configs
    for( auto p = m_sub_configs.begin(); p != m_sub_configs.end(); p++ )
    {
        p->second.Write_Stream(fout);
    }
}


/***************************************/
/*    Set the Change Tracking Mode     */
/***************************************/
void Config_Param::Set_Change_Tracking( const bool& change_tracking )
{
    m_change_tracking = change_tracking;

    for( auto it = m_sub_configs.begin(); it != m_sub_configs.end(); it++ )
    {
        it->second.Set_Change_Tracking(m_change_tracking);
    }

}

/*************************************/
/*      Check if we have changed     */
/*************************************/
bool Config_Param::Has_Changed()const {

    bool output = m_has_changed;

    // Otherwise, check children
    for (auto p = m_sub_configs.begin(); p != m_sub_configs.end(); p++ )
    {
        if( !output )
        {
            output |= p->second.Has_Changed();
        }
    }

    return output;
}


/*******************************************/
/*          Parse a Key/Value File         */
/*******************************************/
Config_Param Config_Param::Load_Key_Value_File(const std::string &pathname,
                                               bool&              status )
{
    // Create output object
    Config_Param output;
    status = true;

    // Check if the file exists
    if( !bf::exists(bf::path(pathname)))
    {
        status = false;
        std::cerr << "Config File (" << pathname << ") Does Not Exist." << std::endl;
    }

        // Otherwise, process
    else
    {
        // Open the file
        std::ifstream fin;
        fin.open(pathname.c_str());

        // Read the first line
        std::string line, trimmed_line;
        std::getline( fin, line);

        // Misc Params
        bool comment_set = false;
        std::string comment_str;


        while( fin.good() )
        {
            // Trim the string
            trimmed_line = String_Trim(line);

            // Skip if Empty
            if( trimmed_line.size() <= 0 )
            {
            }

                // Check if comment
            else if( trimmed_line[0] == '#' )
            {
                // Check if a comment has already been created
                if(comment_set)
                {
                    comment_str = trimmed_line;
                }

                    // Otherwise, set again
                else
                {
                    comment_set = true;
                    comment_str = trimmed_line;
                }
            }

                // Otherwise, check for param
            else
            {
                // Split based on equal operator
                std::vector<std::string> comps = String_Split( trimmed_line,
                                                               "=");

                // Check if enough comps
                if( comps.size() < 2 )
                {
                    std::cerr << "Warning: Line (" << trimmed_line << ") does not have enough components" << std::endl;
                    status = false;
                }
                else
                {
                    // Add the kv pair
                    output.Add_KV_Pair( comps[0], comps[1], comment_str, false);

                    // Clear any comments
                    comment_set = false;
                    comment_str = "";
                }

            }

            // Get next line
            getline( fin, line);

        } // End of while(fin.good)

        // Close the file
        fin.close();
    }

    // return the output
    return output;
}
/**
 * @file    Config_Param.hpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#ifndef CORE_CONFIG_PARAM_HPP
#define CORE_CONFIG_PARAM_HPP


// C++ Libraries
#include <map>
#include <memory>
#include <string>
#include <vector>


/**
 * @class Config_Param
 */
class Config_Param
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Config_Param> ptr_t;

        /**
         * @brief Default Constructor
         */
        Config_Param();


        /**
         * @brief Parameterized Constructor
         */
        Config_Param( const std::string& key_name );


        /**
         * @brief Get the Keyname
         *
         * @return Key name
         */
        inline std::string Get_Key_Name()const{
            return m_key_name;
        }


        /**
         * @brief Get Value
         *
         * @return Value
         */
        std::string Get_Value_Name()const;


        /**
         * @brief Get Sub Config
         *
         * @return Get Sub Config
         */
        std::map<std::string,Config_Param> Get_Sub_Configs()const;


        /**
         * @brief Get KV Pairs
         */
        inline std::map<std::string,std::string> Get_KV_Pairs()const{
            return m_kv_pairs;
        }

        /**
         * @brief Get COmment Pairs
         */
        inline std::map<std::string,std::string> Get_Comment_Pairs()const{
            return m_comment_pairs;
        }


        /**
         * @brief Add Key/Value Pair
         *
         * @param[in] key_name
         * @param[in] value_name
         * @param[in] comment_name
         */
        void Add_KV_Pair( const std::string& key_name,
                          const std::string& value_name,
                          const std::string& comment_name = "");


        /**
         * @brief Parse Key
         *
         * @param[in] key_name
         * @return list of keys split
         */
        static std::vector<std::string>  Parse_Key( const std::string& key_name );


        /**
         * @brief Subtract Key
         *
         * @param[in] subkey
         * @param[in] key_name
         *
         * @return remaining key
         */
        static std::string Pop_Key_Front( const std::string& key_name );


        /**
         * @brief Print to string
         */
        std::string ToString( const int& indent = 4 )const;


    private:

        /// Class Name
        std::string m_class_name;

        /// Key Name
        std::string m_key_name;

        /// Sub-Configs
        std::map<std::string,Config_Param> m_sub_configs;

        // KV Names
        std::map<std::string,std::string> m_kv_pairs;
        std::map<std::string,std::string> m_comment_pairs;

};

#endif
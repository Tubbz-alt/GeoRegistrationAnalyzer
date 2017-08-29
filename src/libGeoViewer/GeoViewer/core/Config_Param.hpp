/**
 * @file    Config_Param.hpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#ifndef CORE_CONFIG_PARAM_HPP
#define CORE_CONFIG_PARAM_HPP


// C++ Libraries
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

// Qt Libraries
#include <QJsonObject>

// Project Libraries
#include "Status.hpp"


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
        Config_Param( const std::string& key_name,
                      const std::string& parent_key = "",
                      const bool&        change_tracking = false );


        /**
         * @brief Get the Keyname
         *
         * @return Key name
         */
        inline std::string Get_Key_Name()const{
            return m_key_name;
        }


        /**
         * @brief Get the Parent Key
         * @return
         */
        std::string Get_Parent_Key()const;

        /**
         * @brief Get Sub Config
         *
         * @return Get Sub Config
         */
        std::map<std::string,Config_Param> Get_Sub_Configs()const;


        /**
         * @brief Get the Configuration List
         */
        std::map<std::string,std::string> Get_Config_List()const;


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
         * @brief Query KV Pair
         *
         * @param[in] key_name
         */
        void Query_KV_Pair( const std::string& key_name,
                            std::string&       value_name,
                            const std::string& default_value = "",
                            const bool&        write_if_not_found = false );


        /**
         * @brief Query KV Pair
         *
         * @param[in] key_name
         */
        std::string Query_KV_Pair( const std::string& key_name,
                                   bool&              value_found )const;


        /**
         * @brief Add Key/Value Pair
         *
         * @param[in] key_name
         * @param[in] value_name
         * @param[in] comment_name
         */
        void Add_KV_Pair( const std::string& key_name,
                          const std::string& value_name,
                          const std::string& comment_name = "",
                          const bool&        override = false);


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


        /**
         * @brief Print to JSON String
         * @return
         */
        std::string ToJsonString()const;


        /**
         * @brief Convert from JSON String
         */
        static Config_Param FromJsonString( const std::string& json_data );


        /**
         * @brief Convert from JSON String
         * @param json_data
         * @param status
         * @return
         */
        static Config_Param FromJsonString( const std::string& json_data,
                                            Status&            status );


        /**
         * @brief Convert to QJsonObject
         */
        QJsonObject ToQJsonObject()const;


        /**
         * @brief Convert from JSON Object
         */
        static Config_Param FromQJsonObject( const QJsonObject& json_data );


        /**
         * @brief Write to Stream
         */
        void Write_Stream( std::ostream& fout )const;


        /**
         * @brief Set the Change Tracking Flag
         *
         */
        void Set_Change_Tracking( const bool& enabled );

        inline bool Is_Change_Tracking()const{
            return m_change_tracking;
        }


        /**
         * @brief Check if we have changed
         */
        bool Has_Changed()const;


        /**
         * @brief Load Key/Value File
         */
        static Config_Param Load_Key_Value_File( const std::string& pathname,
                                                 bool&              status );


        /**
         * @brief Comparison Operator
         */
        bool operator == (const Config_Param& rhs )const;



    private:

        /// Class Name
        std::string m_class_name;

        /// Key Name
        std::string m_key_name;

        /// Parent Key Name
        std::string m_parent_key;

        /// Change Tracking
        bool m_change_tracking;

        /// Change Flag
        bool m_has_changed;

        /// Sub-Configs
        std::map<std::string,Config_Param> m_sub_configs;

        // KV Names
        std::map<std::string,std::string> m_kv_pairs;
        std::map<std::string,std::string> m_comment_pairs;

};

#endif
/**
 * @file    INI_Parser.hpp
 * @author  Marvin Smith
 * @date    4/22/2017
*/
#ifndef IO_INI_PARSER_HPP
#define IO_INI_PARSER_HPP

// C++ Libraries
#include <cinttypes>
#include <string>


namespace PSR{


/**
 * @class INI_Parser
*/
class INI_Parser
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<INI_Parser> ptr_t;


        /**
         * @brief Constructor
        */
        INI_Parser();


        /**
         * @brief Constructor
         *
         * @param[in] pathname  Path to configuration file.
        */
        INI_Parser( const std::string& pathname );


        /**
         * @brief Initialize the Configuration File Parser
        */
        void Initialize( const std::string& pathname );


        /**
         * @brief Check Status
        */
        bool Is_Initialized( std::string& message ) const;


        /**
         * @brief Get list of configuration options.
        */
        


    private:

        /// Class Name
        std::string m_class_name;


}; // End of INI_Parser Class

} // End of PSR Namespace

#endif

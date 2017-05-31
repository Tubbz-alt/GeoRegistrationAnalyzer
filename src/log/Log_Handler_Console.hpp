/**
 * @file    Log_Handler_Console.hpp
 * @author  Marvin Smith
 * @date    4/20/2017
*/
#ifndef LOG_LOG_HANDLER_CONSOLE
#define LOG_LOG_HANDLER_CONSOLE

// C++ Libraries
#include <memory>

// Project Libraries
#include "Log_Handler_Base.hpp"


/**
 * @class Log_Handler_Config_Console
*/
class Log_Handler_Config_Console : public Log_Handler_Config_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Log_Handler_Config_Console> ptr_t;


        /**
         * @brief Constructor
        */
        Log_Handler_Config_Console( const LogSeverity& severity );

    private:

        /// Class Name
        std::string m_class_name;

}; // End of Log_Handler_Config_Console Class


/**
 * @class Log_Handler_Console
*/
class Log_Handler_Console : public Log_Handler_Base
{
    public:

        /**
         * @brief Constructor
        */
        Log_Handler_Console( Log_Handler_Config_Base::ptr_t config );

    private:

        /// Class Name
        std::string m_class_name;

        /// Configuration
        Log_Handler_Config_Console::ptr_t m_config;

}; // End of Log_Handler_Console Class


#endif

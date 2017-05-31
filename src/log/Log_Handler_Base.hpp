/**
 * @file    Log_Handler_Base.hpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#ifndef LOG_HANDLER_BASE
#define LOG_HANDLER_BASE

// C++ Libraries
#include <memory>
#include <string>


// Project Libraries
#include "Log_Severity.hpp"


/**
 * @brief Log Handler Configuration
*/
class Log_Handler_Config_Base
{
    public:

        // Pointer Type
        typedef std::shared_ptr<Log_Handler_Config_Base> ptr_t;

        /**
         * @brief Log Handler
         *
         * @param[in] severity
        */
        Log_Handler_Config_Base( const LogSeverity& severity );


        /**
         * @brief COnvert to String
         */
        virtual std::string To_String( const int& indent = 0 )const;


    protected:

        /// Log Severity
        LogSeverity m_severity;

    private:

        /// Class Name
        std::string m_class_name;

}; // End of Log Handler Config Base Class

/**
 * @class Log_Handler_Base
*/
class Log_Handler_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Log_Handler_Base> ptr_t;


        /**
         * @brief Constructor
        */
        Log_Handler_Base( Log_Handler_Config_Base::ptr_t config );


    private:

        /// Class Name
        std::string m_class_name;

        /// Configuration
        Log_Handler_Config_Base::ptr_t m_config;

}; // End of Log_Handler_Base Class

#endif

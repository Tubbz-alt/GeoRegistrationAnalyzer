/**
 * @file    Log_Handler_Base.hpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#ifndef LOG_HANDLER_BASE
#define LOG_HANDLER_BASE

// C++ Libraries
#include <ctime>
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
         * @brief Get the Severity
         */
        inline LogSeverity  Get_Log_Severity()const{
            return m_severity;
        }


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


        /**
         * @brief Log Message
         */
        virtual void Log( const LogSeverity& severity,
                          const time_t&      timestamp,
                          const std::string& message ) = 0;


        virtual void Log_Class( const LogSeverity& severity,
                                const time_t&      timestamp,
                                const std::string& class_name,
                                const std::string& func_name,
                                const int&         line_no,
                                const std::string& message ) = 0;

    private:

        /// Class Name
        std::string m_class_name;

        /// Configuration
        Log_Handler_Config_Base::ptr_t m_config;

}; // End of Log_Handler_Base Class

#endif

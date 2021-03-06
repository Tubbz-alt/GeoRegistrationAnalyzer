/**
 * @file    Log_Handler_File.hpp
 * @author  Marvin Smith
 * @date    4/20/2017
*/
#ifndef LOG_HANDLER_FILE
#define LOG_HANDLER_FILE

// C++ Libraries
#include <memory>

// Project Libraries
#include "Log_Handler_Base.hpp"


/**
 * @class Log_Handler_Config_File
 */
class Log_Handler_Config_File : public Log_Handler_Config_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Log_Handler_Config_File> ptr_t;

        /**
         * @brief Constructor
         */
        Log_Handler_Config_File( const LogSeverity& severity );

    private:

        /// Class Name
        std::string m_class_name;
};


/**
 * @class Log_Handler_File
*/
class Log_Handler_File : public Log_Handler_Base
{
    public:

        /**
         * @brief Constructor
        */
        Log_Handler_File( Log_Handler_Config_Base::ptr_t config );


        /**
         * @brief Log a message
         *
         * @param severity
         * @param message
         */
        virtual void Log( const LogSeverity& severity,
                          const time_t&      timestamp,
                          const std::string& message );

        /**
         * @brief Log a Class Message
         * @param severity
         * @param timestamp
         * @param class_name
         * @param line_no
         * @param message
         */
        virtual void Log_Class( const LogSeverity& severity,
                                const time_t&      timestamp,
                                const std::string& class_name,
                                const std::string& file_name,
                                const std::string& func_name,
                                const int&         line_no,
                                const std::string& message );


        /**
         * @brief Log a Class Message
         * @param severity
         * @param timestamp
         * @param class_name
         * @param line_no
         * @param message
         */
        virtual void Log_Function( const LogSeverity& severity,
                                   const time_t&      timestamp,
                                   const std::string& file_name,
                                   const std::string& func_name,
                                   const int&         line_no,
                                   const std::string& message );


    private:

        /// Class Name
        std::string m_class_name;

        /// Config
        Log_Handler_Config_File::ptr_t m_config;

}; // End of Log_Handler_File Class


#endif

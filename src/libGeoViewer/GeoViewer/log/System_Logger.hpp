/**
 * @file    System_Logger.hpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#ifndef SYSTEM_LOGGER_HPP
#define SYSTEM_LOGGER_HPP

// C++ Libraries
#include <memory>
#include <mutex>
#include <string>
#include <vector>


// Project Libraries
#include "Log_Handler_Base.hpp"
#include "../core/System_Configuration.hpp"


#define LOG_ERROR(   message ) System_Logger::Log( LogSeverity::ERROR,   message )
#define LOG_WARNING( message ) System_Logger::Log( LogSeverity::WARNING, message )
#define LOG_INFO(    message ) System_Logger::Log( LogSeverity::INFO,    message )
#define LOG_DEBUG(   message ) System_Logger::Log( LogSeverity::DEBUG,   message )
#define LOG_TRACE(   message ) System_Logger::Log( LogSeverity::TRACE,   message )


#define LOG_CLASS_ERROR(   message ) System_Logger::Log_Class( LogSeverity::ERROR,   m_class_name, __FILE__, __func__, __LINE__, message )
#define LOG_CLASS_WARNING( message ) System_Logger::Log_Class( LogSeverity::WARNING, m_class_name, __FILE__, __func__, __LINE__, message )
#define LOG_CLASS_INFO(    message ) System_Logger::Log_Class( LogSeverity::INFO,    m_class_name, __FILE__, __func__, __LINE__, message )
#define LOG_CLASS_DEBUG(   message ) System_Logger::Log_Class( LogSeverity::DEBUG,   m_class_name, __FILE__, __func__, __LINE__, message )
#define LOG_CLASS_TRACE(   message ) System_Logger::Log_Class( LogSeverity::TRACE,   m_class_name, __FILE__, __func__, __LINE__, message )


#define LOG_FUNCTION_ERROR(   message ) System_Logger::Log_Function( LogSeverity::ERROR,   __FILE__, __func__, __LINE__, message )
#define LOG_FUNCTION_WARNING( message ) System_Logger::Log_Function( LogSeverity::WARNING, __FILE__, __func__, __LINE__, message )
#define LOG_FUNCTION_INFO(    message ) System_Logger::Log_Function( LogSeverity::INFO,    __FILE__, __func__, __LINE__, message )
#define LOG_FUNCTION_DEBUG(   message ) System_Logger::Log_Function( LogSeverity::DEBUG,   __FILE__, __func__, __LINE__, message )
#define LOG_FUNCTION_TRACE(   message ) System_Logger::Log_Function( LogSeverity::TRACE,   __FILE__, __func__, __LINE__, message )

/**
 * @brief Log the Entry of a Class
 */
#define LOG_CLASS_ENTRY() System_Logger::Log_Class( LogSeverity::TRACE, m_class_name, __FILE__, __func__, __LINE__, "Start of Method" )
#define LOG_CLASS_EXIT()  System_Logger::Log_Class( LogSeverity::TRACE, m_class_name, __FILE__, __func__, __LINE__, "End of Method" )

/**
 * @brief Log the Entry of a Function
 */
#define LOG_FUNCTION_ENTRY() System_Logger::Log_Function( LogSeverity::TRACE, __FILE__, __func__, __LINE__, "Start of Method" )
#define LOG_FUNCTION_EXIT()  System_Logger::Log_Function( LogSeverity::TRACE, __FILE__, __func__, __LINE__, "End of Method" )


/**
 * @class System_Logger
*/
class System_Logger
{
    public:

        /**
         * @brief Destructor
        */
        virtual ~System_Logger();


        /**
         * @brief Inialize the Logger
        */
        static void Initialize( System_Configuration::ptr_t          sys_config,
                                std::vector<Log_Handler_Base::ptr_t> log_handlers );


        /**
         * @brief Finalize
        */
        static void Finalize();


        /**
         * @brief Check if Initialized
         */
        static bool Is_Initialized();


        /**
         * @brief Log a Message
         */
         static void Log( const LogSeverity& severity,
                          const std::string& message );


        /**
         * @brief Log
         * @param severity
         * @param class_name
         * @param line_no
         * @param message
         */
        static void Log_Class( const LogSeverity&  severity,
                               const std::string&  class_name,
                               const std::string&  file_name,
                               const std::string&  func_name,
                               const int&          line_no,
                               const std::string&  message );


        /**
         * @brief Log
         * @param severity
         * @param class_name
         * @param line_no
         * @param message
         */
        static void Log_Function( const LogSeverity&  severity,
                                  const std::string&  file_name,
                                  const std::string&  func_name,
                                  const int&          line_no,
                                  const std::string&  message );


    private:

        /// Pointer Type
        typedef std::shared_ptr<System_Logger> ptr_t;

        /**
         * @brief Constructor
         */
        System_Logger();


        /**
         * @brief Copy Constructor
         */
        System_Logger( const System_Logger& rhs ) = delete;


        /**
         * @brief Assignment operator
         */
        void operator = ( System_Logger const& rhs ) = delete;


        /**
         * @brief Get the Instance
         */
        static System_Logger::ptr_t&  Get_Instance();


        /// Class Name
        std::string m_class_name;

        /// List of Log Handlers
        std::vector<Log_Handler_Base::ptr_t> m_log_handlers;

        /// Internal Mutex
        std::mutex m_log_lock;

}; // End of System_Logger Class


#endif

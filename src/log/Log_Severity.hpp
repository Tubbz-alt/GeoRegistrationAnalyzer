/**
 * @file    Log_Severity.hpp
 * @author  Marvin Smith
 * @date    5/30/2017
 */
#ifndef LOG_LOG_SEVERITY_HPP
#define LOG_LOG_SEVERITY_HPP

// C++ Libraries
#include <cinttypes>
#include <string>


/**
 * @enum  LogSeverity
 */
enum class LogSeverity : int8_t
{
        UNKNOWN = 0 /**< Error Condition */,
        TRACE   = 1 /**< Lowest Level Log Level*/,
        DEBUG   = 2 /**< Debugging Level*/,
        INFO    = 3 /**< Standard Log Level*/,
        WARNING = 4 /**< Recoverable Error*/,
        ERROR   = 5 /**< Error */,
        FATAL   = 6 /**< Fatal, Crashing Error*/,
};


/**
 * @brief Convert LogSeverity to String
 * @param level
 * @return
 */
std::string LogSeverityToString( const LogSeverity& level );


/**
 * @brief Convert String To LogSeverity
 * @param level
 * @return
 */
LogSeverity StringToLogSeverity( const std::string& level );


#endif
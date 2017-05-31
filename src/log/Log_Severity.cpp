/**
 * @file    Log_Severity.cpp
 * @author  Marvin Smith
 * @date    5/30/2017
 */
#include "Log_Severity.hpp"


/*************************************************/
/*         Convert LogSeverity to String         */
/*************************************************/
std::string LogSeverityToString( const LogSeverity& level )
{
    switch(level)
    {
        case LogSeverity::FATAL:
            return "FATAL";
        case LogSeverity::WARNING:
            return "WARNING";
        case LogSeverity::INFO:
            return "INFO";
        case LogSeverity::DEBUG:
            return "DEBUG";
        case LogSeverity::TRACE:
            return "TRACE";
        default:
            return "UNKNOWN";
    }
    return "UNKNOWN";
}


/*************************************************/
/*         Convert String To LogSeverity         */
/*************************************************/
LogSeverity StringToLogSeverity( const std::string& level )
{
    // TRACE
    if( level == "trace" || level == "TRACE" )
    {
        return LogSeverity::TRACE;
    }

    // DEBUG
    if( level == "debug" || level == "DEBUG" )
    {
        return LogSeverity::DEBUG;
    }

    // INFO
    if( level == "info" || level == "INFO" )
    {
        return LogSeverity::INFO;
    }

    // WARNING
    if( level == "warning" || level == "WARNING" )
    {
        return LogSeverity::WARNING;
    }

    // ERROR
    if( level == "error" || level == "ERROR" )
    {
        return LogSeverity::ERROR;
    }

    // FATAL
    if( level == "fatal" || level == "FATAL" )
    {
        return LogSeverity::FATAL;
    }

    return LogSeverity::UNKNOWN;
}
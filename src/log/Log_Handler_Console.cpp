/**
 * @file    Log_Handler_Console.cpp
 * @author  Marvin Smith
 * @date    5/30/2017
 */
#include "Log_Handler_Console.hpp"


// C++ Libraries
#include <iostream>

// Boost Libraries
#include <boost/filesystem.hpp>

namespace bf = boost::filesystem;


/**********************************/
/*          Constructor           */
/**********************************/
Log_Handler_Config_Console::Log_Handler_Config_Console( const LogSeverity& severity )
  : Log_Handler_Config_Base(severity),
    m_class_name("Log_Handler_Config_Console")
{

}


/**********************************/
/*          Constructor           */
/**********************************/
Log_Handler_Console::Log_Handler_Console( Log_Handler_Config_Base::ptr_t config )
  : Log_Handler_Base(config),
    m_class_name("Log_Handler_Console")
{
    // Cast the config
    m_config = std::dynamic_pointer_cast<Log_Handler_Config_Console>(config);
}

/*****************************/
/*       Log a Message       */
/*****************************/
void Log_Handler_Console::Log( const LogSeverity& severity,
                               const time_t&      timestamp,
                               const std::string& message )
{
    // Lock method
    std::unique_lock<std::mutex> lck(m_mtx);

    // FOrmat the timestamp
    struct tm * timeinfo = localtime(&timestamp);
    char buffer [80];

    strftime (buffer,80,"%Y/%m/%d %H::%M::%S",timeinfo);
    std::string time_str = std::string(buffer);

    // Check severity level
    if( severity >= m_config->Get_Log_Severity() )
    {
        std::cout << "TIME: " << time_str << " LEVEL: " << LogSeverityToString(severity) << "  MSG: " << message << std::endl;
    }
}


/*****************************/
/*       Log a Message       */
/*****************************/
void Log_Handler_Console::Log_Class( const LogSeverity& severity,
                                     const time_t&      timestamp,
                                     const std::string& class_name,
                                     const std::string& file_name,
                                     const std::string& func_name,
                                     const int&         line_no,
                                     const std::string& message )
{
    // Lock method
    std::unique_lock<std::mutex> lck(m_mtx);

    // FOrmat the timestamp
    struct tm * timeinfo = localtime(&timestamp);
    char buffer [80];

    strftime (buffer,80,"%Y/%m/%d %H::%M::%S",timeinfo);
    std::string time_str = std::string(buffer);

    // Format File
    std::string file_tag = bf::basename(bf::path(file_name));

    // Check severity level
    if( severity >= m_config->Get_Log_Severity() )
    {
        std::cout << "TIME: " << time_str << " LEVEL: " << LogSeverityToString(severity);
        std::cout << "  FILE: " << file_tag;
        std::cout << "  CLASS: " << class_name << " FUNC: " << func_name << " LINE: " << line_no << "  MSG: " << message << std::endl;
    }
}

/*****************************/
/*       Log a Message       */
/*****************************/
void Log_Handler_Console::Log_Function( const LogSeverity& severity,
                                        const time_t&      timestamp,
                                        const std::string& file_name,
                                        const std::string& func_name,
                                        const int&         line_no,
                                        const std::string& message )
{
    // Lock method
    std::unique_lock<std::mutex> lck(m_mtx);

    // Format the timestamp
    struct tm * timeinfo = localtime(&timestamp);
    char buffer [80];

    strftime (buffer,80,"%Y/%m/%d %H::%M::%S",timeinfo);
    std::string time_str = std::string(buffer);

    // FOrmat File
    std::string file_tag = bf::basename(bf::path(file_name));

    // Check severity level
    if( severity >= m_config->Get_Log_Severity() )
    {
        std::cout << "TIME: " << time_str << " LEVEL: " << LogSeverityToString(severity);
        std::cout << "  FILE: " << file_tag;
        std::cout << "  FUNC: " << func_name << " LINE: " << line_no << "  MSG: " << message << std::endl;
    }
}
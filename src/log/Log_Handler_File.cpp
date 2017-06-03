/**
 * @file    Log_Handler_File.cpp
 * @author  Marvin Smith
 * @date    4/20/2017
*/
#include "Log_Handler_File.hpp"

// C++ Libraries
#include <iostream>


/*********************************/
/*          Constructor          */
/*********************************/
Log_Handler_Config_File::Log_Handler_Config_File( const LogSeverity& severity )
  : Log_Handler_Config_Base(severity),
    m_class_name("Log_Handler_Config_File")
{

}


/*********************************/
/*          Constructor          */
/*********************************/
Log_Handler_File::Log_Handler_File( Log_Handler_Config_Base::ptr_t config)
 : Log_Handler_Base(config),
   m_class_name("Log_Handler_File")
{
    // Cast the config
    m_config = std::dynamic_pointer_cast<Log_Handler_Config_File>(config);
}


/*****************************/
/*       Log a Message       */
/*****************************/
void Log_Handler_File::Log( const LogSeverity& severity,
                            const time_t&      timestamp,
                            const std::string& message )
{
    // Check severity level

}

/*****************************/
/*       Log a Message       */
/*****************************/
void Log_Handler_File::Log_Class( const LogSeverity& severity,
                                  const time_t&      timestamp,
                                  const std::string& class_name,
                                  const std::string& file_name,
                                  const std::string& func_name,
                                  const int&         line_no,
                                  const std::string& message )
{
    // FOrmat the timestamp
    struct tm * timeinfo = localtime(&timestamp);
    char buffer [80];

    strftime (buffer,80,"%Y/%m/%d %H::%M::%S",timeinfo);
    std::string time_str = std::string(buffer);


}



/*****************************/
/*       Log a Message       */
/*****************************/
void Log_Handler_File::Log_Function( const LogSeverity& severity,
                                     const time_t&      timestamp,
                                     const std::string& file_name,
                                     const std::string& func_name,
                                     const int&         line_no,
                                     const std::string& message )
{
    // FOrmat the timestamp
    struct tm * timeinfo = localtime(&timestamp);
    char buffer [80];

    strftime (buffer,80,"%Y/%m/%d %H::%M::%S",timeinfo);
    std::string time_str = std::string(buffer);


}
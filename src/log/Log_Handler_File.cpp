/**
 * @file    Log_Handler_File.cpp
 * @author  Marvin Smith
 * @date    4/20/2017
*/
#include "Log_Handler_File.hpp"

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

/**
 * @file    Log_Handler_Console.cpp
 * @author  Marvin Smith
 * @date    5/30/2017
 */
#include "Log_Handler_Console.hpp"


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

/**
 * @file    Log_Handler_Qt.cpp
 * @author  Marvin Smith
 * @date    5/30/2017
 */
#include "Log_Handler_Qt.hpp"

/********************************/
/*          Constructor         */
/********************************/
Log_Handler_Config_Qt::Log_Handler_Config_Qt( const LogSeverity& severity )
  : Log_Handler_Config_Base(severity),
    m_class_name("Log_Handler_Config_Qt")
{

}


/********************************/
/*          Constructor         */
/********************************/
Log_Handler_Qt::Log_Handler_Qt(Log_Handler_Config_Base::ptr_t config)
  : Log_Handler_Base(config)
{
    // Cast the config
    m_config = std::dynamic_pointer_cast<Log_Handler_Config_Qt>(config);
}

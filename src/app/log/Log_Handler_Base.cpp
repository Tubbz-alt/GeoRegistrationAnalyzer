/**
 * @file    Log_Handler_Base.cpp
 * @author  Marvin Smith
 * @date    4/20/2017
*/
#include "Log_Handler_Base.hpp"


/**********************************/
/*           Constructor          */
/**********************************/
Log_Handler_Config_Base::Log_Handler_Config_Base()
  : m_class_name("Log_Handler_Config_Base")
{
}


/**********************************/
/*           Constructor          */
/**********************************/
Log_Handler_Config_Base::Log_Handler_Config_Base(  Log_Handler_Config_Base::ptr_t config )
  : m_class_name("Log_Handler_Config_Base"),
    m_config(config)
{
}

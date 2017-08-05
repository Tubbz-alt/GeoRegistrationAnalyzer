/**
 * @file    Log_Handler_Base.cpp
 * @author  Marvin Smith
 * @date    4/20/2017
*/
#include "Log_Handler_Base.hpp"

// C++ Libraries
#include <sstream>


/**********************************/
/*           Constructor          */
/**********************************/
Log_Handler_Config_Base::Log_Handler_Config_Base( const LogSeverity& severity )
  :  m_severity(severity),
     m_class_name("Log_Handler_Config_Base")
{
}


/*************************************/
/*         Convert to String         */
/*************************************/
std::string Log_Handler_Config_Base::To_String(const int &indent) const
{
    // Build indent
    std::string gap( ' ', indent);

    std::stringstream sin;

    sin << gap << m_class_name << std::endl;

    // return output
    return sin.str();
}

/**********************************/
/*           Constructor          */
/**********************************/
Log_Handler_Base::Log_Handler_Base(  Log_Handler_Config_Base::ptr_t config )
  : m_class_name("Log_Handler_Base"),
    m_config(config)
{
}

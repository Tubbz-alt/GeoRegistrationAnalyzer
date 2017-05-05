/**
 * @file    ReferenceImageryPanel.cpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#include "ReferenceImageryPanel.hpp"


/***************************************/
/*             Constructor             */
/***************************************/
ReferenceImageryPanel::ReferenceImageryPanel( System_Configuration::ptr_t system_config,
                                              QWidget*                    parent  )
  : QWidget(parent),
    m_class_name("ReferenceImageryPanel"),
    m_sys_config(system_config)
{

    Initialize_GUI();

}


/****************************************/
/*          Initialize The GUI          */
/****************************************/
void ReferenceImageryPanel::Initialize_GUI()
{
    // Check system configuration for default source data

}

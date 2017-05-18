/**
 * @file    ReferenceToolbar.cpp
 * @author  Marvin Smith
 * @date    5/18/2017
 */
#include "ReferenceToolbar.hpp"

/************************************************/
/*         Reference Toolbar Constructor        */
/************************************************/
ReferenceToolbar::ReferenceToolbar( System_Configuration::ptr_t  sys_config,
                                    QWidget*                     parent )
  : QWidget(parent),
    m_class_name("ReferenceToolbar"),
    m_sys_config(sys_config)
{
    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/*************************************/
/*          Initialize the GUI       */
/*************************************/
void ReferenceToolbar::Initialize_GUI()
{

}


/*********************************************/
/*        Initialize the Configuration       */
/*********************************************/
void ReferenceToolbar::Initialize_Configuration()
{
    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.matching.reference.default.toolbutton.width",
                                   "120",
                                   "#  Default Width of Reference Panel Tool-Button",
                                   false);

    m_sys_config->Add_Config_Param("system.matching.reference.default.toolbutton.height",
                                   "120",
                                   "#  Default Height of Reference Panel Tool-Button",
                                   false);

}

/**
 * @file    ProjectBasePanel.cpp
 * @author  Marvin Smith
 * @date    5/21/2017
 */
#include "ProjectBasePanel.hpp"


/**********************************/
/*          Constructor           */
/**********************************/
ProjectBasePanel::ProjectBasePanel( System_Configuration::ptr_t sys_config,
                                    QWidget*                    parent)
  : QWidget(parent),
    m_sys_config(sys_config),
    m_class_name("ProjectBasePanel")
{

}


/******************************************/
/*           Import New Project           */
/******************************************/
void ProjectBasePanel::Import_Project( const Config_Param& project_info )
{
    std::cout << "Warning: Not implemented for base class" << std::endl;

}

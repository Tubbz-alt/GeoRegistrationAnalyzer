/**
 * @file     ProjectViewerPanelBase.cpp
 * @author   Marvin Smith
 * @date     5/20/2017
 */
#include "ProjectViewerPanelBase.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
ProjectViewerPanelBase::ProjectViewerPanelBase( const Config_Param&          project_info,
                                                System_Configuration::ptr_t  sys_config,
                                                QWidget*                     parent)
  : QWidget(parent),
    m_project_info(project_info),
    m_sys_config(sys_config),
    m_class_name("ProjectViewerPanelBase")
{

}

/**
 * @file    NewProjectPanelBase.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "NewProjectPanelBase.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
NewProjectPanelBase::NewProjectPanelBase( System_Configuration::ptr_t sys_config,
                                          QWidget *parent)
 : QWidget(parent),
   m_sys_config(sys_config),
   m_class_name("NewProjectPanelBase")
{
}

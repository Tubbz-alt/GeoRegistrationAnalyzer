/**
 * @file    NewProjectPanelMatching.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "NewProjectPanelMatching.hpp"


/**********************************/
/*          Constructor           */
/**********************************/
NewProjectPanelMatching::NewProjectPanelMatching( System_Configuration::ptr_t sys_config,
                                                  QWidget*                    parent )
 : NewProjectPanelBase(sys_config,
                       parent),
   m_class_name("NewProjectPanelMatching")
{

}

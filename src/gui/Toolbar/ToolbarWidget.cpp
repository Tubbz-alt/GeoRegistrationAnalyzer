/**
 * @brief ToolbarWidget.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "ToolbarWidget.hpp"

/**********************************/
/*          Constructor           */
/**********************************/
ToolbarWidget::ToolbarWidget(System_Configuration::ptr_t sys_config,
                             QWidget *parent)
  : QWidget(parent),
    m_class_name("ToolbarWidget"),
    m_sys_config(sys_config)
{

}


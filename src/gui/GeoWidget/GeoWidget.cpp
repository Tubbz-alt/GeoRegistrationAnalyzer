/**
 * @class GeoWidget.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include "GeoWidget.hpp"

/*********************************/
/*          Constructor          */
/*********************************/
GeoWidget::GeoWidget( System_Configuration::ptr_t sys_config,
                      QWidget *parent)
 : QWidget(parent),
   m_sys_config(sys_config),
   m_class_name("GeoWidget")
{

}

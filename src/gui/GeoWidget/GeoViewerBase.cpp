/**
 * @file GeoViewerBase.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "GeoViewerBase.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
GeoViewerBase::GeoViewerBase( System_Configuration::ptr_t sys_config,
                              QWidget *parent)
  : QWidget(parent),
    m_sys_config(sys_config),
    m_class_name("GeoViewerBase")
{

}


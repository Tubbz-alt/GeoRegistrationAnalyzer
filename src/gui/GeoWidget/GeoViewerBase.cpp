/**
 * @file GeoViewerBase.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "GeoViewerBase.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
GeoViewerBase::GeoViewerBase( const std::string&          base_config_profile,
                              System_Configuration::ptr_t sys_config,
                              QWidget *parent)
  : QWidget(parent),
    m_base_config_profile(base_config_profile),
    m_sys_config(sys_config),
    m_class_name("GeoViewerBase")
{

}


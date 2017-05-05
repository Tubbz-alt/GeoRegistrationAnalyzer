/**
 * @file GeoViewerGoogle.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "GeoViewerGoogle.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
GeoViewerGoogle::GeoViewerGoogle( System_Configuration::ptr_t sys_config,
                                  QWidget *parent)
        : GeoViewerBase( sys_config,
                         parent),
          m_class_name("GeoViewerGoogle")
{

}

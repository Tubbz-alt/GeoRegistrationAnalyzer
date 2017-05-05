/**
 * @file GeoViewerGDAL.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "GeoViewerGDAL.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
GeoViewerGDAL::GeoViewerGDAL( System_Configuration::ptr_t sys_config,
                                  QWidget *parent)
        : GeoViewerBase( sys_config,
                         parent),
          m_class_name("GeoViewerGDAL")
{

}

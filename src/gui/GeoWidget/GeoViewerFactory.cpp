/**
 * @file    GeoViewerFactory.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include "GeoViewerFactory.hpp"

// Project Libraries
#include "GeoViewerGoogle.hpp"


/*******************************/
/*          Initialize         */
/*******************************/
GeoViewerBase*  GeoViewerFactory::Create( System_Configuration::ptr_t sys_config,
                                          const std::string&          window_name )
{
    // Build the viewer
    GeoViewerBase*  widget;

    if( window_name == "google" ) {
        widget = new GeoViewerGoogle(sys_config);
    }

    // return the result
    return widget;
}

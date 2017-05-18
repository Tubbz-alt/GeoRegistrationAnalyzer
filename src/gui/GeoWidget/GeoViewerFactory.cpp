/**
 * @file    GeoViewerFactory.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include "GeoViewerFactory.hpp"

// Project Libraries
#include "GeoViewerGoogle.hpp"
#include "GeoViewerLocal.hpp"


/*******************************/
/*          Initialize         */
/*******************************/
GeoViewerBase*  GeoViewerFactory::Create( const std::string&          base_config_profile,
                                          System_Configuration::ptr_t sys_config,
                                          const std::string&          window_name )
{
    // Build the viewer
    GeoViewerBase*  widget;

    // Construct the Google Widget
    if( window_name == "google" ) {
        widget = new GeoViewerGoogle(base_config_profile,
                                     sys_config);
    }

    // Construct the Local Viewer
    else if( window_name == "local" )
    {
        widget = new GeoViewerLocal(base_config_profile,
                                    sys_config);
    }

    // return the result
    return widget;
}

/**
 * @file    Init_Utilities.hpp
 * @author  Marvin Smith
 * @date    8/4/2017
 */
#ifndef GEO_VIEWER_INIT_UTILITIES_HPP
#define GEO_VIEWER_INIT_UTILITIES_HPP

// Project Libraries
#include <GeoViewer/core/System_Configuration.hpp>
#include <GeoViewer/log/System_Logger.hpp>

/**
 * @brief Initialize Logging
 *
 * @param[in] sys_config  System configuration settings
 */
void Initialize_Logging( const System_Configuration::ptr_t sys_config );

#endif

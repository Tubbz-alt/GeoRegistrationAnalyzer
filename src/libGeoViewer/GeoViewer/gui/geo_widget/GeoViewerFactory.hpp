/**
 * @file    GeoViewerFactory.hpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#ifndef GUI_GEOWIDGET_GEOVIEWER_FACTORY_HPP
#define GUI_GEOWIDGET_GEOVIEWER_FACTORY_HPP

// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "GeoViewerBase.hpp"


/**
 * @class GeoViewerFactory
 */
class GeoViewerFactory
{
    public:

        /**
         * @brief Create Geoviewer Widget
         *
         * @param[in] base_config_profile
         * @param[in] sys_config
         * @param[in] window_name
         *
         * @return GeoViewer widget object.
         */
        static GeoViewerBase*  Create( const std::string&          base_config_profile,
                                       System_Configuration::ptr_t sys_config,
                                       const std::string&          window_name );
};


#endif
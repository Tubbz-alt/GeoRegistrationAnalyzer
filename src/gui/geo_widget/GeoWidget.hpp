/**
 * @file    GeoWidget.hpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#ifndef GUI_GEOWIDGET_GEOWIDGET_HPP
#define GUI_GEOWIDGET_GEOWIDGET_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/assets/Asset_Image_Base.hpp"
#include "../../core/System_Configuration.hpp"
#include "GeoViewerBase.hpp"
#include "GeoViewerFactory.hpp"


/**
 * @class QWidget
 */
class GeoWidget : public QWidget
{
    public:

        /**
         * @brief Constructor for base viewer class
         *
         * @param sys_config
         * @param parent
         */
        GeoWidget( const std::string&          base_config_profile,
                   System_Configuration::ptr_t sys_config,
                   QWidget*                    parent = nullptr );


        /**
         * @brief Update the widget asset
         */
         void Update_Asset( const std::string&      asset_type,
                            Asset_Image_Base::ptr_t new_asset );

    protected:

        /**
         * @brief Initialize GUI
         */
        void Initialize_GUI();


        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

    private:

        /**
         * @brief Update Configuration
         */
        void Update_Configuration();


        /// Class Name
        std::string m_class_name;

        /// Base Config Profile
        std::string m_base_config_profile;

        /// GeoWidget Viewer
        std::map<std::string,GeoViewerBase*> m_geo_viewers;

}; // End of GeoWidget Class

#endif
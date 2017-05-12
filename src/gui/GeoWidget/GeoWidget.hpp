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
#include "../../core/System_Configuration.hpp"
#include "GeoViewerBase.hpp"


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
        GeoWidget( System_Configuration::ptr_t sys_config,
                   QWidget*                    parent = nullptr );


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

        /// GeoWidget Viewer
        GeoViewerBase* m_geo_viewer;

}; // End of GeoWidget Class

#endif
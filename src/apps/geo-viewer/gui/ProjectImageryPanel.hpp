/**
 * @file    ProjectImageryPanel.hpp
 * @author  Marvin Smith
 * @date    8/6/2017
*/
#ifndef GEO_VIEWER_GUI_PROJECT_IMAGERY_PANEL_HPP
#define GEO_VIEWER_GUI_PROJECT_IMAGERY_PANEL_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "ProjectImageryToolbar.hpp"

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>
#include <GeoViewer/gui/geo_widget/GeoWidget.hpp>

/**
 * @class ProjectImageryPanel
*/
class ProjectImageryPanel : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
        */
        ProjectImageryPanel( System_Configuration::ptr_t system_config,
                             QWidget*                    parent = nullptr );

    protected:

        /**
         * @brief Initialize the GUI
        */
        void Initialize_GUI();

    private:

        /**
         * @brief Initialize the Configuration
         */
        void Initialize_Configuration();


        /// Class Name
        std::string m_class_name;

        ///  System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// GeoViewer
        GeoWidget* m_geo_widget;

        /// Toolbar
        ProjectImageryToolbar* m_toolbar;

}; // End of ReferenceImageryPanel Class

#endif

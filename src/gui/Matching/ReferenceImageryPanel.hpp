/**
 * @file    ReferenceImageryPanel.hpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#ifndef REFERENCE_IMAGERY_PANEL_HPP
#define REFERENCE_IMAGERY_PANEL_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "ReferenceToolbar.hpp"
#include "../../core/System_Configuration.hpp"
#include "../geo_widget/GeoWidget.hpp"


/**
 * @class ReferenceImageryPanel
*/
class ReferenceImageryPanel : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
        */
        ReferenceImageryPanel( System_Configuration::ptr_t system_config,
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
        ReferenceToolbar* m_toolbar;

}; // End of ReferenceImageryPanel Class

#endif

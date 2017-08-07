/**
 * @file    ProjectToolbarWidget.hpp
 * @author  Marvin Smith
 * @date    8/6/2017
 */
#ifndef GEO_WIDGET_GUI_PROJECT_TOOLBAR_WIDGET_HPP
#define GEO_WIDGET_GUI_PROJECT_TOOLBAR_WIDGET_HPP

// C++ Libraries
#include <string>

// Qt Libraries
#include <QGridLayout>
#include <QStackedWidget>
#include <QWidget>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>

// Project Libraries
#include "PrimaryToolbarPane.hpp"


/**
 * @class ProjectToolbarWidget
 * @brief Main Class for Primary Toolbar
 */
class ProjectToolbarWidget : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        ProjectToolbarWidget( System_Configuration::ptr_t sys_config,
                              QWidget*                     parent = nullptr );


    public slots:

        /**
         * @brief Return to Primary Panel
         */
        void Change_Panel( int panel_id );

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

        /**
         * @brief Build the Primary Panel
         */
        void Build_Primary_Panels();


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Layout
        QVBoxLayout* m_main_layout;

        /// Stacked Widget
        QStackedWidget* m_main_widget;

        /// Primary Toolbar Panel
        PrimaryToolbarPane* m_primary_panel;




}; // End of MatchingToolbarWidget Class

#endif
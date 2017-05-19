/**
 * @file    MatchingToolbarWidget.hpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#ifndef TOOLBAR_MATCHING_TOOLBAR_WIDGET_HPP
#define TOOLBAR_MATCHING_TOOLBAR_WIDGET_HPP

// C++ Libraries
#include <string>

// Qt Libraries
#include <QGridLayout>
#include <QStackedWidget>
#include <QWidget>

// Project Libraries
#include "../../../core/System_Configuration.hpp"
#include "PrimaryMatchingToolbarPane.hpp"
#include "ProjectMatchingToolbarPane.hpp"


/**
 * @class ToolbarWidget
 * @brief Main Class for Primary Toolbar
 */
class MatchingToolbarWidget : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        MatchingToolbarWidget( System_Configuration::ptr_t sys_config,
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
        PrimaryMatchingToolbarPane* m_primary_panel;

        /// Project Panel
        ProjectMatchingToolbarPane* m_project_panel;



}; // End of MatchingToolbarWidget Class

#endif
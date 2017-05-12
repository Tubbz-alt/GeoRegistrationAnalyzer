/**
 * @file    MatchingBasePanel.hpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#ifndef MATCHING_BASE_PANEL_HPP
#define MATCHING_BASE_PANEL_HPP

// Qt Libraries
#include <QSplitter>
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "ReferenceImageryPanel.hpp"
#include "TestImageryPanel.hpp"
#include "../Toolbar/ToolbarWidget.hpp"


/**
 * @class MatchingBasePanel
*/
class MatchingBasePanel : public QWidget
{
    public:

        /**
         * @brief Constructor
        */
        MatchingBasePanel( System_Configuration::ptr_t sys_config,
                           QWidget*                    parent = nullptr );


    protected:

        /**
         * @brief Initialize the GUI
        */
        void Initialize_GUI();

    private:

        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t  m_sys_config;

        /// Main Widgets
        QSplitter* m_main_splitter;

        /// Toolbar Widget
        ToolbarWidget* m_toolbar_widget;

}; // End of MatchingBasePanel Class

#endif

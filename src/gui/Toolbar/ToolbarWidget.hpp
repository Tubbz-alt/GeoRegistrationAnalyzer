/**
 * @file    ToolbarWidget.hpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#ifndef TOOLBAR_TOOLBAR_WIDGET_HPP
#define TOOLBAR_TOOLBAR_WIDGET_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"


/**
 * @class ToolbarWidget
 * @brief Main Class for Primary Toolbar
 */
class ToolbarWidget : public QWidget
{
    public:

        /**
         * @brief Constructor
         */
        ToolbarWidget( System_Configuration::ptr_t sys_config,
                       QWidget*                     parent = nullptr );



    private:

        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

};

#endif
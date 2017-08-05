/**
 * @file    NewProjectPanelBase.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef GUI_NEW_PROJECT_PANEL_BASE_HPP
#define GUI_NEW_PROJECT_PANEL_BASE_HPP

// C++ Libraries
#include <string>

// Qt Libraries
#include <QWidget>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>


/**
 * @class NewProjectPanelBase
 */
class NewProjectPanelBase : public QWidget
{
    public:

        /**
         * @brief Constructor
         */
        NewProjectPanelBase( System_Configuration::ptr_t  sys_config,
                             QWidget*                     parent = nullptr );

    protected:

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

    private:

        /// Class Name
        std::string m_class_name;

}; // End of NewProjectPanelBase

#endif
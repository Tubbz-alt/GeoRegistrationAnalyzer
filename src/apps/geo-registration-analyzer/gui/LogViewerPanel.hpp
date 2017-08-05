/**
 * @file    LogViewerPanel.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef GUI_LOG_VIEWER_PANEL_HPP
#define GUI_LOG_VIEWER_PANEL_HPP


// C++ Libraries
#include <string>

// Qt Libraries
#include <QWidget>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>


class LogViewerPanel : public QWidget
{
    public:

        /**
         * @brief Constructor
         */
        LogViewerPanel( System_Configuration::ptr_t sys_config,
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

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

};

#endif
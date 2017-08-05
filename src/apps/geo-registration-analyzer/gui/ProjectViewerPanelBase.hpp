/**
 * @file    ProjectViewerPanelBase.hpp
 * @author  Marvin Smith
 * @date    5/20/2017
 */
#ifndef GUI_PROJECT_VIEWER_PANEL_BASE_HPP
#define GUI_PROJECT_VIEWER_PANEL_BASE_HPP

// Qt Libraries
#include <QWidget>

// C++ Libraries
#include <string>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>


/**
 *  @class ProjectViewerPanelBase
 */
class ProjectViewerPanelBase : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        ProjectViewerPanelBase( const Config_Param&          project_info,
                                System_Configuration::ptr_t  sys_config,
                                QWidget*                     parent = nullptr );


    protected:

        /// Project Info
        Config_Param m_project_info;


        /// System Configuration
        System_Configuration::ptr_t m_sys_config;


    private:

        /// Class Name
        std::string m_class_name;
};


#endif
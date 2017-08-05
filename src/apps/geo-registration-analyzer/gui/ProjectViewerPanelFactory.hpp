/**
 * @file    ProjectViewerPanelFactory.hpp
 * @author  Marvin Smith
 * @date    5/20/2017
 */
#ifndef GUI_PROJECT_VIEWER_PANEL_FACTORY_HPP
#define GUI_PROJECT_VIEWER_PANEL_FACTORY_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "ProjectViewerPanelBase.hpp"

/**
 * @class ProjectViewerPanelFactory
 */
class ProjectViewerPanelFactory
{
    public:

        /**
         * @brief Generate ProjectViewerPanel Object
         */
        static ProjectViewerPanelBase*   Create( const Config_Param&          project_info,
                                                 System_Configuration::ptr_t  sys_config,
                                                 QWidget*                     parent = nullptr );

};

#endif
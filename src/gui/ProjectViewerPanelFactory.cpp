/**
 * @file    ProjectViewerPanelFactory.cpp
 * @author  Marvin Smith
 * @date    5/20/2017
 */
#include "ProjectViewerPanelFactory.hpp"

// Implemented Panels
#include "Matching/ProjectViewerPanelMatching.hpp"


/*****************************************/
/*             Create Factory            */
/*****************************************/
ProjectViewerPanelBase* ProjectViewerPanelFactory::Create(const Config_Param&           project_info,
                                                          System_Configuration::ptr_t   sys_config,
                                                          QWidget*                      parent)
{
    // Build output
    ProjectViewerPanelBase* widget = nullptr;

    // Query the project type
    bool value_found;

    std::string project_type = project_info.Query_KV_Pair("project.type", value_found );

    if( value_found )
    {
        // Check if Matching
        if( project_type == "matching" )
        {
            widget = new ProjectViewerPanelMatching(project_info,
                                                    sys_config,
                                                    parent );
        }

        else
        {
            std::cerr << "Unknown Project Type: " << project_type << std::endl;
        }

    }

    // Otherwise, error
    else
    {
        std::cerr << "No Project Type Found" << std::endl;
    }

    // Return panel
    return widget;
}

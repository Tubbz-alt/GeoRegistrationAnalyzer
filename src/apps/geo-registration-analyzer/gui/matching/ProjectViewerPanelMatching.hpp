/**
 * @file    ProjectViewerPanelMatching.hpp
 * @author  Marvin Smith
 * @date    5/20/2017
 */
#ifndef GUI_MATCHING_PROJECT_VIEWER_PANEL_MATCHING_HPP
#define GUI_MATCHING_PROJECT_VIEWER_PANEL_MATCHING_HPP

// C++ Libraries
#include <string>


// Qt Libraries
#include <QVBoxLayout>
#include <QWidget>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>

// Project Libraries
#include "../ProjectViewerPanelBase.hpp"


/**
 * @class ProjectViewerPanelMatching
 */
class ProjectViewerPanelMatching : public ProjectViewerPanelBase
{
    Q_OBJECT

    public:

        /**
         * @brief Matching Viewer Project Panel
         *
         * @param project_info
         * @param sys_config
         * @param parent
         */
        ProjectViewerPanelMatching( const Config_Param&          project_info,
                                    System_Configuration::ptr_t  sys_config,
                                    QWidget*                     parent = nullptr );


    protected:

        /**
         *  @brief Initialize the GUI
         */
        void Initialize_GUI();


    private:


        /**
         * @brief Initialize Configuration
         */
        void Initialize_Configuration();


        /**
         * @brief Build the label
         */
        void Build_Title_Widget();


        /// Class Name
        std::string m_class_name;

        /// Main Layout
        QVBoxLayout* m_main_layout;
};

#endif
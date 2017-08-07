/**
 * @file    ProjectViewerPanelMatching.hpp
 * @author  Marvin Smith
 * @date    5/20/2017
 */
#ifndef GEO_VIEWER_GUI_MATCHING_PROJECT_VIEWER_HPP
#define GEO_VIEWER_GUI_MATCHING_PROJECT_VIEWER_HPP

// C++ Libraries
#include <string>


// Qt Libraries
#include <QVBoxLayout>
#include <QWidget>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>



/**
 * @class ProjectViewerPanelMatching
 */
class ProjectViewer : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Project Viewer Panel
         *
         * @param project_info
         * @param sys_config
         * @param parent
         */
        ProjectViewer( const Config_Param&          project_info,
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

        /// Project Info
        Config_Param m_project_info;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Layout
        QVBoxLayout* m_main_layout;
};

#endif
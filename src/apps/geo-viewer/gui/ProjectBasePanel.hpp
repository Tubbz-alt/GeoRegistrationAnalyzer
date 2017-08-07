/**
 * @file    ProjectBasePanel.hpp
 * @author  Marvin Smith
 * @date    8/6/2017
*/
#ifndef GEO_VIEWER_PROJECT_BASE_PANEL_HPP
#define GEO_VIEWER_PROJECT_BASE_PANEL_HPP

// Qt Libraries
#include <QSplitter>
#include <QTableWidget>
#include <QWidget>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>

// Project Libraries
#include "toolbar/ProjectToolbarWidget.hpp"
#include "workers/Project_Worker.hpp"

/**
 * @class ProjectBasePanel
*/
class ProjectBasePanel : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
        */
        ProjectBasePanel( System_Configuration::ptr_t sys_config,
                           QWidget*                    parent = nullptr );


        /**
         * @brief Destructor
         */
        virtual ~ProjectBasePanel();


        /**
        * @brief Import a new project
        *
        * @param project_info
        */
        virtual void Import_Project( const Config_Param& project_info );


    protected:

        /**
         * @brief Initialize the GUI
        */
        void Initialize_GUI();

    private:

        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Widgets
        QSplitter* m_main_splitter;

        /// Toolbar Widget
        ProjectToolbarWidget* m_toolbar_widget;

        /// Import Project ImportProjectJob
        Project_Worker m_worker;


}; // End of ProjectBasePanel Class

#endif

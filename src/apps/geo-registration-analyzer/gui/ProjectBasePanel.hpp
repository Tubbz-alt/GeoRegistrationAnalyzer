/**
 * @file    ProjectBasePanel.hpp
 * @author  Marvin Smith
 * @date    5/21/2017
 */
#ifndef GUI_PROJECT_BASE_PANEL_HPP
#define GUI_PROJECT_BASE_PANEL_HPP


// Qt Gui
#include <QWidget>


// Project Libraries
#include "../core/Config_Param.hpp"
#include "../core/System_Configuration.hpp"


/**
 * @class ProjectBasePanel
 */
class ProjectBasePanel : public QWidget
{
    Q_OBJECT

    public:

        /**
         * Constructor
         *
         * @param sys_config
         * @param parent
         */
        ProjectBasePanel( System_Configuration::ptr_t sys_config,
                          QWidget*                    parent );


        /**
         * @brief Import a new project
         *
         * @param project_info
         */
        virtual void Import_Project( const Config_Param& project_info );

    protected:

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

    private:

        /// Class Name
        std::string m_class_name;
};


#endif
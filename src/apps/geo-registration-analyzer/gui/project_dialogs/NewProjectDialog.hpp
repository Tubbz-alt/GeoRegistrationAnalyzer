/**
 * @file    NewProjectDialog.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef GUI_NEW_PROJECT_DIALOG_HPP
#define GUI_NEW_PROJECT_DIALOG_HPP

// C++ Libraries
#include <map>
#include <string>


// Qt Libraries
#include <QDialog>
#include <QStackedWidget>
#include <QVBoxLayout>

// GeoViewer Libraries
#include <GeoViewer/core/Config_Param.hpp>
#include <GeoViewer/core/System_Configuration.hpp>

// Project Libraries
#include "gui/ProjectViewerPanelFactory.hpp"


/**
 * @class NewProjectDialog
 */
class NewProjectDialog : public QDialog
{
    Q_OBJECT


    public:

        /**
         * @brief Build New Project
         *
         * @param sys_config
         * @param parent
         */
        NewProjectDialog( System_Configuration::ptr_t  sys_config,
                          QWidget*                     parent = nullptr );


        /**
         * @brief Check if Project Was Imported
         */
        inline bool Project_Loaded()const{
            return m_project_loaded;
        }

        /**
         * @brief Get the Project Info
         */
        inline Config_Param Get_Project_Info()const
        {
            return m_project_info;
        }


    public slots:


        /**
         * @brief Reset the Dialog
         */
        virtual void Reset();


        /**
         * @brief Close the Dialog
         */
        virtual void Close();

    protected slots:

        /**
         * @brief Create a Matching Project
         */
        void Create_Matching_Project();

    protected:

        /**
         *  @brief Initialize the GUI
         */
        void Initialize_GUI();


    private:

        /**
         * @brief Initialize the Configuration
         */
        void Initialize_Configuration();


        /**
         * @brief Build the Selector Panel
         */
        void Build_Selector_Panel();


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Layout
        QVBoxLayout* m_main_layout;


        /// Stacked Widget
        QStackedWidget* m_stack_widget;

        /// Project Info
        Config_Param m_project_info;

        /// Loaded Project
        bool m_project_loaded;

};


#endif
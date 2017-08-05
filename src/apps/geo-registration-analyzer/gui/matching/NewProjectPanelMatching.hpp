/**
 * @file    NewProjectPanelMatching.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef GUI_MATCHING_NEW_PROJECT_PANEL_MATCHING_HPP
#define GUI_MATCHING_NEW_PROJECT_PANEL_MATCHING_HPP

// C++ Libraries
#include <string>

// Qt Libraries
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>

// Project Libraries
#include "gui/project_dialogs/NewProjectPanelBase.hpp"


/**
 * @class NewProjectPanelMatching
 */
class NewProjectPanelMatching : public NewProjectPanelBase
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        NewProjectPanelMatching( System_Configuration::ptr_t sys_config,
                                 QWidget*                    parent = nullptr );


    signals:

        void Close_Dialog();

    protected slots:

        /**
         * @brief Save the current project
         */
        void Save_Project();

        /**
         * @brief Cancel the current project
         */
        void Cancel_Project();


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


        /**
         * @brief Build the Editor Widgets
         */
        void Build_Editor();


        /**
         * @brief Build the Project Name Widget
         */
        void Build_Project_Name_Widget();


        /**
         * @brief Build the Project ID Widget
         */
        void Build_Project_ID_Widget();


        /**
         * @brief Build the Toolbar
         */
        void Build_Toolbar();


        /// Class Name
        std::string m_class_name;

        /// Main Layout
        QVBoxLayout* m_main_layout;

        /// Editor Layout
        QVBoxLayout* m_editor_layout;

        /// Project Name Edit
        QLineEdit* m_project_name_edit;

        /// Project ID Edit
        QLineEdit* m_project_id_edit;

}; // End of NewProjectPanelMatching Class

#endif
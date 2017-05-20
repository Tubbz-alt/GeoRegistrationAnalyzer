/**
 * @file    ImportProjectDialog.hpp
 * @author  Marvin Smith
 * @date    5/20/2017
 */
#ifndef GUI_IMPORT_PROJECT_DIALOG_HPP
#define GUI_IMPORT_PROJECT_DIALOG_HPP

// Qt Libraries
#include <QDialog>
#include <QStackedWidget>
#include <QVBoxLayout>


// Project Libraries
#include "../core/System_Configuration.hpp"


/**
 * @class ImportProjectDialog
 */
class ImportProjectDialog : public QDialog
{
    Q_OBJECT

    public:

        /**
         * @brief Import Project
         *
         * @param sys_config
         * @param parent
         */
        ImportProjectDialog( System_Configuration::ptr_t  sys_config,
                             QWidget*                     parent = nullptr );


    protected slots:

        /**
         * @brief Import Project File
         */
        void Import_Project_File();


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
         * @brief BUild the File Chooser Widget
         */
        void Build_File_Chooser();


        /**
         * @brief Build the Project Viewer
         */
        void Build_Project_Viewer();


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Layout
        QVBoxLayout* m_main_layout;

        /// Stacked Widget
        QStackedWidget* m_stack_widget;
};


#endif
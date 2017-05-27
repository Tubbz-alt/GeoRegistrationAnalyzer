/**
 * @file    NewProjectDialog.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "NewProjectDialog.hpp"

// Qt Libraries
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <QToolButton>




/************************************/
/*            Constructor           */
/************************************/
NewProjectDialog::NewProjectDialog( System_Configuration::ptr_t sys_config,
                                    QWidget*                    parent)
 : QDialog(parent),
   m_class_name("ImportProjectDialog"),
   m_sys_config(sys_config),
   m_project_loaded(false)
{
    // Initialize Configuration
    Initialize_Configuration();

    // Initialize GUI
    Initialize_GUI();
}


/*******************************/
/*      Initialize the GUI     */
/*******************************/
void NewProjectDialog::Initialize_GUI()
{
    // Query Relevant Parameters
    bool value_found;

    std::string window_title = m_sys_config->Query_Config_Param("system.gui.new_project.title", value_found );

    // Create the main layout
    m_main_layout = new QVBoxLayout();

    m_stack_widget = new QStackedWidget();

    m_main_layout->addWidget(m_stack_widget);

    // Set the layout
    setLayout(m_main_layout);

    setWindowTitle(window_title.c_str());
}


/*************************************/
/*      Initialize Configuration     */
/*************************************/
void NewProjectDialog::Initialize_Configuration()
{
    // Title of Pref Dialog
    m_sys_config->Add_Config_Param("system.gui.new_project.title",
                                   "Build New Project",
                                   "#  Title of Dialog",
                                   false );

    // Button Sizes
    m_sys_config->Add_Config_Param("system.gui.new_project.button_width",
                                   "70",
                                   "#  Width of New Project Button",
                                   false );

    m_sys_config->Add_Config_Param("system.gui.new_project.button_height",
                                   "40",
                                   "#  Height of New Project Button",
                                   false );
}

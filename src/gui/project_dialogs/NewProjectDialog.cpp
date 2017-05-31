/**
 * @file    NewProjectDialog.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "NewProjectDialog.hpp"

// Qt Libraries
#include <QGridLayout>
#include <QLabel>
#include <QToolButton>

// Project Libraries
#include "../matching/NewProjectPanelMatching.hpp"


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
/*      Reset the Dialog       */
/*******************************/
void NewProjectDialog::Reset()
{

}


/*******************************/
/*      Close the Dialog       */
/*******************************/
void NewProjectDialog::Close()
{
    // close the dialog
    close();
}


/***************************************/
/*      Create a Matching Project      */
/***************************************/
void NewProjectDialog::Create_Matching_Project()
{
    // Set the index
    m_stack_widget->setCurrentIndex(1);
}


/*******************************/
/*      Initialize the GUI     */
/*******************************/
void NewProjectDialog::Initialize_GUI()
{
    // Query Relevant Parameters
    bool value_found;
    std::string window_title = m_sys_config->Query_Config_Param("system.gui.new_project.title",
                                                                value_found );

    // Create the main layout
    m_main_layout = new QVBoxLayout();

    // Create the stack widget
    m_stack_widget = new QStackedWidget();

    // Create project selection panel
    Build_Selector_Panel();


    // Create the Matching Panel
    NewProjectPanelMatching* matching_panel = new NewProjectPanelMatching(m_sys_config,
                                                                          this);
    connect(matching_panel, SIGNAL(Close_Dialog()), this, SLOT(Close()));
    m_stack_widget->addWidget(matching_panel);


    // Set the layout
    m_main_layout->addWidget(m_stack_widget);

    // Set the layout
    setLayout(m_main_layout);

    // Set the window title
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

/*************************************/
/*      Build the Selector Panel     */
/*************************************/
void NewProjectDialog::Build_Selector_Panel()
{
    bool value_found;
    int button_width  = m_sys_config->Query_Config_Param_Int32("system.gui.new_project.button_width",
                                                               value_found);
    int button_height = m_sys_config->Query_Config_Param_Int32("system.gui.new_project.button_height",
                                                               value_found);

    // Create the widget
    QWidget* selector_widget = new QWidget(this);

    // Create the layout
    QGridLayout* selector_layout = new QGridLayout();
    selector_layout->setContentsMargins(1,1,1,1);

    // Add the matching panel information
    QToolButton* matching_button = new QToolButton(selector_widget);
    matching_button->setText("Matching");
    matching_button->setFixedSize(button_width, button_height);
    connect(matching_button, SIGNAL(clicked()), this, SLOT(Create_Matching_Project()));
    selector_layout->addWidget(matching_button, 0, 0, 1, 1 );

    // Add the label information
    QLabel* matching_label = new QLabel("Point-Matching Interface.");
    selector_layout->addWidget(matching_label, 0, 1, 1, 1);


    // Add the cancel button
    QToolButton* cancel_button = new QToolButton(selector_widget);
    cancel_button->setText("Cancel");
    cancel_button->setFixedSize(button_width, button_height);
    connect(cancel_button, SIGNAL(clicked()), this, SLOT(Close()));
    selector_layout->addWidget(cancel_button, 1, 0, 1, 1);

    // Add cancel label
    QLabel* cancel_label = new QLabel("Cancel and Discard Changes.");
    selector_layout->addWidget(cancel_label, 1, 1, 1, 1);

    // Set the layout
    selector_widget->setLayout(selector_layout);

    // Add to main widget
    m_stack_widget->addWidget(selector_widget);
}

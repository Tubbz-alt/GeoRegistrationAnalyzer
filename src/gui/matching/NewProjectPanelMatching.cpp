/**
 * @file    NewProjectPanelMatching.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "NewProjectPanelMatching.hpp"

// Qt Libraries
#include <QLabel>


/**********************************/
/*          Constructor           */
/**********************************/
NewProjectPanelMatching::NewProjectPanelMatching( System_Configuration::ptr_t sys_config,
                                                  QWidget*                    parent )
 : NewProjectPanelBase(sys_config,
                       parent),
   m_class_name("NewProjectPanelMatching")
{
    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/*******************************/
/*       Save the Project      */
/*******************************/
void NewProjectPanelMatching::Save_Project()
{
    // Save the project


    // Close the project
    emit Close_Dialog();
}


/**********************************/
/*       Cancel the Project       */
/**********************************/
void NewProjectPanelMatching::Cancel_Project()
{
    emit Close_Dialog();
}


/************************************/
/*        Initialize the GUI        */
/************************************/
void NewProjectPanelMatching::Initialize_GUI()
{
    // Create the layout
    m_main_layout = new QVBoxLayout();

    // Build the Editor
    Build_Editor();

    // Build the Toolbar
    Build_Toolbar();

    // Set the layout
    setLayout(m_main_layout);
}


/**********************************************/
/*         Initialize the Configuration       */
/**********************************************/
void NewProjectPanelMatching::Initialize_Configuration()
{
    // Add Panel Toolbar Information
    m_sys_config->Add_Config_Param("system.matching.newprojectpanel.toolbar.save_icon",
                                   "export.png",
                                   "#  Path of the save button icon",
                                   false );

    m_sys_config->Add_Config_Param("system.matching.newprojectpanel.toolbar.cancel_icon",
                                   "close.png",
                                   "#  Path of the cancel button icon",
                                   false );

    m_sys_config->Add_Config_Param("system.matching.newprojectpanel.toolbar.icon_width",
                                   "70",
                                   "#  Icon Width",
                                   false );

    m_sys_config->Add_Config_Param("system.matching.newprojectpanel.toolbar.icon_height",
                                   "70",
                                   "#  Icon Height",
                                   false );

    m_sys_config->Add_Config_Param("system.matching.newprojectpanel.toolbar.button_width",
                                   "90",
                                   "#  Button Width",
                                   false );

    m_sys_config->Add_Config_Param("system.matching.newprojectpanel.toolbar.button_height",
                                   "90",
                                   "#  Button Height",
                                   false );
}


/****************************************/
/*          Build the Editor            */
/****************************************/
void NewProjectPanelMatching::Build_Editor()
{
    // Create the editor widget
    QWidget* editor_widget = new QWidget(this);
    editor_widget->setContentsMargins(0,0,0,0);

    // Build the layout
    m_editor_layout = new QVBoxLayout();

    // Create the project name widget
    Build_Project_Name_Widget();

    // Create the project id widget
    Build_Project_ID_Widget();

    // Set the layout
    editor_widget->setLayout(m_editor_layout);

    // Set the widget
    m_main_layout->addWidget(editor_widget);
}


/****************************************************/
/*          Build the Project Name Widget           */
/****************************************************/
void NewProjectPanelMatching::Build_Project_Name_Widget()
{
    // Path info
    std::string help_icon_path = m_sys_config->Get_Icon_Path() + "/question.png";

    // Project Name Widget
    QWidget* name_widget = new QWidget();

    // Layout
    QGridLayout* name_layout = new QGridLayout();
    name_layout->setAlignment(Qt::AlignTop);
    name_layout->setContentsMargins(0,0,0,0);

    // Label
    QLabel* name_label = new QLabel("Project Name");
    name_layout->addWidget(name_label, 0, 0, 1, 2);

    // Edit
    m_project_name_edit = new QLineEdit();
    m_project_name_edit->setText("My Project");
    name_layout->addWidget(m_project_name_edit, 1, 0, 1, 1);

    // Tip Button
    QToolButton* help_button = new QToolButton();
    help_button->setIcon(QIcon(help_icon_path.c_str()));
    help_button->setToolTip("Name of Project.");
    help_button->setCheckable(false);
    name_layout->addWidget(help_button, 1, 1, 1, 1);


    // Set the layout
    name_widget->setLayout(name_layout);

    // Add to layout
    m_editor_layout->addWidget(name_widget);
}


/**************************************************/
/*          Build the Project ID Widget           */
/**************************************************/
void NewProjectPanelMatching::Build_Project_ID_Widget()
{
    // Path info
    std::string help_icon_path = m_sys_config->Get_Icon_Path() + "/question.png";

    // Project ID Widget
    QWidget* id_widget = new QWidget();

    // Layout
    QGridLayout* id_layout = new QGridLayout();
    id_layout->setAlignment(Qt::AlignTop);
    id_layout->setContentsMargins(0,0,0,0);

    // Label
    QLabel* id_label = new QLabel("Project ID");
    id_layout->addWidget(id_label, 0, 0, 1, 2);

    // Edit
    m_project_id_edit = new QLineEdit();
    m_project_id_edit->setText("my_project");
    id_layout->addWidget(m_project_id_edit, 1, 0, 1, 1);

    // Tip Button
    QToolButton* help_button = new QToolButton();
    help_button->setIcon(QIcon(help_icon_path.c_str()));
    help_button->setToolTip("String with no spaces and special characters.");
    help_button->setCheckable(false);
    id_layout->addWidget(help_button, 1, 1, 1, 1);


    // Set the layout
    id_widget->setLayout(id_layout);

    // Add to layout
    m_editor_layout->addWidget(id_widget);
}


/*************************************/
/*          Build the Toolbar        */
/*************************************/
void NewProjectPanelMatching::Build_Toolbar()
{
    // Create toolbar
    QWidget* toolbar_widget = new QWidget(this);
    QHBoxLayout* toolbar_layout = new QHBoxLayout();
    toolbar_layout->setContentsMargins(0,0,0,0);
    toolbar_layout->setMargin(0);

    // Prep default info
    bool value_found;
    int def_icon_height = m_sys_config->Query_Config_Param_Int32("system.matching.newprojectpanel.toolbar.icon_height",
                                                                 value_found);
    int def_icon_width = m_sys_config->Query_Config_Param_Int32("system.matching.newprojectpanel.toolbar.icon_width",
                                                                value_found);

    int def_button_height = m_sys_config->Query_Config_Param_Int32("system.matching.newprojectpanel.toolbar.button_height",
                                                                   value_found);
    int def_button_width = m_sys_config->Query_Config_Param_Int32("system.matching.newprojectpanel.toolbar.button_width",
                                                                   value_found);

    // Icon base path
    std::string icon_base_path = m_sys_config->Get_Icon_Path();
    std::string button_icon_path;

    // Create Save Button
    button_icon_path = m_sys_config->Query_Config_Param("system.matching.newprojectpanel.toolbar.save_icon", value_found);
    button_icon_path = icon_base_path + "/" + button_icon_path;
    QToolButton* saveButton = new QToolButton(toolbar_widget);
    saveButton->setText("Save");
    saveButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    saveButton->setIcon(QIcon(button_icon_path.c_str()));
    saveButton->setFixedSize(def_button_width, def_button_height);
    saveButton->setIconSize(QSize(def_icon_width, def_icon_height));
    toolbar_layout->addWidget(saveButton);
    connect(saveButton, SIGNAL(clicked()), this, SLOT(Save_Project()));


    // Create Cancel Button
    button_icon_path = m_sys_config->Query_Config_Param("system.matching.newprojectpanel.toolbar.cancel_icon", value_found);
    button_icon_path = icon_base_path + "/" + button_icon_path;
    QToolButton* cancelButton = new QToolButton(toolbar_widget);
    cancelButton->setText("Cancel");
    cancelButton->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    cancelButton->setIcon(QIcon(button_icon_path.c_str()));
    cancelButton->setFixedSize(def_button_width, def_button_height);
    cancelButton->setIconSize(QSize(def_icon_width, def_icon_height));
    toolbar_layout->addWidget(cancelButton);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(Cancel_Project()));

    // Set layout
    toolbar_widget->setLayout(toolbar_layout);

    // Add to main layout
    m_main_layout->addWidget(toolbar_widget);
}

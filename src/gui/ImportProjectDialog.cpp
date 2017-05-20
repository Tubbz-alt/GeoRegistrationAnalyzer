/**
 * @file    ImportProjectDialog.cpp
 * @author  Marvin Smith
 * @date    5/20/2017
 */
#include "ImportProjectDialog.hpp"

// Qt Libraries
#include <QFileSelector>
#include <QLabel>
#include <QToolButton>
#include <QVBoxLayout>


/************************************/
/*            Constructor           */
/************************************/
ImportProjectDialog::ImportProjectDialog( System_Configuration::ptr_t sys_config,
                                          QWidget*                    parent)
  : QDialog(parent),
    m_class_name("ImportProjectDialog"),
    m_sys_config(sys_config)
{
    // Initialize Configuration
    Initialize_Configuration();

    // Initialize GUI
    Initialize_GUI();

}


/*****************************************/
/*           Import File Slot            */
/*****************************************/
void ImportProjectDialog::Import_Project_File()
{
    // Change the widget
    m_stack_widget->setCurrentIndex(1);
}

/*******************************/
/*      Initialize the GUI     */
/*******************************/
void ImportProjectDialog::Initialize_GUI()
{
    // Query Relevant Parameters
    bool value_found;

    std::string window_title = m_sys_config->Query_Config_Param("system.gui.import_project.title", value_found );

    // Create the main layout
    m_main_layout = new QVBoxLayout();

    m_stack_widget = new QStackedWidget();

    // Build the File Chooser
    Build_File_Chooser();

    // Build the Project Viewer Button
    Build_Project_Viewer();

    m_main_layout->addWidget(m_stack_widget);

    // Set the layout
    setLayout(m_main_layout);

    setWindowTitle(window_title.c_str());
}


/*************************************/
/*      Initialize Configuration     */
/*************************************/
void ImportProjectDialog::Initialize_Configuration()
{
    // Title of Pref Dialog
    m_sys_config->Add_Config_Param("system.gui.import_project.title",
                                   "Import Project",
                                   "#  Title of Dialog",
                                   false );

    // Button Sizes
    m_sys_config->Add_Config_Param("system.gui.import_project.button_width",
                                   "70",
                                   "#  Width of Import Project Button",
                                   false );

    m_sys_config->Add_Config_Param("system.gui.import_project.button_height",
                                   "40",
                                   "#  Height of Import Project Button",
                                   false );
}


/**********************************************/
/*       Build the Project File Chooser       */
/**********************************************/
void ImportProjectDialog::Build_File_Chooser()
{
    bool value_found;
    int button_width  = m_sys_config->Query_Config_Param_Int32("system.gui.import_project.button_width", value_found);
    int button_height = m_sys_config->Query_Config_Param_Int32("system.gui.import_project.button_height", value_found);

    QWidget* widget = new QWidget(this);

    QVBoxLayout* layout = new QVBoxLayout();

    std::string widget_text;
    widget_text += "1.  Click on \"Import File\" Button to Load Project File.\n\n";
    widget_text += "2.  View Project Changes.  Then select the \"Import\" Button.\n\n";
    widget_text += "Note:  At any time, select \"Cancel\" to abort changes.";


    // Create the label
    QLabel* label = new QLabel();
    label->setText(widget_text.c_str());
    layout->addWidget(label);

    // Select Button
    QWidget* toolbar_widget = new QWidget();
    QHBoxLayout* toolbar_layout = new QHBoxLayout();

    // Create Import Button
    QToolButton* import_button = new QToolButton();
    import_button->setText("Import File");
    import_button->setFixedSize( button_width,
                                 button_height);
    toolbar_layout->addWidget(import_button);
    connect(import_button, SIGNAL(clicked()), this, SLOT(Import_Project_File()));

    // Create Cancel Button
    QToolButton* cancel_button = new QToolButton();
    cancel_button->setText("Cancel");
    cancel_button->setFixedSize( button_width,
                                 button_height);
    toolbar_layout->addWidget(cancel_button);
    connect( cancel_button, SIGNAL(clicked()), this, SLOT(close()));


    toolbar_widget->setLayout(toolbar_layout);
    layout->addWidget(toolbar_widget);


    // Select Layout
    widget->setLayout(layout);

    // Add to stack layout
    m_stack_widget->addWidget(widget);
}

/****************************************/
/*       Build the Project Viewer       */
/****************************************/
void ImportProjectDialog::Build_Project_Viewer()
{
    // Query Button Sizes
    bool value_found;
    int button_width  = m_sys_config->Query_Config_Param_Int32("system.gui.import_project.button_width", value_found);
    int button_height = m_sys_config->Query_Config_Param_Int32("system.gui.import_project.button_height", value_found);


    // Build main widget
    QWidget* widget = new QWidget(this);

    // Build main layout
    QVBoxLayout* layout = new QVBoxLayout();


    // Toolbar
    QWidget* toolbar_widget = new QWidget();
    QHBoxLayout* toolbar_layout = new QHBoxLayout();

    // Create Import Button
    QToolButton* import_button = new QToolButton();
    import_button->setText("Import");
    import_button->setFixedSize( button_width,
                                 button_height);
    toolbar_layout->addWidget(import_button);

    // Create Cancel Button
    QToolButton* cancel_button = new QToolButton();
    cancel_button->setText("Cancel");
    cancel_button->setFixedSize( button_width,
                                 button_height);
    toolbar_layout->addWidget(cancel_button);
    connect( cancel_button, SIGNAL(clicked()), this, SLOT(close()));


    toolbar_widget->setLayout(toolbar_layout);
    layout->addWidget(toolbar_widget);

    // Select Layout
    widget->setLayout(layout);

    // Add to stack layout
    m_stack_widget->addWidget(widget);

}

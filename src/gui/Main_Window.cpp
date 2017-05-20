/**
 * @file    Main_Window.cpp
 * @author  Marvin Smith
 * @date    4/21/2017
 */
#include "Main_Window.hpp"

// C++ Libraries
#include <iostream>

// Qt Libraries
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>

// Project Libraries
#include "ConfigurationSaveDialog.hpp"


/**********************************/
/*          Constructor           */
/**********************************/
Main_Window::Main_Window( System_Configuration::ptr_t sys_config,
                          QWidget*                    parent )
 : QMainWindow(parent),
   m_class_name("Main_Window"),
   m_sys_config(sys_config)
{
    // Update Configuration
    Update_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/****************************************/
/*       Load the Project Pathname      */
/****************************************/
void Main_Window::Load_Project(const std::string &project_pathname)
{

    // Load the project file for the project type

}


/****************************************/
/*          Inititalize the GUI         */
/****************************************/
void Main_Window::Initialize_GUI()
{
    // Create the stack Widgets
    m_stack_widget = new QStackedWidget(this);

    // Add each sub-widget
    m_stack_widget->addWidget( new MatchingBasePanel(m_sys_config,
                                                     this));

    m_stack_widget->addWidget( new AnalysisBasePanel(m_sys_config,
                                                     this));

    setCentralWidget( m_stack_widget );

    // Build the Preference Dialog
    m_pref_dialog = new PreferenceDialog(m_sys_config, this);

    // Build the Import Dialog
    m_import_project_dialog = new ImportProjectDialog(m_sys_config, this);


    // Build the Menu Bar
    Build_Menu();

    // CHeck if System Configuration File Exists
    if( !m_sys_config->Config_File_Path_Exists() )
    {
        // Create Dialog to ask if user wants to create new config
        ConfigurationSaveDialog* temp_dialog = new ConfigurationSaveDialog(m_sys_config,
                                                                           this);

        // Show the Dialog
        temp_dialog->exec();

        // Check the dialog
        if( temp_dialog->Save_Configuration() )
        {
            m_sys_config->Generate_Configuration_File();
        }
        else
        {
        }
    }
}


/*************************************/
/*          Close the GUI            */
/*************************************/
void Main_Window::closeEvent(QCloseEvent *event)
{

    // Check if changes to the config were generated
    if( m_sys_config->Has_Changed() )
    {
        std::cout << "Changes Detected" << std::endl;
        QMessageBox::Icon window_icon = QMessageBox::Icon::Question;
        QString window_title = "System Configuration Changed";
        QString window_text = "Changes were detected in the system config.\nWould you like to update the config file?";
        QMessageBox::StandardButtons window_buttons = QMessageBox::StandardButton::Save | QMessageBox::StandardButton::Discard;

        QMessageBox* box = new QMessageBox( window_icon,
                                            window_title,
                                            window_text,
                                            window_buttons );

        int ret = box->exec();
        if( ret == QMessageBox::StandardButton::Save )
        {
            m_sys_config->Generate_Configuration_File();
        }
    }
    else
    {
        std::cout << "No Changes Detected" << std::endl;
    }

    // Clean up the System Configuration
    m_sys_config->Finalize();

}


/******************************/
/*     Open a New Project     */
/******************************/
void Main_Window::Import_Project_Dialog()
{
    // Create the file dialog
    m_import_project_dialog->show();
}


/*************************************/
/*        Update Configuration       */
/*************************************/
void Main_Window::Update_Configuration()
{

}


/****************************/
/*        Build Menu        */
/****************************/
void Main_Window::Build_Menu()
{
    //  Create a File Menu
    QMenu* fileMenu = new QMenu(tr("File"));
    QMenu* projectMenu = new QMenu(tr("Project"));

    // Create the Preferences Action
    QAction* prefAction = new QAction(tr("&Preferences"), this);
    prefAction->setStatusTip("View/Modify Application Preferences");
    connect(prefAction, SIGNAL(triggered()), m_pref_dialog, SLOT(show()));
    fileMenu->addAction(prefAction);


    // Add Quit Action
    QAction* quitAction = new QAction(tr("&Quit"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    quitAction->setStatusTip("Quit Program");
    connect( quitAction, SIGNAL(triggered()), this, SLOT(close()));
    fileMenu->addAction(quitAction);


    // Create the Load Project Action
    QAction* loadProjectAction = new QAction(tr("&Import Project"), this);
    loadProjectAction->setStatusTip("Import Project");
    connect( loadProjectAction, SIGNAL(triggered()), this, SLOT(Import_Project_Dialog()));
    projectMenu->addAction(loadProjectAction);

    // Add file menu
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(projectMenu);

}

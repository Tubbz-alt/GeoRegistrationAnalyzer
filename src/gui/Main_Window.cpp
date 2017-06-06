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
#include "../log/System_Logger.hpp"


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
    // Log Entry
    LOG_CLASS_ENTRY();

    // Load the project file for the project type
    bool project_status;
    Config_Param  project_info = Config_Param::Load_Key_Value_File(project_pathname, project_status);

    // Find the project to load
    std::string project_type = project_info.Query_KV_Pair("project.type", project_status);

    if( !project_status || m_project_panels.find(project_type) == m_project_panels.end() )
    {
        std::cerr << "Unable to find matching project" << std::endl;
        std::exit(-1);
    }
    else
    {
        // Import the new project
        m_project_panels[project_type]->Import_Project(project_info);
    }

    // Log Exit
    LOG_CLASS_EXIT();
}


/****************************************/
/*          Inititalize the GUI         */
/****************************************/
void Main_Window::Initialize_GUI()
{
    // Create the stack Widgets
    m_stack_widget = new QStackedWidget(this);

    // Build project panels
    m_project_panels["matching"] = new MatchingBasePanel(m_sys_config, this);
    m_project_panels["analysis"] = new AnalysisBasePanel(m_sys_config, this);

    // Add each sub-widget
    m_stack_widget->addWidget( m_project_panels["matching"]);
    m_stack_widget->addWidget( m_project_panels["analysis"]);

    setCentralWidget( m_stack_widget );

    // Build the Preference Dialog
    m_pref_dialog = new PreferenceDialog(m_sys_config, this);

    // Build the New Project Dialog
    m_new_project_dialog = new NewProjectDialog(m_sys_config, this);

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
void Main_Window:: New_Project_Dialog()
{
    // Create the file dialog
    m_new_project_dialog->exec();

    // Check if project loaded
    if( m_new_project_dialog->Project_Loaded() )
    {
        // Grab the project information
        Config_Param  project_info = m_new_project_dialog->Get_Project_Info();

        // Find the project to load
        bool match_found;
        std::string project_type = project_info.Query_KV_Pair("project.type", match_found);

        if( !match_found || m_project_panels.find(project_type) == m_project_panels.end() )
        {
            std::cerr << "Unable to find matching project" << std::endl;
            std::exit(-1);
        }
        else
        {
            // Import the new project
            m_project_panels[project_type]->Import_Project(project_info);
        }
    }
    else
    {
        std::cout << "Canceled Import" << std::endl;
    }
}


/******************************/
/*     Open a New Project     */
/******************************/
void Main_Window::Import_Project_Dialog()
{
    // Create the file dialog
    m_import_project_dialog->exec();

    // Check if project loaded
    if( m_import_project_dialog->Project_Loaded() )
    {
        // Grab the project information
        Config_Param  project_info = m_import_project_dialog->Get_Project_Info();

        // Find the project to load
        bool match_found;
        std::string project_type = project_info.Query_KV_Pair("project.type", match_found);

        if( !match_found || m_project_panels.find(project_type) == m_project_panels.end() )
        {
            std::cerr << "Unable to find matching project" << std::endl;
            std::exit(-1);
        }
        else
        {
            // Import the new project
            m_project_panels[project_type]->Import_Project(project_info);
        }
    }
    else
    {
        std::cout << "Canceled Import" << std::endl;
    }
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


    // Create the New Project Action
    QAction* newProjectAction = new QAction(tr("&New Project"), this);
    newProjectAction->setStatusTip("Create New Project");
    connect(newProjectAction, SIGNAL(triggered()), this, SLOT(New_Project_Dialog()));
    projectMenu->addAction(newProjectAction);

    // Create the Load Project Action
    QAction* loadProjectAction = new QAction(tr("&Import Project"), this);
    loadProjectAction->setStatusTip("Import Project");
    connect( loadProjectAction, SIGNAL(triggered()), this, SLOT(Import_Project_Dialog()));
    projectMenu->addAction(loadProjectAction);

    // Add file menu
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(projectMenu);

}

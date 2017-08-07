/**
 * @file    Main_Window.cpp
 * @author  Marvin Smith
 * @date    8/4/2017
 */
#include "Main_Window.hpp"

// C++ Libraries
#include <iostream>

// Qt Libraries
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>

// Project Libraries
#include <GeoViewer/log/System_Logger.hpp>


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

    // Create the imagery panel
    ProjectBasePanel* project_panel = new ProjectBasePanel(m_sys_config,
                                                           this);
    m_stack_widget->addWidget(project_panel);


    // Add widget to main gui
    setCentralWidget( m_stack_widget );

    // Build the Menu Bar
    Build_Menu();

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

    // Add Quit Action
    QAction* quitAction = new QAction(tr("&Quit"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    quitAction->setStatusTip("Quit Program");
    connect( quitAction, SIGNAL(triggered()), this, SLOT(close()));
    fileMenu->addAction(quitAction);

    // Add file menu
    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(projectMenu);

}

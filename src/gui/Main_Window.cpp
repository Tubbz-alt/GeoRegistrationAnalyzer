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


    // Build the Menu Bar
    Build_Menu();
}


/*************************************/
/*          Close the GUI            */
/*************************************/
void Main_Window::closeEvent(QCloseEvent *event)
{
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
    QMenu* fileMenu = menuBar()->addMenu(tr("File"));

    // Add File Menu Action
    QAction* quitAction = new QAction(tr("&Quit"), this);
    quitAction->setShortcuts(QKeySequence::Quit);
    quitAction->setStatusTip("Quit Program");
    connect( quitAction, SIGNAL(triggered()), this, SLOT(close()));
    fileMenu->addAction(quitAction);

}

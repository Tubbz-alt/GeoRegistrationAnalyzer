/**
 * @file    Main_Window.cpp
 * @author  Marvin Smith
 * @date    4/21/2017
 */
#include "Main_Window.hpp"

// C++ Libraries
#include <iostream>


/**********************************/
/*          Constructor           */
/**********************************/
Main_Window::Main_Window( System_Configuration::ptr_t sys_config,
                          QWidget*                    parent )
 : QMainWindow(parent),
   m_class_name("Main_Window"),
   m_sys_config(sys_config)
{

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
}


/*************************************/
/*          Close the GUI            */
/*************************************/
void Main_Window::closeEvent(QCloseEvent *event)
{
    // Clean up the System Configuration
    m_sys_config->Finalize();

}

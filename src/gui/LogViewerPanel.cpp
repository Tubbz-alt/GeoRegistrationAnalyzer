/**
 * @file    LogViewerPanel.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "LogViewerPanel.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
LogViewerPanel::LogViewerPanel(System_Configuration::ptr_t sys_config,
                               QWidget *parent)
 : QWidget(parent),
   m_sys_config(sys_config),
   m_class_name("LogViewerPanel")
{
    // Initialize the Config
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/*********************************/
/*       Initialize the GUI      */
/*********************************/
void LogViewerPanel::Initialize_GUI()
{

}


/************************************/
/*      Initialize Configuration    */
/************************************/
void LogViewerPanel::Initialize_Configuration()
{

}

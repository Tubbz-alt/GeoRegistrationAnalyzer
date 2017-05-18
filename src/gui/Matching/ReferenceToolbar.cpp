/**
 * @file    ReferenceToolbar.cpp
 * @author  Marvin Smith
 * @date    5/18/2017
 */
#include "ReferenceToolbar.hpp"

// Qt Libraries
#include <QLabel>
#include <QLineEdit>


/************************************************/
/*         Reference Toolbar Constructor        */
/************************************************/
ReferenceToolbar::ReferenceToolbar( System_Configuration::ptr_t  sys_config,
                                    QWidget*                     parent )
  : QWidget(parent),
    m_class_name("ReferenceToolbar"),
    m_sys_config(sys_config)
{
    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/*************************************/
/*          Initialize the GUI       */
/*************************************/
void ReferenceToolbar::Initialize_GUI()
{
    // Create Grid Layout
    m_main_layout = new QGridLayout();

    // Build the Source Widget
    Build_Source_Widget();

    // Set the layout
    setLayout(m_main_layout);
}


/*********************************************/
/*        Initialize the Configuration       */
/*********************************************/
void ReferenceToolbar::Initialize_Configuration()
{
    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.matching.reference.default.toolbutton.width",
                                   "120",
                                   "#  Default Width of Reference Panel Tool-Button",
                                   false);

    m_sys_config->Add_Config_Param("system.matching.reference.default.toolbutton.height",
                                   "120",
                                   "#  Default Height of Reference Panel Tool-Button",
                                   false);

}

/********************************************/
/*          Build the Source Widget         */
/********************************************/
void ReferenceToolbar::Build_Source_Widget()
{
    // Build the Source Widget
    QWidget*  datasource_widget = new QWidget(this);

    QHBoxLayout* datasource_layout = new QHBoxLayout();

    // Create label
    QLabel* datasource_label = new QLabel("Data Source:");
    datasource_layout->addWidget(datasource_label);

    // Create edit
    m_datasource_edit = new QLineEdit();
    datasource_layout->addWidget(m_datasource_edit);

    // Create update button
    m_datasource_update_button = new QToolButton();
    datasource_layout->addWidget(m_datasource_update_button);

    // Set layout
    datasource_widget->setLayout(datasource_layout);

    // Add to main layout
    m_main_layout->addWidget(datasource_widget, 1, 1, 1, 2);

}

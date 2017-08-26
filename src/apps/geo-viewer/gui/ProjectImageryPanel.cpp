/**
 * @file    ProjectImageryPanel.cpp
 * @author  Marvin Smith
 * @date    8/6/2017
*/
#include "ProjectImageryPanel.hpp"

// Qt Libraries
#include <QVBoxLayout>


/***************************************/
/*             Constructor             */
/***************************************/
ProjectImageryPanel::ProjectImageryPanel( System_Configuration::ptr_t system_config,
                                          QWidget*                    parent  )
  : QWidget(parent),
    m_class_name("ProjectImageryPanel"),
    m_sys_config(system_config)
{
    // Initialize the System-Config Object
    Initialize_Configuration();

    // Build the GUI
    Initialize_GUI();

}


/****************************************/
/*          Initialize The GUI          */
/****************************************/
void ProjectImageryPanel::Initialize_GUI()
{
    // Get the Base Configuration
    bool value_found;
    std::string base_conf = "system.imagery";

    // Create the main layout
    QVBoxLayout* main_layout = new QVBoxLayout();
    main_layout->setContentsMargins(2,2,2,2);

    // Create the geo widget
    m_geo_widget = new GeoWidget(base_conf,
                                 m_sys_config,
                                 this);
    main_layout->addWidget(m_geo_widget);

    // Create the toolbar
    m_toolbar = new ProjectImageryToolbar(m_sys_config, this);
    main_layout->addWidget(m_toolbar);


    // Set the main layout
    setLayout(main_layout);

    // Check system configuration for default source data
    setWindowTitle("Imagery");
}


/*********************************************************/
/*          Initialize the System Configuration          */
/*********************************************************/
void ProjectImageryPanel::Initialize_Configuration()
{

    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.imagery.provider",
                                   "esri",
                                   "#  Default Provider for the Imagery Panel",
                                   false);

    m_sys_config->Add_Config_Param("system.imagery.id",
                                   "viewer",
                                   "#  ID of viewer for internal asset routing.",
                                   false );

    m_sys_config->Add_Config_Param("system.imagery.name",
                                   "Viewer",
                                   "# Name of viewer for external identification.",
                                   false );
}

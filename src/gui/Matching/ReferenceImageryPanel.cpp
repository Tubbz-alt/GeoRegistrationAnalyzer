/**
 * @file    ReferenceImageryPanel.cpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#include "ReferenceImageryPanel.hpp"

// Qt Libraries
#include <QVBoxLayout>


/***************************************/
/*             Constructor             */
/***************************************/
ReferenceImageryPanel::ReferenceImageryPanel( System_Configuration::ptr_t system_config,
                                              QWidget*                    parent  )
  : QWidget(parent),
    m_class_name("ReferenceImageryPanel"),
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
void ReferenceImageryPanel::Initialize_GUI()
{
    // Get the Base Configuration
    bool value_found;
    std::string base_conf = "system.matching.reference";

    // Create the main layout
    QVBoxLayout* main_layout = new QVBoxLayout();
    main_layout->setContentsMargins(2,2,2,2);

    // Create the geo widget
    m_geo_widget = new GeoWidget(base_conf,
                                 m_sys_config,
                                 this);
    main_layout->addWidget(m_geo_widget);

    // Create the toolbar
    m_toolbar = new ReferenceToolbar(m_sys_config, this);
    main_layout->addWidget(m_toolbar);


    // Set the main layout
    setLayout(main_layout);

    // Check system configuration for default source data
    setWindowTitle("Reference Imagery");
}


/*********************************************************/
/*          Initialize the System Configuration          */
/*********************************************************/
void ReferenceImageryPanel::Initialize_Configuration()
{

    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.matching.reference.provider",
                                   "google",
                                   "#  Default Provider for the Reference Panel",
                                   false);
}

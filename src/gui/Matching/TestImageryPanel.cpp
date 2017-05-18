/**
 * @file    TestImageryPanel.cpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#include "TestImageryPanel.hpp"

// Qt Libraries
#include <QVBoxLayout>


/********************************/
/*          Constructor         */
/********************************/
TestImageryPanel::TestImageryPanel( System_Configuration::ptr_t sys_config,
                                    QWidget*                    parent )
  : QWidget(parent),
    m_class_name("TestImageryPanel"),
    m_sys_config(sys_config)
{
    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}

/************************************/
/*          Initialize GUI          */
/************************************/
void TestImageryPanel::Initialize_GUI()
{
    // Get the Base Configuration
    bool value_found;
    std::string base_conf = "system.matching.test";

    // Create the main layout
    QVBoxLayout* main_layout = new QVBoxLayout();

    // Create the geo widget
    m_geo_widget = new GeoWidget( base_conf,
                                  m_sys_config,
                                  this);
    main_layout->addWidget(m_geo_widget);

    // Set the main layout
    setLayout(main_layout);

    // Set the Window Title
    setWindowTitle("Test Imagery");
}


/*********************************************************/
/*          Initialize the System Configuration          */
/*********************************************************/
void TestImageryPanel::Initialize_Configuration()
{

    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.matching.test.provider",
                                   "local",
                                   "#  Default Provider for the Reference Panel",
                                   false);
}
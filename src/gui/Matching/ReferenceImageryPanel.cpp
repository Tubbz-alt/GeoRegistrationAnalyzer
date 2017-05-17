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

    Initialize_GUI();

}


/****************************************/
/*          Initialize The GUI          */
/****************************************/
void ReferenceImageryPanel::Initialize_GUI()
{
    // Create the main layout
    QVBoxLayout* main_layout = new QVBoxLayout();

    // Create the geo widget
    m_geo_widget = new GeoWidget(m_sys_config, this);
    main_layout->addWidget(m_geo_widget);

    // Set the main layout
    setLayout(main_layout);

    // Check system configuration for default source data
    setWindowTitle("Reference Imagery");
}

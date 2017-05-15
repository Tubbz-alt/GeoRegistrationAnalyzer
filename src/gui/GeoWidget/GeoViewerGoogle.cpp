/**
 * @file GeoViewerGoogle.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "GeoViewerGoogle.hpp"

// Qt Libraries
#include <QVBoxLayout>


/*********************************/
/*          Constructor          */
/*********************************/
GeoViewerGoogle::GeoViewerGoogle( System_Configuration::ptr_t sys_config,
                                  QWidget *parent)
 : GeoViewerBase( sys_config,
                  parent),
   m_class_name("GeoViewerGoogle")
{
    // Update the Configuration Object
    Update_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/****************************************/
/*          Initialize the GUI          */
/****************************************/
void GeoViewerGoogle::Initialize_GUI()
{
    // Create Layout
    QVBoxLayout* main_layout = new QVBoxLayout();

    // Create Web Engine

    // Set layout
    setLayout(main_layout);

}

/*************************************************/
/*          Update the Configuration Object      */
/*************************************************/
void GeoViewerGoogle::Update_Configuration()
{

}


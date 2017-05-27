/**
 * @file GeoViewerLocal.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "GeoViewerLocal.hpp"

// Qt Libraries
#include <QVBoxLayout>


/*********************************/
/*          Constructor          */
/*********************************/
GeoViewerLocal::GeoViewerLocal( const std::string&          base_config_profile,
                                System_Configuration::ptr_t sys_config,
                                QWidget *parent)
 : GeoViewerBase( base_config_profile,
                  sys_config,
                  parent),
   m_class_name("GeoViewerLocal")
{
    // Update the config object
    Update_Configuration();

    // Initialize the Scene
    Initialize_Scene();

    // Build the GUI
    Initialize_GUI();

}

/****************************************/
/*          Initialize the GUI          */
/****************************************/
void GeoViewerLocal::Initialize_GUI()
{
    // Create Layout
    QVBoxLayout* main_layout = new QVBoxLayout();

    // Build View
    m_view = new QGraphicsView(&m_scene, this);
    main_layout->addWidget(m_view);
    main_layout->setContentsMargins(0,0,0,0);

    // Set layout
    setLayout(main_layout);

}

/*************************************************/
/*          Update the Configuration Object      */
/*************************************************/
void GeoViewerLocal::Update_Configuration()
{

}


void GeoViewerLocal::Initialize_Scene()
{
    m_scene.setSceneRect(QRectF(QPoint(-1, 1), QSizeF(2, 2)));
    m_scene.addText("No Dataset Loaded.");
}
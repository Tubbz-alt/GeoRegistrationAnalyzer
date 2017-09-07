/**
 * @file GeoViewerLocal.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "GeoViewerLocal.hpp"

// Qt Libraries
#include <QGraphicsPixmapItem>
#include <QVBoxLayout>


// Project Libraries
#include "../../assets/local/Asset_Local_Image.hpp"
#include "../../assets/Asset_Manager.hpp"
#include "../../log/System_Logger.hpp"


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
    m_viewer_window = new GeoViewerLocalWindow(m_base_config_profile,
                                               m_sys_config,
                                               this);
    main_layout->addWidget(m_viewer_window);
    main_layout->setContentsMargins(0,0,0,0);


    // Set layout
    setLayout(main_layout);

}


/*********************************/
/*        Update the Asset       */
/*********************************/
void GeoViewerLocal::Import_Asset( int asset_id )
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Push to viewer window
    m_viewer_window->Import_Asset(asset_id);

    // Log Exit
    LOG_CLASS_EXIT();
}


/*************************************************/
/*          Update the Configuration Object      */
/*************************************************/
void GeoViewerLocal::Update_Configuration()
{

}


/*******************************************/
/*          Initialize the Scene           */
/*******************************************/
void GeoViewerLocal::Initialize_Scene()
{


}


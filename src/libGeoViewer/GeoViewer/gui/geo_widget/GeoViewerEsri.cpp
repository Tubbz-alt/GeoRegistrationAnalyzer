/**
 * @file GeoViewerEsri.cpp
 * @author  Marvin Smith
 * @date    8/6/2017
 */
#include "GeoViewerEsri.hpp"


// Qt Libraries
#include <QVBoxLayout>

// ArcGIS Libraries
#include <RasterLayer.h>
#include <Raster.h>

// Project Libraries
#include "../../log/System_Logger.hpp"

using namespace Esri::ArcGISRuntime;

/*********************************/
/*          Constructor          */
/*********************************/
GeoViewerEsri::GeoViewerEsri( const std::string&          base_config_profile,
                              System_Configuration::ptr_t sys_config,
                              QWidget*                    parent)
        : GeoViewerBase( base_config_profile,
                         sys_config,
                         parent),
          m_class_name("GeoViewerEsri")
{
    // Update the Configuration Object
    Update_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/*********************************/
/*        Update the Asset       */
/*********************************/
void GeoViewerEsri::Update_Asset(const Asset_Image_Base::ptr_t new_asset)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Log Not Supported
    LOG_CLASS_ERROR("Not Supported Yet.");
    throw std::runtime_error("Not Supported Yet");
}


/****************************************/
/*          Initialize the GUI          */
/****************************************/
void GeoViewerEsri::Initialize_GUI()
{
    // Create Layout
    QVBoxLayout* main_layout = new QVBoxLayout();

    // Create the basemap
    m_basemap = Basemap::imagery(this);

    // Create the map
    m_map = new Map(m_basemap, this);


    // Create the viewer
    m_mapView = new MapGraphicsView( m_map, this );

    // Set the widget
    main_layout = new QVBoxLayout();
    main_layout->addWidget(m_mapView);

    // Set layout
    setLayout(main_layout);

}

/*************************************************/
/*          Update the Configuration Object      */
/*************************************************/
void GeoViewerEsri::Update_Configuration()
{

}


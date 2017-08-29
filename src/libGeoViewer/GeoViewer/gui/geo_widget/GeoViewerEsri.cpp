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
#include "../../core/assets.hpp"
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

    connect(this, SIGNAL(New_Asset_Ready(int)), this, SLOT(Create_Raster_Layer(int)));
}


/*********************************/
/*        Update the Asset       */
/*********************************/
void GeoViewerEsri::Import_Asset( int asset_id )
{
    // Log Entry
    LOG_CLASS_ENTRY();

    emit New_Asset_Ready(asset_id);

    // Log Exit
    LOG_CLASS_EXIT();
}


/****************************************/
/*          Add new Layer to Map        */
/****************************************/
void GeoViewerEsri::Create_Raster_Layer(int asset_id)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Query Asset from Asset-Manager
    Status status = Status::SUCCESS();
    Status temp_status;
    Asset_Base::ptr_t asset = Asset_Manager::Query_Asset(asset_id, status );

    if( asset == nullptr || !status.Not_Failure() )
    {
        LOG_CLASS_ERROR("Unable to Import Asset. " + status.To_Log_String());
    }

    // If no errors, then continue
    if( status.Not_Failure() )
    {
        // Cast to ESRI Type
        Asset_Image_ESRI::ptr_t esri_asset = std::dynamic_pointer_cast<Asset_Image_ESRI>(asset);

        // Make sure asset loaded
        if( !esri_asset->Asset_Loaded() )
        {
            esri_asset->Load_Asset( temp_status );
            status.Append(temp_status);
        }

        // Add raster layer
        if( status.Not_Failure() )
        {
            LOG_CLASS_TRACE("Creating new Raster Layer.");
            m_raster_layer[asset_id] = new RasterLayer( esri_asset->Get_Raster(), this);

            // Add to view
            LOG_CLASS_TRACE("Adding new Raster to MapView Operational Layers.");
            m_map->operationalLayers()->clear();
            m_map->operationalLayers()->append(m_raster_layer[asset_id]);
            LOG_CLASS_TRACE("Finished Adding Layer.");

        }
    }

    // Log Exit
    LOG_CLASS_EXIT();
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


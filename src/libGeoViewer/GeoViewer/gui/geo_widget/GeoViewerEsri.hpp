/**
 * @file    GeoViewerEsri.hpp
 * @author  Marvin Smith
 * @date    8/6/2017
 */
#ifndef GEOVIEWER_GEOVIEWER_ESRI_HPP
#define GEOVIEWER_GEOVIEWER_ESRI_HPP

 // Skip if ArcGIS SDK Disabled
#ifdef USE_ArcGIS_SDK

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "GeoViewerBase.hpp"

// ArcGIS Libraries
#include <Map.h>
#include <MapGraphicsView.h>
#include <Basemap.h>
#include <RasterLayer.h>


/**
 * @class GeoViewerEsri
 */
class GeoViewerEsri : public GeoViewerBase
{
    Q_OBJECT

    signals:

        void New_Asset_Ready( int );

    public:

        /**
         * @brief Constructor for ESRI Qt viewer class
         *
         * @param sys_config
         * @param parent
         */
        GeoViewerEsri( const std::string&          base_config_profile,
                       System_Configuration::ptr_t sys_config,
                       QWidget*                    parent = nullptr );


        /**
         * @brief Add new asset to viewer
         *
         * @param[in] asset_id
         */
        virtual void Import_Asset( int asset_id );


    public slots:

        /**
         * @brief Build a new Raster Layer
         */
        virtual void Create_Raster_Layer( int asset_id );

    protected:

        /**
         * @brief Initialize Gui
         */
        void Initialize_GUI();


    private:

        void Update_Configuration();

        /// Class Name
        std::string m_class_name;

        /// Active ESRI Map
        Esri::ArcGISRuntime::Map* m_map = nullptr;
       
        /// ESRI View
        Esri::ArcGISRuntime::MapGraphicsView* m_mapView = nullptr;
        
        /// ESRI Basemap
        Esri::ArcGISRuntime::Basemap* m_basemap = nullptr;

        /// Active Raster Layers (Key is the Asset-ID)
        std::map<int, Esri::ArcGISRuntime::RasterLayer*> m_raster_layer;

};

#endif // End of #ifdef USE_ArcGIS_SDK

#endif
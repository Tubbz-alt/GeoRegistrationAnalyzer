/**
 * @file    GeoViewerEsri.hpp
 * @author  Marvin Smith
 * @date    8/6/2017
 */
#ifndef GEOVIEWER_GEOVIEWER_ESRI_HPP
#define GEOVIEWER_GEOVIEWER_ESRI_HPP


// Qt Libraries
#include <QWidget>

// Project Libraries
#include "GeoViewerBase.hpp"

// ArcGIS Libraries
#include <Map.h>
#include <MapGraphicsView.h>
#include <Basemap.h>


/**
 * @class GeoViewerEsri
 */
class GeoViewerEsri : public GeoViewerBase
{

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
         * @brief Update the Asset In View
         */
        virtual void Update_Asset( const Asset_Image_Base::ptr_t new_asset );


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

};

#endif
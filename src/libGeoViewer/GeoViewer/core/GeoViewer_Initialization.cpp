/**
 * @file    GeoViewer_Initialization.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "GeoViewer_Initialization.hpp"

// Project Libraries
#include "../assets/Asset_Loader.hpp"
#include "../assets/esri/Asset_Generator_ESRI.hpp"
#include "../assets/local/Asset_Generator_Local.hpp"


/******************************************/
/*          Initialize GeoViewer          */
/******************************************/
void GEOVIEWER_INITIALIZE( Status& status )
{
    // Initialize Status
    status = Status::SUCCESS();
    Status temp_status = Status::SUCCESS();

    // Setup Asset Loader
    Asset_Loader::Initialize(temp_status);
    status.Append( temp_status );

    // Add Each Generator
    if( status.Not_Failure() )
    {
		// Build only if using the ArcGIS SDK
		#ifdef USE_ArcGIS_SDK
        auto esri_config = std::make_shared<Asset_Generator_Config_ESRI>();
        auto esri_generator = std::make_shared<Asset_Generator_ESRI>( esri_config );
        Asset_Loader::Register_Asset_Generator(esri_generator);
		#endif // End of USE_ArcGIS_SDK

        auto local_config = std::make_shared<Asset_Generator_Config_Local>();
        auto local_generator = std::make_shared<Asset_Generator_Local>( local_config );
        Asset_Loader::Register_Asset_Generator(local_generator);
    }


}


/******************************************/
/*           Initialize GeoViewer         */
/******************************************/
void GEOVIEWER_FINALIZE( Status& status )
{
    // Initialize Status
    status = Status::SUCCESS();
    Status temp_status = Status::SUCCESS();

    // Setup Asset Loader
    Asset_Loader::Finalize(temp_status);
    status.Append( temp_status );

}
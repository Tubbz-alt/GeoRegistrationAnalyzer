/**
 * @file    GeoViewer_Initialization.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "GeoViewer_Initialization.hpp"

// Project Libraries
#include "assets.hpp"


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
        auto config = std::make_shared<Asset_Generator_Config_ESRI>();
        auto esri_generator = std::make_shared<Asset_Generator_ESRI>( config );
        Asset_Loader::Register_Asset_Generator(esri_generator);
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
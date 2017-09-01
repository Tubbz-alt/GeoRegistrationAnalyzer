/**
 * @file    Asset_Image_ESRI.cpp
 * @author  Marvin Smith
 * @date    8/12/2017
 */
#include "Asset_Image_ESRI.hpp"

// C++ Libraries
#include <sstream>

// Project Libraries
#include "../log/System_Logger.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
Asset_Image_ESRI::Asset_Image_ESRI( const Config_Param& asset_info )
 : Asset_Image_Base(asset_info),
   m_class_name("Asset_Image_ESRI"),
   m_asset_loaded(false),
   m_raster(nullptr)
{
}


/********************************/
/*          Load Asset          */
/********************************/
void Asset_Image_ESRI::Load_Asset( Status& status )
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize Status
    status = Status::SUCCESS();

    // Get the pathname
    bool match_found;
    const std::string raster_path = m_asset_info.Query_KV_Pair("asset.esri.image.source.pathname", match_found);

    // Error-Check
    if( !match_found )
    {
        status.Append(StatusType::FAILURE,
                      StatusReason::PATH_NOT_FOUND,
                      "No image found at path (" + raster_path + ")");
    }

    else
    {
        m_raster = new Esri::ArcGISRuntime::Raster( QString(raster_path.c_str()));
        m_asset_loaded = true;
    }


    // Log Exit
    LOG_CLASS_EXIT();
}


/************************************/
/*      Convert to Log String       */
/************************************/
std::string Asset_Image_ESRI::To_Log_String(const int &offset) const
{
    // Create gap
    std::string gap(offset, ' ');

    // Create stream
    std::stringstream sin;

    sin << gap << m_class_name << std::endl;

    return sin.str();
}
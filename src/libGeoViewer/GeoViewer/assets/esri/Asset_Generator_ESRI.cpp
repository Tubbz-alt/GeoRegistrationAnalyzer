/**
 * @file    Asset_Generator_ESRI.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "Asset_Generator_ESRI.hpp"


 // Skip if ArcGIS SDK Disabled
#ifdef USE_ArcGIS_SDK

// Boost Libraries
#include <boost/filesystem.hpp>

// Project Libraries
#include "Asset_Image_ESRI.hpp"


/********************************/
/*          Constructor         */
/********************************/
Asset_Generator_Config_ESRI::Asset_Generator_Config_ESRI()
 : Asset_Generator_Config_Base(),
   m_class_name("Asset_Generator_Config_ESRI")
{
}


/********************************/
/*          Constructor         */
/********************************/
Asset_Generator_ESRI::Asset_Generator_ESRI(Asset_Generator_Config_Base::ptr_t config)
  : Asset_Generator_Base(config),
    m_class_name("Asset_Generator_ESRI")
{
}

/***************************************/
/*        Check Valid Asset Path       */
/***************************************/
bool Asset_Generator_ESRI::Is_Valid_Asset_Path( const std::string& asset_path,
                                                std::string&       error_message )
{

    return true;
}


/**************************************/
/*        Load Asset Information      */
/**************************************/
Config_Param Asset_Generator_ESRI::Load_Asset_Info( const std::string&  pathname,
                                                    Status&             status )
{
    // Create output
    Config_Param output;

    // Initialize status
    status = Status::SUCCESS();


    // Load the asset information
    output.Add_KV_Pair("asset.generator","esri");
    output.Add_KV_Pair("asset.esri.type","image");
    output.Add_KV_Pair("asset.esri.image.source.type","file");
    output.Add_KV_Pair("asset.esri.image.source.pathname", pathname);

    // Construct a detail string
    output.Add_KV_Pair("asset.details","Path: " + pathname);

    return output;
}


/*********************************/
/*         Load the Asset        */
/*********************************/
Asset_Base::ptr_t Asset_Generator_ESRI::Load_Asset( const Config_Param& asset_info,
                                                    Status&             status )
{
    // Create Asset
    Asset_Image_ESRI::ptr_t new_asset = std::make_shared<Asset_Image_ESRI>(asset_info);

    // Return asset
    return new_asset;
}

#endif // End of USE_ArcGIS_SDK

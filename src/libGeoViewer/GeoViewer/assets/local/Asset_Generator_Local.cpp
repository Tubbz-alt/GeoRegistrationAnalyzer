/**
 * @file    Asset_Generator_Local.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "Asset_Generator_Local.hpp"


// Boost Libraries
#include <boost/filesystem.hpp>

// Project Libraries
#include "Asset_Local_Image.hpp"


/********************************/
/*          Constructor         */
/********************************/
Asset_Generator_Config_Local::Asset_Generator_Config_Local()
 : Asset_Generator_Config_Base(),
   m_class_name("Asset_Generator_Config_Local")
{
}


/********************************/
/*          Constructor         */
/********************************/
Asset_Generator_Local::Asset_Generator_Local(Asset_Generator_Config_Base::ptr_t config)
  : Asset_Generator_Base(config),
    m_class_name("Asset_Generator_Local")
{
}

/***************************************/
/*        Check Valid Asset Path       */
/***************************************/
bool Asset_Generator_Local::Is_Valid_Asset_Path( const std::string& asset_path,
                                                std::string&       error_message )
{

    return true;
}


/**************************************/
/*        Load Asset Information      */
/**************************************/
Config_Param Asset_Generator_Local::Load_Asset_Info( const std::string&  pathname,
                                                    Status&             status )
{
    // Create output
    Config_Param output;

    // Initialize status
    status = Status::SUCCESS();


    // Load the asset information
    output.Add_KV_Pair("asset.generator","local");
    output.Add_KV_Pair("asset.local.type","image");
    output.Add_KV_Pair("asset.local.image.source.type","file");
    output.Add_KV_Pair("asset.local.image.source.pathname", pathname);

    // Construct a detail string
    output.Add_KV_Pair("asset.details","Path: " + pathname);

    return output;
}


/*********************************/
/*         Load the Asset        */
/*********************************/
Asset_Base::ptr_t Asset_Generator_Local::Load_Asset( const Config_Param& asset_info,
                                                     Status&             status )
{
    // Create Asset
    Asset_Local_Image::ptr_t new_asset = std::make_shared<Asset_Local_Image>(asset_info);

    // Return asset
    return new_asset;
}

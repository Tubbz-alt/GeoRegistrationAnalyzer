/**
 * @file    Asset_Generator_ESRI.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "Asset_Generator_ESRI.hpp"


// Boost Libraries
#include <boost/filesystem.hpp>


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
    output.Add_KV_Pair("asset.source", "local");
    output.Add_KV_Pair("asset.generator","esri");
    output.Add_KV_Pair("asset.local.path", pathname);
    output.Add_KV_Pair("asset.local.type", "esri");


    return output;
}


/*********************************/
/*         Load the Asset        */
/*********************************/
Asset_Base::ptr_t Asset_Generator_ESRI::Load_Asset( const Config_Param& asset_info,
                                                    Status&             status )
{

}

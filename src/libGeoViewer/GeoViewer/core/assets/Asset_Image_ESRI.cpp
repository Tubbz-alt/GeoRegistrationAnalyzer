/**
 * @file    Asset_Image_ESRI.cpp
 * @author  Marvin Smith
 * @date    8/12/2017
 */
#include "Asset_Image_ESRI.hpp"

// C++ Libraries
#include <sstream>

/*********************************/
/*          Constructor          */
/*********************************/
Asset_Image_ESRI::Asset_Image_ESRI( const Config_Param& asset_info )
 : Asset_Image_Base(asset_info),
   m_class_name("Asset_Image_ESRI")
{
    // Load Asset Information
    Load_Asset();
}


/********************************/
/*          Load Asset          */
/********************************/
void Asset_Image_ESRI::Load_Asset()
{

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
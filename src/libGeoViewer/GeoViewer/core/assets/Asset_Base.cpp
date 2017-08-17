/**
 * @file    Asset_Base.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "Asset_Base.hpp"


// C++ Libraries
#include <sstream>


/*********************************/
/*          Constructor          */
/*********************************/
Asset_Base::Asset_Base( const Config_Param& asset_info )
  : m_class_name("Asset_Base"),
    m_asset_info(asset_info)
{

}


/**************************************/
/*        Print to Log String         */
/**************************************/
std::string Asset_Base::To_Log_String(const int &offset) const
{
    // Create gap
    std::string gap(' ', offset);

    // Create stringstream
    std::stringstream sin;

    sin << gap << m_class_name << std::endl;

    return sin.str();
}

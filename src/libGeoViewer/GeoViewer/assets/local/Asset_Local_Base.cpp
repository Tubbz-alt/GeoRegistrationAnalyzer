/**
 * @file    Asset_Local_Base.cpp
 * @author  Marvin Smith
 * @date    9/5/2017
 */
#include "Asset_Local_Base.hpp"


/********************************/
/*          Constructor         */
/********************************/
Asset_Local_Base::Asset_Local_Base(const Config_Param &asset_info)
  : Asset_Base(asset_info),
    m_class_name("Asset_Local_Base")
{

}


/********************************/
/*          Destructor          */
/********************************/
Asset_Local_Base::~Asset_Local_Base()
{
}


/**
 * @file    Asset_Info_Widget_Base.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "Asset_Info_Widget_Base.hpp"


/********************************/
/*          Constructor         */
/********************************/
Asset_Info_Widget_Base::Asset_Info_Widget_Base( const Config_Param& asset_info,
                                                QWidget*            parent )
  : QWidget(parent),
    m_class_name("Asset_Info_Widget_Base")
{

}


/********************************/
/*          Destructor          */
/********************************/
Asset_Info_Widget_Base::~Asset_Info_Widget_Base()
{

}
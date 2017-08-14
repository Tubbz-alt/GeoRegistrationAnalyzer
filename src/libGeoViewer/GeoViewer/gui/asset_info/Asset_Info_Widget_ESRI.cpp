/**
 * @file    Asset_Info_Widget_ESRI.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "Asset_Info_Widget_ESRI.hpp"


/********************************/
/*          Constructor         */
/********************************/
Asset_Info_Widget_ESRI::Asset_Info_Widget_ESRI(const Config_Param& asset_info,
                                               QWidget*            parent)
 : Asset_Info_Widget_Base(asset_info,
                          parent),
   m_class_name("Asset_Info_Widget_ESRI")
{
    Initialize_GUI();
}



/********************************/
/*          Constructor         */
/********************************/
Asset_Info_Widget_ESRI::~Asset_Info_Widget_ESRI()
{
}


/************************************/
/*        Initialize the GUI        */
/************************************/
void Asset_Info_Widget_ESRI::Initialize_GUI()
{
    // Create Layout
    m_main_layout = new QVBoxLayout();


    // Set layout
    setLayout(m_main_layout);
}
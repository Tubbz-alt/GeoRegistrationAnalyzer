/**
 * @file    Asset_Local_Image.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "Asset_Local_Image.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
Asset_Local_Image::Asset_Local_Image( const Config_Param&  asset_info )
  : Asset_Local_Base(asset_info),
    m_class_name("Asset_Local_Image")
{

}


/****************************/
/*        Destructor        */
/****************************/
Asset_Local_Image::~Asset_Local_Image()
{

}


/********************************/
/*      De-allocate memory      */
/********************************/
void Asset_Local_Image::Deallocate()
{

}


/*************************************/
/*        Render Imagery Layer       */
/*************************************/
void Asset_Local_Image::Render_Layer( QPainter&             painter,
                                      SceneViewBase::ptr_t  scene_view,
                                      const double&         current_timestamp,
                                      Status&               status )
{
    // Initialize Status
    status = Status::SUCCESS();

    // Determine if Scene has changed and requires redraw


    // Copy Raster to Scene Painter


}



/**
 * @file    Asset_Local_Image.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "Asset_Local_Image.hpp"

// Project Libraries
#include "../../log.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
Asset_Local_Image::Asset_Local_Image( const Config_Param&  asset_info )
  : Asset_Local_Base(asset_info),
    m_class_name("Asset_Local_Image")
{

}


/********************************/
/*          Constructor         */
/********************************/
Asset_Local_Image::Asset_Local_Image(const Config_Param&             asset_info,
                                     cv::Mat                         image,
                                     const std::vector<cv::Point3d>& corners,
                                     const OGRSpatialReference&      proj_info )
   : Asset_Local_Base(asset_info),
     m_class_name("Asset_Local_Image"),
     m_image(image),
     m_corners(corners),
     m_proj_info(proj_info)
{

}


/****************************/
/*        Destructor        */
/****************************/
Asset_Local_Image::~Asset_Local_Image()
{

}


/********************************/
/*          Load Asset          */
/********************************/
void Asset_Local_Image::Load_Asset()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Misc Vars
    bool match_found;
    Status status = Status::SUCCESS();
    Status temp_status;

    // Get the File Path
    std::string filepath = m_asset_info.Query_KV_Pair("asset.local.image.source.pathname",
                                                       match_found);

    // Check if Match Not Found
    if( !match_found )
    {
        status.Append(StatusType::FAILURE,
                      StatusReason::UNINITIALIZED,
                      "No Path Provided to Asset.");
    }

    // Load actual asset
    if( status.Not_Failure() )
    {

    }

    // Log Exit
    LOG_CLASS_EXIT();
}


/*************************************/
/*        Render Imagery Layer       */
/*************************************/
void Asset_Local_Image::Render_Layer( QPainter&                  painter,
                                      GEO::SceneViewBase::ptr_t  scene_view,
                                      const double&              current_timestamp,
                                      Status&                    status )
{
    // Initialize Status
    status = Status::SUCCESS();

    // Determine if Scene has changed and requires redraw


    // Copy Raster to Scene Painter


}



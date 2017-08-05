/**
 * @file    Asset_Image_Local.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "Asset_Image_Local.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
Asset_Image_Local::Asset_Image_Local( cv::Mat                         image,
                                      const std::vector<cv::Point3d>& corners,
                                      const OGRSpatialReference&      proj_info )
  : Asset_Image_Base(),
    m_class_name("Asset_Image_Local"),
    m_image(image),
    m_corners(corners),
    m_proj_info(proj_info)
{

}


/****************************/
/*        Destructor        */
/****************************/
Asset_Image_Local::~Asset_Image_Local()
{

}


/********************************/
/*      De-allocate memory      */
/********************************/
void Asset_Image_Local::Deallocate()
{

}

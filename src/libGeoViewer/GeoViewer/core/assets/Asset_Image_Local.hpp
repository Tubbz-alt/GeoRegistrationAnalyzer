/**
 * @file    Asset_Image_Local.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef CORE_ASSETS_ASSET_IMAGE_LOCAL_HPP
#define CORE_ASSETS_ASSET_IMAGE_LOCAL_HPP

// C++ Libraries
#include <memory>
#include <string>

// OpenCV Libraries
#include <opencv2/opencv.hpp>

// GDAL Libraries
#include <ogr_spatialref.h>

// Project Libraries
#include "Asset_Image_Base.hpp"

/**
 * @class Asset_Image_Local
 */
class Asset_Image_Local : public Asset_Image_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Image_Local> ptr_t;


        /**
         * @brief Constructor
         */
        Asset_Image_Local( const Config_Param&             asset_info,
                           cv::Mat                         image,
                           const std::vector<cv::Point3d>& corners,
                           const OGRSpatialReference&      proj_info );


        /**
         * @brief Destructor
         */
        virtual ~Asset_Image_Local();


        /**
         * @brief De-Allocate
         */
        void Deallocate();


        /**
         * @brief Get the Image
         */
        inline cv::Mat Get_Image()const{
            return m_image;
        }


    private:

        /// Class Name
        std::string m_class_name;

        // Image Pixel Data
        cv::Mat m_image;

        /// Corner Information
        std::vector<cv::Point3d> m_corners;

        /// Projection Information
        OGRSpatialReference m_proj_info;


}; // End of Asset_Image_Local Class

#endif
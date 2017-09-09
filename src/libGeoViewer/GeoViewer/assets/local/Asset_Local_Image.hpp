/**
 * @file    Asset_Image_Local.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef CORE_ASSETS_ASSET_LOCAL_IMAGE_HPP
#define CORE_ASSETS_ASSET_LOCAL_IMAGE_HPP

// C++ Libraries
#include <memory>
#include <string>

// OpenCV Libraries
#include <opencv2/opencv.hpp>

// GDAL Libraries
#include <ogr_spatialref.h>

// Project Libraries
#include "Asset_Local_Base.hpp"

/**
 * @class Asset_Image_Local
 */
class Asset_Local_Image : public Asset_Local_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Local_Image> ptr_t;


        /**
         * @brief Single Constructor
         */
        Asset_Local_Image( const Config_Param& asset_info );


        /**
         * @brief Constructor
         */
        Asset_Local_Image( const Config_Param&             asset_info,
                           cv::Mat                         image,
                           const std::vector<cv::Point3d>& corners,
                           const OGRSpatialReference&      proj_info );


        /**
         * @brief Destructor
         */
        virtual ~Asset_Local_Image();



        /**
         * @brief Get the Image
         */
        inline cv::Mat Get_Image()const{
            return m_image;
        }


        /**
         * @brief Set the Image Data
         */
        inline void Set_Image( cv::Mat& image )
        {
            m_image = image;
        }


        /**
         * @brief Load
         */
        virtual void Load_Asset();


        /**
         * @brief Render the Layer
         *
         * @param[in]  painter
         * @param[in]  scene_view
         * @param[in]  current_timestamp
         * @param[out] status
         */
        virtual void Render_Layer( QPainter&             painter,
                                   SceneViewBase::ptr_t  scene_view,
                                   const double&         current_timestamp,
                                   Status&               status );


        /**
         * @brief Load the asset's scene information
         *
         * @param[in] default_projection
         * @param[in] status
         */
        virtual SceneViewBase::ptr_t  Create_Scene_View( const OGRSpatialReference&  default_projection,
                                                         Status&                     status )const override;


        /**
         * @brief Get the Image Center
         * @return
         */
        virtual GEO::CoordinateBase::ptr_t Get_Image_Center_Coordinate( Status& status )const;


    private:


        /**
         *
         * @param status
         * @return
         */
        double Compute_Initial_GSD( Status& status )const;


        /// Class Name
        std::string m_class_name;

        // Image Pixel Data
        cv::Mat m_image;

        /// Corner Information
        std::vector<cv::Point3d> m_corners;

        /// Projection Information
        OGRSpatialReference m_proj_info;


}; // End of Asset_Local_Image Class

#endif

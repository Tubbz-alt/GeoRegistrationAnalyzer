/**
 * @file    GDAL_Image_Loader.hpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */
#ifndef IO_GDAL_IMAGE_LOADER_HPP
#define IO_GDAL_IMAGE_LOADER_HPP

// C++ Libraries
#include <string>

// OpenCV Libraries
#include <opencv2/core/core.hpp>

// GDAL Libraries
#include <ogr_spatialref.h>

// Project Libraries
#include "../assets/local/Asset_Local_Base.hpp"


/**
 * @class GDAL_Image_Loader
 */
class GDAL_Image_Loader
{
    public:

        /**
         * @brief Constructor
         */
        GDAL_Image_Loader();


        /**
         * @brief Load an image and store in asset.
         * @param[in]  pathname
         * @param[out] status
         * @param[out] error_msg
         * @return
         */
        static void Load_Image( const std::string&         pathname,
                                cv::Mat&                   image,
                                std::vector<cv::Point3d>&  corners,
                                OGRSpatialReference&       proj_info,
                                Status&                    status );


    private:

        /// Class Name
        std::string m_class_name;

};  // End of GDAL_Image_Loader Class


#endif

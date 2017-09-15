/**
 * @file    TEST_GDAL_Image_Loader.cpp
 * @author  Marvin Smith
 * @date    9/13/2017
 */
#include <gtest/gtest.h>

// GeoViewer Libraries
#include <GeoViewer/io/GDAL_Image_Loader.hpp>

// OpenCV Libraries
#include <opencv2/highgui/highgui.hpp>


/****************************************/
/*          Test the Load-Image         */
/****************************************/
TEST( GDAL_Image_Loader, Load_Image_GeoTiff_16_RGBA )
{
    // Define a test
    const std::string pathname = "data/unit-test-data/sample-images/geotiff/emerald-bay.tif";

    // Output Image
    cv::Mat image;
    std::vector<cv::Point3d> corners;
    OGRSpatialReference proj_info;
    Status status;


    // Pass to GDAL loader
    GDAL_Image_Loader::Load_Image( pathname,
                                   image,
                                   corners,
                                   proj_info,
                                   status );

    // Check image info
    ASSERT_EQ( status.Get_Status_Type(), StatusType::SUCCESS );
}

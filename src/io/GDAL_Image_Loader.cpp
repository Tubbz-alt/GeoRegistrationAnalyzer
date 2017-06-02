/**
 * @file    GDAL_Image_Loader.cpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */
#include "GDAL_Image_Loader.hpp"

// Boost Libraries
#include <boost/filesystem.hpp>

// GDAL Libraries
#include <gdal_priv.h>
#include <cpl_conv.h>

// Project Libraries
#include "GDAL_Utilities.hpp"


namespace bf = boost::filesystem;


/********************************/
/*          Constructor         */
/********************************/
GDAL_Image_Loader::GDAL_Image_Loader()
  : m_class_name("GDAL_Image_Loader")
{

}


/************************************/
/*          Load an Image           */
/************************************/
Asset_Image_Base::ptr_t GDAL_Image_Loader::Load_Image( const std::string& pathname,
                                                       bool&              status,
                                                       std::string&       error_msg)
{
    // Initialize status
    status = true;
    error_msg = "";
    Asset_Image_Base::ptr_t output;

    // Make sure path exists
    if( !bf::exists(bf::path(pathname)))
    {
        status = false;
        error_msg = "Image (" + pathname + ") does not exist.";
    }

    // Otherwise, process
    else
    {
        // GDAL Components
        GDALDriver*  driver;
        GDALDataset* dataset;

        // Open the dataset
        dataset = (GDALDataset*)GDALOpen(pathname.c_str(), GA_ReadOnly);

        // Make sure the dataset is okay
        if( dataset == nullptr )
        {
            status = false;
            error_msg = "Unable to open gdal dataset for image (" + pathname + ")";
        }

        // make sure we have pixel data
        if( status && dataset->GetRasterCount())
        {
            status = false;
            error_msg = "No pixel data inside dataset for image (" + pathname + ")";
        }

        // Grab the driver
        if( status )
        {
            driver = dataset->GetDriver();

            if( driver == nullptr )
            {
                status = false;
                error_msg = "No driver available for image (" + pathname + ")";
            }
        }

        // Get Image Size
        int image_rows, image_cols, channels;
        size_t image_depth, buffer_size;

        if( status )
        {
            image_rows = dataset->GetRasterYSize();
            image_cols = dataset->GetRasterXSize();
            channels = dataset->GetRasterCount();
            image_depth = GDAL_Data_Type_To_Bytes(dataset->GetRasterBand(0)->GetRasterDataType());

            // Compute full size
            buffer_size = image_rows * image_cols * channels * image_depth;
        }
    }


    // return asset
    return output;
}
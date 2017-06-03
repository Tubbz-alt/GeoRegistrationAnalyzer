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

// OpenCV Libraries
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

// Project Libraries
#include "GDAL_Utilities.hpp"
#include "OpenCV_Utilities.hpp"
#include "../log/System_Logger.hpp"


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
    // Log Entry
    const std::string m_class_name = "GDAL_Image_Loader";
    LOG_CLASS_ENTRY();

    // Initialize status
    status = true;
    error_msg = "";
    std::string message;
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
        if( status && dataset->GetRasterCount() <= 0 )
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
        cv::Mat image;
        std::vector<cv::Mat> image_layers;
        std::vector<GDALColorInterp> image_colors;


        if( status )
        {
            image_rows = dataset->GetRasterYSize();
            image_cols = dataset->GetRasterXSize();
            channels = dataset->GetRasterCount();
            image_depth = GDAL_Data_Type_To_Bytes(dataset->GetRasterBand(1)->GetRasterDataType());

            // Compute full size
            buffer_size = image_rows * image_cols * channels * image_depth;

            std::string m_class_name;
            message = "Creating Image.  Cols: " + std::to_string(image_cols) + ", Rows: " + std::to_string(image_rows);
            LOG_CLASS_TRACE(message);

            // Allocate Asset Memory
            image = cv::Mat(image_rows,
                            image_cols,
                            CV_8UC4,
                            cv::Scalar(0, 0, 0, 255));

            // Allocate temporary working memory
            image_layers.resize(channels);

        }

        // Process Memory
        if( status )
        {
            // Log Start
            LOG_CLASS_TRACE("Reading Raster Information");

            char* temp_row = new char[image_rows * image_depth];

            // Iterate over each raster band
            for( int b=1; b<= dataset->GetRasterCount(); b++ )
            {
                // Grab the band
                GDALRasterBand*  band = dataset->GetRasterBand(b);
                GDALDataType gdal_type = band->GetRasterDataType();
                GDALColorInterp gdal_color = band->GetColorInterpretation();
                image_colors.push_back(gdal_color);

                // Allocate layer
                uint64_t offset = 0;
                int cv_type = GDAL_Data_Type_To_OpenCV_Type(gdal_type);

                message  = "Loading Band: " + std::to_string(b) + ", GDAL Type: " + GDALGetDataTypeName(gdal_type);
                message += ", OpenCV Type: " + OpenCV_Depth_Type_To_String(cv_type) + ", GDAL Color: " + GDALGetColorInterpretationName(gdal_color);
                LOG_CLASS_TRACE(message);

                image_layers[b-1] = cv::Mat(image_rows,
                                            image_cols,
                                            cv_type);

                // Iterate over each row
                for( int r=0; r<image_rows; r++ )
                {
                    // Read the data
                    band->RasterIO( GF_Read, 0, r, image_cols, 1,
                                    image_layers[b-1].data + offset, image_cols, 1,
                                    gdal_type, 0, 0);

                    // Increment offset
                    offset += image_cols * image_depth;
                }

            }

            // clean up
            delete [] temp_row;
            temp_row = nullptr;
        }

        // Merge Layers
        cv::merge( image_layers, image);

        // Compute Conversion
        int color_conversion = GDAL_Color_Layers_To_OpenCV_BGRA_Conversion( image_colors );

        // Convert Color
        cv::cvtColor( image, image, color_conversion);

        // Construct Asset
        output = std::make_shared<Asset_Image_Local>(image, geo_transform, metadata);
    }


    // return asset
    return output;
}
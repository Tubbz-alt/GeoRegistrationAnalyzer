/**
 * @file    GDAL_Image_Loader.cpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */
#include "GDAL_Image_Loader.hpp"

// C++ Libraries
#include <cinttypes>

// Boost Libraries
#include <boost/filesystem.hpp>

// GDAL Libraries
#include <gdal_priv.h>
#include <cpl_conv.h>

// OpenCV Libraries
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// Project Libraries
#include "gdal/GDAL_Utilities.hpp"
#include "OpenCV_Utilities.hpp"
#include "../assets/local/Asset_Local_Image.hpp"
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
void GDAL_Image_Loader::Load_Image( const std::string&              pathname,
                                    cv::Mat&                        image,
                                    std::vector<cv::Point3d>&       corners,
                                    OGRSpatialReference&            proj_info,
                                    Status&                         status )
{
    // Log Entry
    const std::string m_class_name = "GDAL_Image_Loader";
    LOG_CLASS_ENTRY();


    // Initialize status
    status = Status::SUCCESS();
    Status temp_status = Status::SUCCESS();

    // GDAL Components
    GDALDriver *driver;
    GDALDataset *dataset;

    // Misc Vars
    std::vector<cv::Mat> image_layers;
    std::vector<GDALColorInterp> image_colors;
    int image_rows, image_cols, channels;
    size_t image_depth, buffer_size;


    // Make sure path exists
    if (!bf::exists(bf::path(pathname)))
    {
        status.Append(StatusType::FAILURE,
                      StatusReason::PATH_NOT_FOUND,
                      "Image (" + pathname + ") does not exist.");
    }

    // Load Dataset
    if (status.Not_Failure())
    {
        // Open the dataset
        dataset = (GDALDataset *) GDALOpen(pathname.c_str(), GA_ReadOnly);

        // Make sure the dataset is okay
        if (dataset == nullptr)
        {
            status.Append(StatusType::FAILURE,
                          StatusReason::UNINITIALIZED,
                          "Unable to open gdal dataset for image (" + pathname + ")");
        }
    }

    // Check Raster
    if (status.Not_Failure())
    {
        // make sure we have pixel data
        if (dataset->GetRasterCount() <= 0)
        {
            status.Append(StatusType::FAILURE,
                          StatusReason::GDAL_ERROR,
                          "No pixel data inside dataset for image (" + pathname + ")");
        }
    }

    // Check Driver
    if( status.Not_Failure() )
    {
        driver = dataset->GetDriver();
        if (driver == nullptr)
        {
            status.Append(StatusType::FAILURE,
                          StatusReason::GDAL_ERROR,
                          "No driver available for image (" + pathname + ")");
        }
    }

    // Get Image Information
    if( status.Not_Failure() )
    {
        // Get Image Size
        image_rows = dataset->GetRasterYSize();
        image_cols = dataset->GetRasterXSize();
        channels = dataset->GetRasterCount();
        image_depth = GDAL_Data_Type_To_Bytes(dataset->GetRasterBand(1)->GetRasterDataType());

        // Compute full size
        buffer_size = image_rows * image_cols * channels * image_depth;

        LOG_CLASS_TRACE("Creating Image.  Cols: " + std::to_string(image_cols)
                        + ", Rows: " + std::to_string(image_rows));

        // Allocate Asset Memory
        image = cv::Mat(image_rows,
                        image_cols,
                        CV_8UC4,
                        cv::Scalar(0, 0, 0, 255));

        // Allocate temporary working memory
        image_layers.resize(channels);

        // Process Memory
        LOG_CLASS_TRACE("Reading Raster Information");

        char *temp_row = new char[image_rows * image_depth];

        // Iterate over each raster band
        for (int b = 1; b <= dataset->GetRasterCount(); b++)
        {
            // Grab the band
            GDALRasterBand *band = dataset->GetRasterBand(b);
            GDALDataType gdal_type = band->GetRasterDataType();
            GDALColorInterp gdal_color = band->GetColorInterpretation();
            image_colors.push_back(gdal_color);

            // Allocate layer
            uint64_t offset = 0;
            int cv_type = GDAL_Data_Type_To_OpenCV_Type(gdal_type);

            std::stringstream sin;
            sin << "Loading Band: " << b << ", GDAL Type: " << GDALGetDataTypeName(gdal_type);
            sin << ", OpenCV Type: " << OpenCV_Depth_Type_To_String(cv_type) << ", GDAL Color: ";
            sin << GDALGetColorInterpretationName(gdal_color);
            LOG_CLASS_TRACE(sin.str());

            // Create temp mat for layer
            image_layers[b - 1] = cv::Mat(cv::Size(image_rows,
                                                   image_cols),
                                          cv_type);

            // Iterate over each row
            for (int r = 0; r < image_rows; r++)
            {
                // Read the data
                band->RasterIO(GF_Read, 0, r, image_cols, 1,
                               image_layers[b - 1].data + offset, image_cols, 1,
                               gdal_type, 0, 0);

                // Increment offset
                offset += image_cols * image_depth;
            }

            // clean up
            delete[] temp_row;
            temp_row = nullptr;
        }
    }

    if( status.Not_Failure() )
    {
        // Merge Layers
        LOG_CLASS_TRACE("Merging Image Layers");
        cv::merge(image_layers, image);
        cv::imwrite("post-merge.png", image);

        // Compute Conversion
        bool skip_conversion;
        int color_conversion = GDAL_Color_Layers_To_OpenCV_BGRA_Conversion(image_colors,
                                                                           skip_conversion);

        // Convert Color
        if (!skip_conversion)
        {
            LOG_CLASS_TRACE("Converting Color: " + OpenCV_ColorConversionCodeToString(color_conversion));
            cv::cvtColor(image,
                         image,
                         color_conversion);
        }

        // Downsample if needed
        cv::Mat temp_img;
        if( image.depth() == CV_16U ||
            image.depth() == CV_16S )
        {
            LOG_CLASS_TRACE("Converting from 16-bit to 8-bit");
            image.convertTo(temp_img, CV_8UC4, 1.0/256.0);
            image = temp_img.clone();
        }

        // Get raster info
        LOG_CLASS_TRACE("Getting Raster Information");
        GDAL_Raster_Info raster_info = Get_Raster_Information(dataset,
                                                              temp_status);
        status.Append(temp_status);
        cv::imwrite("post-color-image.png", image);


        // Construct Asset
        Config_Param asset_info;
        LOG_CLASS_TRACE("Building Image Asset");
        corners = raster_info.corners;
        proj_info = raster_info.proj_info;
    }

    // Close the dataset
    LOG_CLASS_TRACE("Closing Dataset");
    if( dataset != nullptr ) {
        GDALClose(dataset);
    }
}

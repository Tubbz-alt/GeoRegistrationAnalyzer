/**
 * @file    GDAL_Utilities.hpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */
#include "GDAL_Utilities.hpp"


// C++ Libraries
#include <sstream>

// OpenCV Libraries
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


// Project Libraries
#include "../log/System_Logger.hpp"


/*********************************************************/
/*           Convert GDAL Data Type To Bytes             */
/*********************************************************/
uint64_t GDAL_Data_Type_To_Bytes( const GDALDataType& gdal_type )
{
    switch(gdal_type)
    {
        case GDALDataType::GDT_Byte:
            return 1;
        case GDALDataType::GDT_Int16:
            return 2;
        case GDALDataType::GDT_UInt16:
            return 2;
        case GDALDataType::GDT_Int32:
            return 4;
        case GDALDataType::GDT_UInt32:
            return 4;
    }
    return 0;
}


/*********************************************/
/*       Convert GDAL DataType to Bytes      */
/*********************************************/
int GDAL_Data_Type_To_OpenCV_Type( const GDALDataType& gdal_type )
{
    switch(gdal_type)
    {
        case GDALDataType::GDT_Byte:
            return CV_8UC1;
        case GDALDataType::GDT_Int16:
            return CV_16SC1;
        case GDALDataType::GDT_UInt16:
            return CV_16UC1;
        default:
            throw std::runtime_error("Unknown GDALDataType (" + std::string(GDALGetDataTypeName(gdal_type)));
    }

    return CV_8UC1;
}


/******************************************************************************/
/*     Convert GDAL Color Interpretations to OpenCV Color Conversion          */
/******************************************************************************/
int GDAL_Color_Layers_To_OpenCV_RGBA_Conversion( const std::vector<GDALColorInterp>& image_colors,
                                                 bool&                               skip_conversion)
{
    // Default Value
    int output = 0;
    skip_conversion = false;

    // Create combo string
    std::string combo_str;
    for( int i=0; i<image_colors.size(); i++ )
    {
        combo_str += GDALGetColorInterpretationName(image_colors[i]);
        if( i != (image_colors.size()-1))
        {
            combo_str += ",";
        }
    }

    // Check Grayscale
    if( image_colors.size() == 1 )
    {
        output = CV_GRAY2RGBA;
    }

    // Check 3 channels
    else if( image_colors.size() == 3 ||
             image_colors.size() == 4 )
    {
        // Check RGB
        if( image_colors[0] == GDALColorInterp::GCI_RedBand &&
            image_colors[1] == GDALColorInterp::GCI_GreenBand &&
            image_colors[2] == GDALColorInterp::GCI_BlueBand )
        {
            if( image_colors.size() == 3 )
            {
                output = CV_RGB2RGBA;
            }
            else if( image_colors.size() == 4 )
            {
                skip_conversion = true;
            }
            else
            {
                std::string message = "Unknown Color Combo: " + combo_str;
                LOG_FUNCTION_ERROR(message);
                throw std::runtime_error(message);
            }
        }

    }

    else
    {
        std::string message = "Unknown Color Combo: " + combo_str;
        LOG_FUNCTION_ERROR(message);
        throw std::runtime_error(message);
    }

    return output;
}


/***************************************************/
/*         Get Raster Metadata Information         */
/***************************************************/
GDAL_Raster_Info  Get_Raster_Information( GDALDataset* dataset,
                                          Status&      status )
{
    // Create output structure
    GDAL_Raster_Info raster_info;

    // Initialize status
    status = Status::SUCCESS();

    // Check dataset
    if( dataset == nullptr )
    {
        status.Append( StatusType::FAILURE,
                       StatusReason::GDAL_ERROR,
                       "GDALDataset is null.");
    }

    // Otherwise, grab projection information
    if( status.Not_Failure() )
    {
        // Set projection info
        char* pszWkt = const_cast<char*>(dataset->GetProjectionRef());

        raster_info.proj_info.importFromWkt(&pszWkt);

        // Get Image Dimensions
        int img_rows = dataset->GetRasterYSize();
        int img_cols = dataset->GetRasterXSize();

        // Get the geo-transform
        double geo_transform[6];

        if(dataset->GetGeoTransform(geo_transform) == CE_None)
        {
            // corners
            cv::Point3d pt;

            // Top-Left
            int px = 0;
            int py = 0;
            pt.x = geo_transform[0] + px * geo_transform[1] + py * geo_transform[2];
            pt.y = geo_transform[3] + px * geo_transform[4] + py * geo_transform[5];
            raster_info.corners.push_back(cv::Point3d(pt.x, pt.y, 0));

            // Top-Right
            px = img_cols-1;
            py = 0;
            pt.x = geo_transform[0] + px * geo_transform[1] + py * geo_transform[2];
            pt.y = geo_transform[3] + px * geo_transform[4] + py * geo_transform[5];
            raster_info.corners.push_back(cv::Point3d(pt.x, pt.y, 0));

            // Bottom-Right
            px = img_cols-1;
            py = img_rows-1;
            pt.x = geo_transform[0] + px * geo_transform[1] + py * geo_transform[2];
            pt.y = geo_transform[3] + px * geo_transform[4] + py * geo_transform[5];
            raster_info.corners.push_back(cv::Point3d(pt.x, pt.y, 0));

            // Bottom-Left
            px = 0;
            py = img_rows-1;
            pt.x = geo_transform[0] + px * geo_transform[1] + py * geo_transform[2];
            pt.y = geo_transform[3] + px * geo_transform[4] + py * geo_transform[5];
            raster_info.corners.push_back(cv::Point3d(pt.x, pt.y, 0));
        }
    }

    return raster_info;
}

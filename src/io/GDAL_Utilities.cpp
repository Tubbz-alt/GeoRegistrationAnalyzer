/**
 * @file    GDAL_Utilities.hpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */
#include "GDAL_Utilities.hpp"


// C++ Libraries
#include <sstream>

// OpenCV Libraries
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>


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
int GDAL_Color_Layers_To_OpenCV_BGRA_Conversion( const std::vector<GDALColorInterp>& image_colors )
{
    // Default Value
    int output = 0;

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
        output = CV_GRAY2BGRA;
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
                output = CV_RGB2BGRA;
            }
            else if( image_colors.size() == 4 )
            {
                output = CV_RGBA2BGRA;
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
                                          bool&        success,
                                          std::string& error_msg )
{
    // Create output structure
    GDAL_Raster_Info raster_info;

    // Initialize status
    success = true;
    error_msg = "";

    // Check dataset
    if( dataset == nullptr )
    {
        success = false;
        error_msg = "GDALDataset is null.";
    }

    // Otherwise, grab projection information
    else
    {

    }


    return raster_info;
}
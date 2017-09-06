/**
 * @file    GDAL_Utilities.hpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */
#ifndef IO_GDAL_UTILITIES_HPP
#define IO_GDAL_UTILITIES_HPP

// C++ Libraries
#include <cinttypes>
#include <map>
#include <vector>


// GDAL Libraries
#include <gdal_priv.h>
#include <ogr_spatialref.h>


// OpenCV Libraries
#include <opencv2/core/core.hpp>


// Project Libraries
#include "../../core/Status.hpp"


/**
 * @struct GDAL_Raster_Info
 */
struct GDAL_Raster_Info
{
    /// Projection Information
    OGRSpatialReference proj_info;

    /// Corner Info
    std::vector<cv::Point3d> corners;

    /// Metadata
    std::map<std::string,std::string> metadata;

};

/**
 * @brief GDAL Data Type to Number Bytes
 */
uint64_t  GDAL_Data_Type_To_Bytes( const GDALDataType& gdal_type );


/**
 * @brief Convert GDAL DataType to Bytes
 */
int GDAL_Data_Type_To_OpenCV_Type( const GDALDataType& gdal_type );


/**
 * @brief Convert GDAL Color Interpretations to OpenCV Color Conversion
 */
int GDAL_Color_Layers_To_OpenCV_RGB_Conversion( const std::vector<GDALColorInterp>& image_colors,
                                                bool&                               skip_conversion );


/**
 * @brief Extract Useful Raster Information
 *
 */
GDAL_Raster_Info  Get_Raster_Information( GDALDataset* dataset,
                                          Status&      status  );

#endif

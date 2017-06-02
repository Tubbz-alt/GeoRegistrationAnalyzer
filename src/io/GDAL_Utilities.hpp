/**
 * @file    GDAL_Utilities.hpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */
#ifndef IO_GDAL_UTILITIES_HPP
#define IO_GDAL_UTILITIES_HPP

#include <gdal_priv.h>

/**
 * @brief GDAL Data Type to Number Bytes
 */
size_t GDAL_Data_Type_To_Bytes( const GDALDataType& type );


#endif
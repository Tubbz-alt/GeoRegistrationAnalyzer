/**
 * @file    OpenCV_Utilities.hpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#ifndef IO_OPENCV_UTILITIES_HPP
#define IO_OPENCV_UTILITIES_HPP

// OpenCV Libraries
#include <opencv2/core/core.hpp>


/**
 * @brief Convert OpenCV Depth Type to String
 * @param cv_type  OpenCV Depth Type.
 * @return
 */
std::string OpenCV_Depth_Type_To_String( const int& cv_type );


/**
 * @brief Convert ColorConversionCode to string (COLOR_RGBA2YUV)
 * @param cv_type
 * @return
 */
std::string OpenCV_ColorConversionCodeToString( const int& cv_type );


#endif

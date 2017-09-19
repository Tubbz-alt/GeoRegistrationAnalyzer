/**
 * @file    OpenCV_Utilities.cpp
 * @author  Marvin Smith
 * @date    6/3/2017
 */
#include "OpenCV_Utilities.hpp"

//OpenCV Libraries
#include <opencv2/imgproc/imgproc.hpp>

/*********************************************************/
/*          Convert OpenCV Depth Type to String          */
/*********************************************************/
std::string OpenCV_Depth_Type_To_String( const int& cv_type )
{
    switch(cv_type)
    {
        case CV_8UC1:
            return "CV_8UC1";
        case CV_8UC2:
            return "CV_8UC2";
        case CV_8UC3:
            return "CV_8UC3";
        case CV_8UC4:
            return "CV_8UC4";
        case CV_16UC1:
            return "CV_16UC1";
        case CV_16UC2:
            return "CV_16UC2";
        case CV_16UC3:
            return "CV_16UC3";
        case CV_16SC1:
            return "CV_16SC1";
        case CV_16SC2:
            return "CV_16SC2";
        case CV_16SC3:
            return "CV_16SC3";
        default:
            return "UNKNOWN (value: " + std::to_string(cv_type) + ")";
    }
    return "UNKNOWN";
}


/************************************************************/
/*      Convert OpenCV Color-Conversion Code to String      */
/************************************************************/
std::string OpenCV_ColorConversionCodeToString( const int& cv_type )
{
    switch(cv_type)
    {
        case cv::COLOR_GRAY2RGBA:
            return "COLOR_GRAY2RGBA";
        case cv::COLOR_RGB2RGBA:
            return "COLOR_RGB2RGBA";
        case cv::COLOR_RGB2BGRA:
            return "COLOR_RGB2BGRA";
        case cv::COLOR_RGBA2BGRA:
            return "COLOR_RGBA2BGRA";
        default:
            return "UNKNOWN";
    }
    return "UNKNOWN";
}
/**
 * @file    CoordinateFactory.hpp
 * @author  Marvin Smith
 * @date    9/8/2017
 */
#ifndef LIB_GEO_IMAGE_COORDINATE_COORDINATE_FACTORY_HPP
#define LIB_GEO_IMAGE_COORDINATE_COORDINATE_FACTORY_HPP

// Project Libraries
#include "CoordinateBase.hpp"

// OpenCV Libraries
#include <opencv2/core/core.hpp>

// GDAL Libraries
#include <ogr_spatialref.h>


namespace GEO{


/**
 * @class CoordinateFactory
 */
class CoordinateFactory
{
    public:

        /**
         * @brief Create Coordinate
         */
        static CoordinateBase::ptr_t  Create( const OGRSpatialReference&  projection,
                                              const cv::Point3d&          coordinate );


}; // End of CoordinateFactory Class


} // End of GEO Namespace

#endif
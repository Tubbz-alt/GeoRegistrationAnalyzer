/**
 * @file    CoordinateFactory.cpp
 * @author  Marvin Smith
 * @date    9/8/2017
 */
#include "CoordinateFactory.hpp"

// Project Libraries
#include "CoordinateGeographic.hpp"
#include "CoordinateUTM.hpp"


// C++ Libraries
#include <iomanip>

namespace GEO{


/********************************************/
/*          Create a new coordinate         */
/********************************************/
CoordinateBase::ptr_t CoordinateFactory::Create( const OGRSpatialReference& projection,
                                                 const cv::Point3d&         coordinate )
{
    // Create output coordinate
    CoordinateBase::ptr_t output;

    // Check projection (UTM)
    int is_north;
    if( projection.GetUTMZone(&is_north) != 0 )
    {
        std::stringstream gz_string;
        gz_string << std::setprecision(2) << projection.GetUTMZone();
        output = std::make_shared<CoordinateUTM>( gz_string.str(),
                                                  is_north,
                                                  coordinate.x,
                                                  coordinate.y );
    }

    // Otherwise, error

    // return coordinate
    return output;
}


} // End of GEO Namespace
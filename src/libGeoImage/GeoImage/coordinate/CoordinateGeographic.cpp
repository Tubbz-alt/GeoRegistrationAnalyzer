/**
 * @file    CoordinateGeographic.cpp
 * @author  Marvin Smith
 * @date    9/3/2017
 */
#include "CoordinateGeographic.hpp"

// C++ Libraries
#include <cmath>
#include <iomanip>
#include <sstream>


namespace GEO{


/********************************/
/*          Constructor         */
/********************************/
CoordinateGeographic::CoordinateGeographic()
  :  CoordinateBase(),
     m_longitude_rad(0),
     m_latitude_rad(0),
     m_class_name("CoordinateGeographic")
{
}


/************************************/
/*          Print to String         */
/************************************/
std::string CoordinateGeographic::To_String( const int& indent )const
{
    // Create gap string
    std::string gap(indent, ' ');

    // Create Stringstream
    std::stringstream sin;

    sin << gap << m_class_name << ", Latitude (Deg): ";
    sin << std::fixed << std::setprecision(3) << Get_Latitude_Degrees() << ", Longitude (Deg): ";
    sin << Get_Longitude_Degrees();

    return sin.str();
}


} // End of GEO Namespace

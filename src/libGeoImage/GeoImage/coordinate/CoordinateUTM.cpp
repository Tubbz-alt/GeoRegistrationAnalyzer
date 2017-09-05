/**
 * @file    CoordinateUTM.cpp
 * @author  Marvin Smith
 * @date    9/3/2017
 */
#include "CoordinateUTM.hpp"

// C++ Libraries
#include <iomanip>
#include <sstream>


namespace GEO{


/********************************/
/*          Constructor         */
/********************************/
CoordinateUTM::CoordinateUTM()
  : CoordinateProjectedBase(),
    m_grid_zone("    "),
    m_is_northern(false),
    m_class_name("CoordinateUTM")
{
}


/********************************/
/*          Constructor         */
/********************************/
CoordinateUTM::CoordinateUTM(const std::string& grid_zone,
                             const bool&        is_northern,
                             const double&      easting,
                             const double&      northing)
        : CoordinateProjectedBase(easting,
                                  northing),
          m_grid_zone(grid_zone),
          m_is_northern(is_northern),
          m_class_name("CoordinateUTM")
{
}


/************************************/
/*          Print to String         */
/************************************/
std::string CoordinateUTM::To_String( const int& indent )const
{
    // Create gap string
    std::string gap(indent, ' ');

    // Create Stringstream
    std::stringstream sin;

    sin << gap << m_class_name << ", Latitude (Deg): ";
    sin << std::fixed << std::setprecision(3) << Get_Grid_Zone();
    sin << ", Is-North: " << std::boolalpha << Is_Northern();
    sin << ", Easting (m): " << Get_Easting_Meters() << ", Northing (m): " << Get_Northing_Meters() << std::endl;

    return sin.str();
}


} // End of GEO Namespace

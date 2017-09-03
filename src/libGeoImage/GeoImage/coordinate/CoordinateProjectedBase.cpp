/**
 * @file    CoordinateProjectedBase.cpp
 * @author  Marvin Smith
 * @date    9/3/2017
 */
#include "CoordinateProjectedBase.hpp"


namespace GEO{

/********************************/
/*         Constructor          */
/********************************/
CoordinateProjectedBase::CoordinateProjectedBase()
 : CoordinateBase(),
   m_x(0),
   m_y(0),
   m_class_name("CoordinateProjectedBase")
{
}


/********************************/
/*         Constructor          */
/********************************/
CoordinateProjectedBase::CoordinateProjectedBase( const double& x,
                                                  const double& y )
 : CoordinateBase(),
   m_x(x),
   m_y(y),
   m_class_name("CoordinateProjectedBase")
{
}


} // End of GEO Namespace

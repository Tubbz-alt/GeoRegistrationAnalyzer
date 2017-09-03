/**
 * @file    CoordinateUTM.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEOIMAGE_COORDINATE_COORDINATE_PROJECTED_BASE_HPP
#define GEOIMAGE_COORDINATE_COORDINATE_PROJECTED_BASE_HPP


// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "CoordinateBase.hpp"


namespace GEO{

/**
 * @class CoordinateProjectedBase
 */
class CoordinateProjectedBase : public CoordinateBase
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<CoordinateProjectedBase> ptr_t;


        /**
         * @brief Constructor
         */
        CoordinateProjectedBase();


    protected:

        /// Easting
        double m_x;

        /// Northing
        double m_y;

    private:

        /// Class Name
        std::string m_class_name;

}; // End of CoordinateProjected Class

} // End of GEO Namespace

#endif
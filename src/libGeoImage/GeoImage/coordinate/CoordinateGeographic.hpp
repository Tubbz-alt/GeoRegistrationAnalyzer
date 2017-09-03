/**
 * @file    CoordinateGeographic.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEOIMAGE_COORDINATE_COORDINATE_GEOGRAPHIC_HPP
#define GEOIMAGE_COORDINATE_COORDINATE_GEOGRAPHIC_HPP


// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "CoordinateBase.hpp"


namespace GEO{

/**
 * @class CoordinateGeographic
 */
class CoordinateGeographic : public CoordinateBase
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<CoordinateGeographic> ptr_t;


        /**
         * @brief Constructor
         */
        CoordinateGeographic();


    protected:

        /// Longitude (X)
        double m_longitude;

        /// Latitude (Y)
        double m_latitude;

    private:

        /// Class Name
        std::string m_class_name;

}; // End of CoordinateGeographic Class

} // End of GEO Namespace

#endif
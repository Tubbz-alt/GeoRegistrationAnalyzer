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


        /**
         * @brief Parameterized Constructor
         *
         * @param[in] x
         * @param[in] y
         */
        CoordinateProjectedBase( const double& x,
                                 const double& y );


        /**
         * @brief Get X in Meters
         */
        inline double Get_X()const{
            return m_x;
        }


        /**
         * @brief Get Y in Meters
         */
        inline double Get_Y()const{
            return m_y;
        }

    virtual std::string To_String( const int& indent = 0 ) const = 0;


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
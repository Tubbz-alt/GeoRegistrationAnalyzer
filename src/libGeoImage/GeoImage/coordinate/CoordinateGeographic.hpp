/**
 * @file    CoordinateGeographic.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEOIMAGE_COORDINATE_COORDINATE_GEOGRAPHIC_HPP
#define GEOIMAGE_COORDINATE_COORDINATE_GEOGRAPHIC_HPP


// C++ Libraries
#include <cmath>
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


        /**
         * @brief Get the Latitude in Radians
         */
        inline double Get_Latitude_Radians()const{
            return m_latitude_rad;
        }


        /**
         * @brief Get the Latitude in Degrees
         */
        inline double Get_Latitude_Degrees()const{
            return m_latitude_rad * M_PI / 180.0;
        }


        /**
         * @brief Get the Longitude in Radians
         */
        inline double Get_Longitude_Radians()const{
            return m_longitude_rad;
        }


        /**
         * @brief Get the Longitude in Degrees
         */
        inline double Get_Longitude_Degrees()const{
            return m_longitude_rad * M_PI / 180.0;
        }


        /**
         * @brief Print to String
         */
        virtual std::string To_String( const int& indent = 0 )const;


    protected:

        /// Longitude (X)
        double m_longitude_rad;

        /// Latitude (Y)
        double m_latitude_rad;

    private:

        /// Class Name
        std::string m_class_name;

}; // End of CoordinateGeographic Class

} // End of GEO Namespace

#endif
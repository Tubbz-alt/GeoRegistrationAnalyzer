/**
 * @file    CoordinateUTM.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEOIMAGE_COORDINATE_COORDINATE_UTM_HPP
#define GEOIMAGE_COORDINATE_COORDINATE_UTM_HPP

// C++ Libraries
#include <memory>
#include <string>


// Project Libraries
#include "CoordinateProjectedBase.hpp"


namespace GEO{


/**
 * @class CoordinateUTM
 */
class CoordinateUTM : public CoordinateProjectedBase
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<CoordinateUTM> ptr_t;


        /**
         * @brief Constructor
         */
        CoordinateUTM();


        /**
         * @brief Parameterized Constructor
         */
        CoordinateUTM( const std::string& grid_zone,
                       const bool&        is_northern,
                       const double&      easting,
                       const double&      northing );


        /**
         * @brief Get the Grid Zone
         */
        inline std::string Get_Grid_Zone()const{
            return m_grid_zone;
        }


        /**
         * @brief Check if Northern
         */
        inline bool Is_Northern()const{
            return m_is_northern;
        }


        /**
         * @brief Get the Easting in Meters
         * @return
         */
        inline double Get_Easting_Meters()const{
            return m_x;
        }


        /**
         * @brief Get the Northing in Meters
         * @return
         */
        inline double Get_Northing_Meters()const{
            return m_y;
        }


        /**
         * @brief Print to String
         */
        virtual std::string To_String( const int& indent = 0 )const;



    protected:

        /// Grid Zone
        std::string m_grid_zone;

        /// Is Northern Hemisphere
        bool m_is_northern;

    private:

        /// Class Name
        std::string m_class_name;

}; // End of CoordinateBase Class

} // End of GEO Namespace

#endif
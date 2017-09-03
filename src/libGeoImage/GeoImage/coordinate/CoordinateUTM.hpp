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
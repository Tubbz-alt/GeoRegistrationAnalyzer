/**
 * @file    CoordinateBase.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEOIMAGE_COORDINATE_COORDINATE_BASE_HPP
#define GEOIMAGE_COORDINATE_COORDINATE_BASE_HPP


// C++ Libraries
#include <memory>
#include <string>


namespace GEO{

/**
 * @class CoordinateBase
 */
class CoordinateBase
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<CoordinateBase> ptr_t;


        /**
         * @brief Constructor
         */
        CoordinateBase();


        /**
         * @brief Print to String
         */
        virtual std::string To_String( const int& indent = 0 )const = 0;


    private:

        /// Class Name
        std::string m_class_name;

};  // End of CoordinateBase Class

}  // End of GEO Namespace

#endif
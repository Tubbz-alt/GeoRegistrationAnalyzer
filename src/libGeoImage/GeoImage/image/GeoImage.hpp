/**
 * @file    GeoImage.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEO_IMAGE_IMAGE_GEO_IMAGE_HPP
#define GEO_IMAGE_IMAGE_GEO_IMAGE_HPP

/// C++ Libraries
#include <memory>
#include <string>

namespace GEO {

/**
 * @class GeoImage
 */
class GeoImage
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<GeoImage> ptr_t;


        /**
         * @brief Constructor
         */
        GeoImage();


        /**
         * @brief Parameterized Constructor
         */

    private:

        /// Class Name
        std::string m_class_name;

        /// Memory Pointer


}; // End of GeoImage Class

} // End of GEO Namespace

#endif
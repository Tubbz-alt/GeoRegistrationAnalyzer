/**
 * @file    GDAL_Image_Loader.hpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */
#ifndef IO_GDAL_IMAGE_LOADER_HPP
#define IO_GDAL_IMAGE_LOADER_HPP

// C++ Libraries
#include <string>


// Project Libraries
#include "../assets/local/Asset_Local_Base.hpp"


/**
 * @class GDAL_Image_Loader
 */
class GDAL_Image_Loader
{
    public:

        /**
         * @brief Constructor
         */
        GDAL_Image_Loader();


        /**
         * @brief Load an image and store in asset.
         * @param[in]  pathname
         * @param[out] status
         * @param[out] error_msg
         * @return
         */
        static Asset_Local_Base::ptr_t  Load_Image( const std::string&  pathname,
                                                    bool&               status,
                                                    std::string&        error_msg );


    private:

        /// Class Name
        std::string m_class_name;

};  // End of GDAL_Image_Loader Class


#endif

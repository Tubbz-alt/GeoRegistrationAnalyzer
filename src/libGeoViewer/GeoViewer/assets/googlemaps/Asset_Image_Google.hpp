/**
 * @file    Asset_Image_Google.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef CORE_ASSETS_ASSET_IMAGE_GOOGLE_HPP
#define CORE_ASSETS_ASSET_IMAGE_GOOGLE_HPP

// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "../Asset_Base.hpp"

/**
 * @class Asset_Image_Google
 */
class Asset_Image_Google : public Asset_Base
{
    public:

        /**
         * @brief Constructor
         */
        Asset_Image_Google( const Config_Param& asset_info );


    private:

        /// Class Name
        std::string m_class_name;

}; // End of Asset_Image_Google Class

#endif
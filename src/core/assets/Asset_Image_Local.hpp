/**
 * @file    Asset_Image_Local.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef CORE_ASSETS_ASSET_IMAGE_LOCAL_HPP
#define CORE_ASSETS_ASSET_IMAGE_LOCAL_HPP

// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "Asset_Image_Base.hpp"

/**
 * @class Asset_Image_Local
 */
class Asset_Image_Local : public Asset_Image_Base
{
    public:

        /**
         * @brief Constructor
         */
        Asset_Image_Local();


    private:

        /// Class Name
        std::string m_class_name;

}; // End of Asset_Image_Local Class

#endif
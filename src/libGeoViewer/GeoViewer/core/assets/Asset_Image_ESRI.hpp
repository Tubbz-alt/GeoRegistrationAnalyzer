/**
 * @file    Asset_Image_ESRI.hpp
 * @author  Marvin Smith
 * @date    8/12/2017
 */
#ifndef GEO_VIEWER_CORE_ASSETS_ASSET_IMAGE_ESRI_HPP
#define GEO_VIEWER_CORE_ASSETS_ASSET_IMAGE_ESRI_HPP


// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "Asset_Image_Base.hpp"

/**
 * @class Asset_Image_ESRI
 */
class Asset_Image_ESRI : public Asset_Image_Base
{
    public:

        /**
         * @brief Constructor
         */
        Asset_Image_ESRI();


    private:

        /// Class Name
        std::string m_class_name;

}; // End of Asset_Image_ESRI Class

#endif
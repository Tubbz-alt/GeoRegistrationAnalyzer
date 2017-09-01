/**
 * @file    Asset_Image_Base.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef CORE_ASSETS_ASSET_IMAGE_BASE_HPP
#define CORE_ASSETS_ASSET_IMAGE_BASE_HPP

// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "Asset_Base.hpp"


/**
 * @class Asset_Image_Base
 */
class Asset_Image_Base : public Asset_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Image_Base> ptr_t;


        /**
         * @brief Constructor
         */
        Asset_Image_Base(const Config_Param& asset_info);


    private:

        /// Class Name
        std::string m_class_name;

}; // End of Asset_Image_Base_Class

#endif
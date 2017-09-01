/**
 * @file    Image_Asset_Builder.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef CORE_ASSETS_IMAGE_ASSET_BUILDER_HPP
#define CORE_ASSETS_IMAGE_ASSET_BUILDER_HPP

// C++ Libraries
#include <string>
#include <vector>


// Project Libraries
#include "Asset_Base.hpp"
#include "../core/Config_Param.hpp"


/**
 * @brief Image_Asset_Builder
 */
class Image_Asset_Builder
{
    public:

        /**
         * @brief Create Image Asset
         * @param project_info
         * @return
         */
        static Asset_Base::ptr_t Create( const Config_Param& project_info );


        /**
         * @brief Load a path file.
         * @param pathname
         * @param success
         * @return
         */
        static std::vector<std::string> Load_Path_File( const std::string& pathname,
                                                        bool&              success,
                                                        std::string&       error_msg );


};

#endif
/**
 * @file    Asset_Generator_Base.hpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#ifndef GEO_VIEWER_CORE_ASSETS_ASSET_GENERATOR_BASE_HPP
#define GEO_VIEWER_CORE_ASSETS_ASSET_GENERATOR_BASE_HPP

// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "Asset_Base.hpp"
#include "../core/Config_Param.hpp"
#include "../core/Status.hpp"


/**
 * @class Asset_Generator_Config_Base
 */
class Asset_Generator_Config_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Generator_Config_Base> ptr_t;

        /**
         * @brief Constructor
         */
        Asset_Generator_Config_Base();


    private:

        /// Class Name
        std::string m_class_name;

};

/**
 * @class Asset_Generator_Base
 */
class Asset_Generator_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Generator_Base> ptr_t;


        /**
         * @brief Constructor
         */
        Asset_Generator_Base( Asset_Generator_Config_Base::ptr_t config );


        /**
         * @brief Check if path is valid for this generator
         */
        virtual bool Is_Valid_Asset_Path( const std::string& asset_path,
                                          std::string&       error_message ) = 0;


        /**
         * @brief Load Asset Information
         */
        virtual Config_Param Load_Asset_Info( const std::string&  pathname,
                                              Status&             status ) = 0;


        /**
         * @brief Load the Asset
         */
        virtual Asset_Base::ptr_t Load_Asset( const Config_Param& asset_info,
                                              Status&             status ) = 0;


        /**
         * @brief Get Generator Name
         */
        virtual std::string Get_Generator_Name()const = 0;


    private:

        /// Class Name
        std::string m_class_name;

        /// Configuration
        Asset_Generator_Config_Base::ptr_t m_config;
};

#endif
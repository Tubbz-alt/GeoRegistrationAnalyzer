/**
 * @file    Asset_Loader.hpp
 * @author  Marvin Smith
 * @date    8/12/2017
 */
#ifndef GEO_VIEWER_CORE_ASSETS_ASSET_LOADER_HPP
#define GEO_VIEWER_CORE_ASSETS_ASSET_LOADER_HPP

// Project Libraries
#include "../Config_Param.hpp"
#include "../Status.hpp"
#include "Asset_Base.hpp"
#include "Asset_Generator_Base.hpp"


// C++ Libraries
#include <string>

/**
 * @class Asset_Loader
 */
class Asset_Loader
{

    public:


        /**
         * @brief Register Asset Generator
         */
        static void Register_Asset_Generator( Asset_Generator_Base::ptr_t asset_generator );


        /**
         * @brief Initialize Asset Loader
         */
        static void Initialize( Status& status );


        /**
         * @brief Finalize Asset Loader
         */
        static void Finalize( Status& status );

        /**
         * @brief Load Asset Information
         */
        static Config_Param Load_Asset_Info( const std::string&  pathname,
                                             Status&             status );


        /**
         * @brief Load asset
         * @param asset_info
         * @param success
         * @param error_msg
         * @return
         */
        static Asset_Base::ptr_t Load_Asset( const Config_Param& asset_info,
                                             Status&             status );

    private:

        /**
         * @brief Get Instance
         */
        static std::shared_ptr<Asset_Loader>& Get_Instance();


        /**
         * @brief Default Constructor
         */
        Asset_Loader();


        /**
         * @brief Deleted Copy-Constructor
         */
        Asset_Loader( const Asset_Loader& rhs ) = delete;


        /**
         * @brief Deleted Assignment Operator
         */
        void operator = ( const Asset_Loader& rhs ) = delete;


        /// Class Name
        std::string m_class_name;

        /// List of Generators
        std::vector<Asset_Generator_Base::ptr_t> m_generators;

}; // End of Asset_Loader Class

#endif
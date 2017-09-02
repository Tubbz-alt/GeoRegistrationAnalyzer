/**
 * @file    Asset_Generator_Local.hpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#ifndef GEO_VIEWER_CORE_ASSETS_ASSET_GENERATOR_LOCAL_HPP
#define GEO_VIEWER_CORE_ASSETS_ASSET_GENERATOR_LOCAL_HPP


// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "../Asset_Generator_Base.hpp"
#include "../core/Status.hpp"


/**
 * @class Asset_Generator_Config_Local
 */
class Asset_Generator_Config_Local : public Asset_Generator_Config_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Generator_Config_Local> ptr_t;

        /**
         * @brief Constructor
         */
        Asset_Generator_Config_Local();


    private:

        /// Class Name
        std::string m_class_name;

};

/**
 * @class Asset_Generator_Local
 */
class Asset_Generator_Local : public Asset_Generator_Base
{
    public:

        /**
         * @brief Constructor
         */
        Asset_Generator_Local( Asset_Generator_Config_Base::ptr_t config );


        /**
         * @brief Check if path is valid for this generator
         *
         * @param[in] asset_path
         * @param[out] error_message
         *
         * @return True if valid asset, false otherwise.
         */
        virtual bool Is_Valid_Asset_Path( const std::string& asset_path,
                                          std::string&       error_message );


        /**
         * @brief Load Asset Information
         *
         * @param[in] pathname
         * @param[out] status
         *
         * @return Asset information
         */
        virtual Config_Param Load_Asset_Info( const std::string&  pathname,
                                              Status&             status );


        /**
         * @brief Load the Asset
         *
         * @param[in] asset_info
         * @param[out] status
         *
         * @return Newly loaded asset.
         */
        virtual Asset_Base::ptr_t Load_Asset( const Config_Param& asset_info,
                                              Status&             status );


        /**
         * @brief Get Generator Name
         */
        inline virtual std::string Get_Generator_Name()const{
            return "esri";
        }


    private:

        /// Class Name
        std::string m_class_name;

}; // End of Asset_Generator_Local Class

#endif
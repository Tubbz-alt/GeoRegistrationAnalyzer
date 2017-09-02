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
#include "../Asset_Image_Base.hpp"
#include "../../core/Config_Param.hpp"
#include "../../core/Status.hpp"

// ESRI Libraries
#include <Raster.h>
#include <RasterLayer.h>


/**
 * @class Asset_Image_ESRI
 */
class Asset_Image_ESRI : public Asset_Image_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Image_ESRI> ptr_t;

        /**
         * @brief Constructor
         */
        Asset_Image_ESRI( const Config_Param& asset_info );


        /**
         * @brief Check if Asset Loaded
         */
        inline bool Asset_Loaded()const{
            return m_asset_loaded;
        }


        /**
         * @brief Load Asset
         */
        void Load_Asset( Status& status );

        /**
         * Get the embedded raster object.
         *
         * @return
         */
        inline Esri::ArcGISRuntime::Raster* Get_Raster()const{
            return m_raster;
        }


        /**
         * @brief Print to logging string.
         * @param offset
         * @return
         */
        virtual std::string To_Log_String( const int& offset = 0 )const;

    private:

        /// Class Name
        std::string m_class_name;

        /// Asset Loaded Check
        bool m_asset_loaded;

        /// Internal Raster
        Esri::ArcGISRuntime::Raster* m_raster;

}; // End of Asset_Image_ESRI Class

#endif
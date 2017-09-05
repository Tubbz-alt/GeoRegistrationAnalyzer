/**
 * @file    Asset_Local_Base.hpp
 * @author  Marvin Smith
 * @date    9/5/2017
 */
#ifndef CORE_ASSETS_ASSET_LOCAL_BASE_HPP
#define CORE_ASSETS_ASSET_LOCAL_BASE_HPP

// C++ Libraries
#include <memory>
#include <string>

// Qt Libraries
#include <QPainter>

// Project Libraries
#include "../Asset_Base.hpp"

/**
 * @class Asset_Local_Base
 */
class Asset_Local_Base : public Asset_Base
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Asset_Local_Base> ptr_t;


        /**
         * @brief Single Constructor
         */
        Asset_Local_Base( const Config_Param& asset_info );


        /**
         * @brief Destructor
         */
        virtual ~Asset_Local_Base();
        

        /**
         * @brief Render the Layer
         *
         * @param[in]  painter
         * @param[in]  scene_view
         * @param[in]  current_timestamp
         * @param[out] status
         */
        virtual void Render_Layer( QPainter&             painter,
                                   SceneViewBase::ptr_t  scene_view,
                                   const double&         current_timestamp,
                                   Status&               status ) = 0;


    private:

        /// Class Name
        std::string m_class_name;


}; // End of Asset_Local_Base Class

#endif

/**
 * @file    Scene_Context.hpp
 * @author  Marvin Smith
 * @date    9/5/2017
 */
#ifndef GEO_VIEWER_GUI_LOCAL_SCENE_CONTEXT_HPP
#define GEO_VIEWER_GUI_LOCAL_SCENE_CONTEXT_HPP

// Qt Libraries
#include <QPainter>

// GeoViewer Libraries
#include "../../../assets/local.hpp"
#include "../../../core/System_Configuration.hpp"


// C++ Libraries
#include <memory>
#include <string>


namespace LOCAL{

/**
 * @class Scene_Context
 */
class Scene_Context
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<Scene_Context> ptr_t;

        /**
         * @brief Constructor
         */
        Scene_Context( const std::string&           base_config_profile,
                       System_Configuration::ptr_t  sys_config,
                       Asset_Local_Base::ptr_t      asset );


        /**
         * @brief Render Layer to Painter
         */
        virtual void Paint_Scene( QPainter&                  painter,
                                  Status&                    status );

        
        /**
         * @brief Update Scene Pixel Data
         * 
         * @param scene_view 
         * @param current_timestamp 
         * @param status 
         */
        virtual void Update_Scene( SceneViewBase::ptr_t  scene_view,
                                   const double&         current_timestamp,
                                   Status&               status );

    private:

        /// Class Name
        std::string m_class_name;

        /// Base Config Profile
        std::string m_base_config_profile;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Registered Asset
        Asset_Local_Base::ptr_t m_asset;

}; // End of Scene_Context Class



} // End of LOCAL Namespace


#endif
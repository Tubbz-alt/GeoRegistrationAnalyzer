/**
 * @file    RenderWorker.hpp
 * @author  Marvin Smith
 * @date    9/6/2017
 */
#ifndef LIB_GEO_VIEWER_GUI_LOCAL_RENDER_WORKER_HPP
#define LIB_GEO_VIEWER_GUI_LOCAL_RENDER_WORKER_HPP

// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "Scene_Context.hpp"
#include "../../../core/System_Configuration.hpp"


namespace LOCAL{

/**
 * @class RenderWorker
 */
class RenderWorker
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<RenderWorker> ptr_t;

        /**
         * @brief Rendering Worker
         */
        RenderWorker( const std::string&          base_config_profile,
                      System_Configuration::ptr_t sys_config );

    private:

        /// Class Name
        std::string m_class_name;

        /// Base Configuration Profile Node
        std::string m_base_config_profile;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// List of Scene Context Objects
        std::vector<Scene_Context::ptr_t> m_scene_render_list;

}; // End of RenderWorker Class


} // End of LOCAL Namespace

#endif
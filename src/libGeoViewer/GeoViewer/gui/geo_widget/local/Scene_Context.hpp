/**
 * @file    Scene_Context.hpp
 * @author  Marvin Smith
 * @date    9/5/2017
 */
#ifndef GEO_VIEWER_GUI_LOCAL_SCENE_CONTEXT_HPP
#define GEO_VIEWER_GUI_LOCAL_SCENE_CONTEXT_HPP

// GeoViewer Libraries
#include "../../../assets.hpp"

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
        Scene_Context( Asset_Local_Base::ptr_t asset );


    private:

        /// Class Name
        std::string m_class_name;

        /// Registered Asset
        Asset_Local_Base::ptr_t m_asset;

}; // End of Scene_Context Class

} // End of LOCAL Namespace


#endif
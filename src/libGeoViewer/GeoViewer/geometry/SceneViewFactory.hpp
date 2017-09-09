/**
 * @file    SceneViewFactory.hpp
 * @author  Marvin Smith
 * @date    9/8/2017
 */
#ifndef LIB_GEO_VIEWER_GEOM_SCENE_VIEW_FACTORY_HPP
#define LIB_GEO_VIEWER_GEOM_SCENE_VIEW_FACTORY_HPP


// Project Libraries
#include "SceneViewBase.hpp"

/**
 * @class SceneViewFactory
 */
class SceneViewFactory
{
    public:

        /**
         * @brief Create new scene view
         */
        static SceneViewBase::ptr_t  Create( const OGRSpatialReference& projection,
                                             Status&                    status );



}; // End of SceneViewFactory Class

#endif
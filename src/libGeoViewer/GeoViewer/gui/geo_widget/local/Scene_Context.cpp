/**
 * @file    Scene_Context.cpp
 * @author  Marvin Smith
 * @date    9/5/2017
 */
#include "Scene_Context.hpp"


/**************************************/
/*          Render the Scene          */
/**************************************/
void Scene_Context::Render_Layer( QPainter&                  painter,
                                  GEO::SceneViewBase::ptr_t  scene_view,
                                  const double&              current_timestamp,
                                  Status&                    status )
{
    // Initialize the status
    status = Status::SUCCESS();

}
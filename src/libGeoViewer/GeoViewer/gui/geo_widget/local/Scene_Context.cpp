/**
 * @file    Scene_Context.cpp
 * @author  Marvin Smith
 * @date    9/5/2017
 */
#include "Scene_Context.hpp"

// Project Libraries
#include "../../../log/System_Logger.hpp"


namespace LOCAL {

/**************************************/
/*            Constructor             */
/**************************************/
Scene_Context::Scene_Context(Asset_Local_Base::ptr_t asset)
  : m_class_name("Scene_Context"),
    m_asset(asset)
{

}


/**************************************/
/*          Render the Scene          */
/**************************************/
void Scene_Context::Render_Layer(QPainter&                  painter,
                                 GEO::SceneViewBase::ptr_t  scene_view,
                                 const double&              current_timestamp,
                                 Status&                    status)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize the status
    status = Status::SUCCESS();

    // 


    // Log Exit
    LOG_CLASS_EXIT();
}


} // End of LOCAL Namespace
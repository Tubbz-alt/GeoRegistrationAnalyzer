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
Scene_Context::Scene_Context(const std::string&           base_config_profile,
                             System_Configuration::ptr_t  sys_config,
                             Asset_Local_Base::ptr_t      asset)
  : m_class_name("Scene_Context"),
    m_base_config_profile(base_config_profile),
    m_sys_config(sys_config),
    m_asset(asset)
{

}


/**************************************/
/*          Render the Scene          */
/**************************************/
void Scene_Context::Paint_Scene( QPainter&  painter,
                                 Status&    status)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize the status
    status = Status::SUCCESS();

    // 


    // Log Exit
    LOG_CLASS_EXIT();
}


/***************************************/
/*          Update the Scene           */
/***************************************/
void Scene_Context::Update_Scene( SceneViewBase::ptr_t scene_view,
                                  const double&        current_timestamp,
                                  Status&              status)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize the status
    status = Status::SUCCESS();

    LOG_CLASS_TRACE("Scene: " + scene_view->To_Log_String());
    LOG_CLASS_TRACE("Time: " + std::to_string(current_timestamp));

    // Check the current bounds of the scene
    //scene_view->Get_Scene_Bou


    // Log Exit
    LOG_CLASS_EXIT();
}

} // End of LOCAL Namespace
/**
 * @file    RenderWorker.cpp
 * @author  Marvin Smith
 * @date    9/6/2017
 */
#include "RenderWorker.hpp"

// Project Libraries
#include "../../../log.hpp"


namespace LOCAL{


/**********************************/
/*          Constructor           */
/**********************************/
RenderWorker::RenderWorker( const std::string&          base_config_profile,
                            System_Configuration::ptr_t sys_config)
  : m_class_name("RenderWorker"),
    m_base_config_profile(base_config_profile),
    m_sys_config(sys_config),
    m_current_scene(nullptr),
    m_current_timestamp(0)
{
}

/***********************************************/
/*          Insert_Scene_Context_Top           */
/***********************************************/
void RenderWorker::Insert_Scene_Context_Top(Scene_Context::ptr_t new_context,
                                            Status&              status )
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize the status
    status = Status::SUCCESS();

    // Check the context
    if( new_context == nullptr )
    {
        status.Append(StatusType::FAILURE,
                      StatusReason::UNINITIALIZED,
                      "New Scene-Context is null");
    }

    // Add to list
    if( status.Not_Failure())
    {
        m_scene_render_list.push_back(new_context);
    }

    // Log Exit
    LOG_CLASS_EXIT();
}


/************************************/
/*          Paint the Scene         */
/************************************/
void RenderWorker::Paint_Scene(QPainter &painter)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize Status
    Status status = Status::SUCCESS();
    Status temp_status;
    bool complete_flag = true;

    // Check if full scene re-render required
    if(true)
    {
        // Iterate over layers
        for( auto scene_context : m_scene_render_list )
        {
            scene_context->Paint_Scene( painter,
                                        temp_status);
            status.Append(temp_status);
        }
    }

    // Check status
    if( status.Not_Success() )
    {
        LOG_CLASS_ERROR( status.To_Log_String());
        complete_flag = false;
    }

    // Log Exit
    LOG_CLASS_EXIT();
}



/*********************************/
/*          Render Scene         */
/*********************************/
void RenderWorker::Update_Scene()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize Status
    Status status = Status::SUCCESS();
    Status temp_status;
    bool complete_flag = true;

    // Check if full scene re-render required
    if(true)
    {
        // Iterate over layers
        for( auto scene_context : m_scene_render_list )
        {
            scene_context->Update_Scene(m_current_scene,
                                        m_current_timestamp,
                                        temp_status);
            status.Append(temp_status);
        }
    }

    // Check status
    if( status.Not_Success() )
    {
        LOG_CLASS_ERROR( status.To_Log_String());
        complete_flag = false;
    }

    emit Update_Scene_Complete(complete_flag);

    // Log Exit
    LOG_CLASS_EXIT();
}


} // End of LOCAL Namespace

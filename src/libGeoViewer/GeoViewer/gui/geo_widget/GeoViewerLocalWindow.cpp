/**
 * @file    GeoViewerLocalWindow.cpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#include "GeoViewerLocalWindow.hpp"

// QT Libraries
#include <QPainter>


// Project Libraries
#include "../../assets/Asset_Manager.hpp"
#include "../../assets/local/Asset_Local_Base.hpp"
#include "../../log.hpp"


/********************************/
/*          Constructor         */
/********************************/
GeoViewerLocalWindow::GeoViewerLocalWindow( const std::string&          base_config_profile,
                                            System_Configuration::ptr_t sys_config,
                                            QWidget*                    parent)
  : QFrame(parent),
    m_class_name("GeoViewerLocalWindow"),
    m_sys_config(sys_config),
    m_base_config_profile(base_config_profile),
    m_current_timestamp(0)
{
    // Build the Render Worker
    m_render_worker = std::make_shared<LOCAL::RenderWorker>(base_config_profile,
                                                            sys_config);

    // Initialize the Frame
    Initialize_Frame();

    // Connect signals and slots
    connect(this, SIGNAL(Request_Update_Scene()),
            this, SLOT(Update_Scene()));

}


/************************************/
/*          Import new asset        */
/************************************/
void GeoViewerLocalWindow::Import_Asset(int asset_id)
{
    // Log Entry
    LOG_CLASS_TRACE("Start of Method. New ID: " + std::to_string(asset_id));

    // Init Status
    Status status = Status::SUCCESS();
    Status temp_status;

    // Get the asset
    Asset_Base::ptr_t asset = Asset_Manager::Query_Asset(asset_id, status );

    if( asset == nullptr || !status.Not_Failure() )
    {
        LOG_CLASS_ERROR("Unable to Import Asset. " + status.To_Log_String());
    }

    // If no errors, then continue
    if( status.Not_Failure() )
    {
        // Cast to Local Type
        Asset_Local_Base::ptr_t local_asset = std::dynamic_pointer_cast<Asset_Local_Base>(asset);

        // Add asset to the render worker
        m_render_worker->
        m_scene_rendering_list.push_back(std::make_shared<LOCAL::Scene_Context>(local_asset));

        // Notify to Update Scene
        emit Request_Update_Scene();
    }

    // Log Exit
    LOG_CLASS_EXIT();
}


/*********************************/
/*          Render Scene         */
/*********************************/
void GeoViewerLocalWindow::Update_Scene()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize Status
    Status status = Status::SUCCESS();
    Status temp_status;

    // Check if full scene re-render required
    if(true)
    {
        // Iterate over layers
        for( auto scene_context : m_scene_rendering_list )
        {
            scene_context->second->Update_Scene(m_current_scene,
                                                m_current_timestamp,
                                                temp_status);
            status.Append(temp_status);
        }
    }

    // Check status
    if( status.Not_Success() )
    {
        LOG_CLASS_ERROR( status.To_Log_String());
    }


    // Log Exit
    LOG_CLASS_EXIT();
}


/********************************************/
/*          Overridden Paint Event          */
/********************************************/
void GeoViewerLocalWindow::paintEvent(QPaintEvent *event)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Create a painter
    QPainter painter(this);

    // Status
    Status status = Status::SUCCESS();
    Status temp_status;

    // If no Scenes Loaded, show boilerplate
    if( m_scene_rendering_list.size() <= 0 )
    {
        // Set the background color
        painter.setBackground(QBrush(QColor::fromRgb(0,255,0)));

        painter.drawText(rect(), Qt::AlignCenter, "No Layers Imported");
    }

    // Iterate over each layer (in order)
    else
    {
        for( auto scene_context : m_scene_rendering_list )
        {
            scene_context.second->Render_Layer( painter,
                                                m_current_scene,
                                                m_current_timestamp,
                                                temp_status );
            status.Append(temp_status);
        }
    }

    // Check status
    if( status.Not_Success() )
    {
        LOG_CLASS_ERROR( status.To_Log_String());
    }

    // Log Exit
    LOG_CLASS_EXIT();
}


/****************************************************/
/*          Initialize QFrame Components            */
/****************************************************/
void GeoViewerLocalWindow::Initialize_Frame()
{
    setAutoFillBackground(true);
    setFocusPolicy( Qt::StrongFocus );
}
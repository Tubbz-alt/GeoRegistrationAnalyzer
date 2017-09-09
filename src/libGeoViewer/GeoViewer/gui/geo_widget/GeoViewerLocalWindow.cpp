/**
 * @file    GeoViewerLocalWindow.cpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#include "GeoViewerLocalWindow.hpp"

// QT Libraries
#include <QPainter>
#include <QMessageBox>
#include <QGridLayout>
#include <QWidget>


// Project Libraries
#include "../../assets/Asset_Manager.hpp"
#include "../../assets/local/Asset_Local_Base.hpp"
#include "../../log.hpp"

// GDAL Libraries
#include <cpl_conv.h>


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
    m_current_timestamp(0),
    m_current_projection(""),
    m_projection_loaded(false)
{
    // Build the Render Worker
    m_render_worker = std::make_shared<LOCAL::RenderWorker>(base_config_profile,
                                                            sys_config);

    // Initialize the Frame
    Initialize_Frame();

    // Attach Rendering Worker to thread
    m_render_worker->moveToThread(&m_render_thread);

    ////////////////////////////////////////////////
    //   Connect signals and slots

    // When we need to redraw the scene, this will cause the Render-Worker to start
    connect(this, SIGNAL(Request_Update_Scene()),
            m_render_worker.get(), SLOT(Update_Scene()),
            Qt::QueuedConnection );

    // When the RenderWorker finished drawing the scene, this will notify us to update the frame
    connect(m_render_worker.get(), SIGNAL(Update_Scene_Completed(bool)),
            this, SLOT(Update_Scene_Completed(bool)));

    // Start rendering thread
    m_render_thread.start();
}


/********************************/
/*          Destructor          */
/********************************/
GeoViewerLocalWindow::~GeoViewerLocalWindow()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Stop the rendering thread
    m_render_thread.exit();

    // Wait for thread to finish
    m_render_thread.wait(3000);

    // Check worker
    if( m_render_worker ){
        m_render_worker.reset();
    }

    // Log Exit
    LOG_CLASS_EXIT();
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

    // Misc Vars
    bool match_found;
    std::string tempstr;
    LOCAL::Scene_Context::ptr_t new_scene_context;


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

        // Create new scene context
        new_scene_context = std::make_shared<LOCAL::Scene_Context>(m_base_config_profile,
                                                                   m_sys_config,
                                                                   local_asset);

        // Check if we have scene created yet
        if (m_current_scene == nullptr)
        {
            // We need to create the scene
            LOG_CLASS_TRACE("Scene does not exist, creating based on new asset.");

            auto default_projection = Get_Default_Projection();
            m_current_scene = local_asset->Create_Scene_View(default_projection,
                                                             temp_status);
            status.Append(temp_status);
        }

            // Otherwise, if the asset wants us to zoom to feature
        else
        {
            tempstr = local_asset->Get_Asset_Info().Query_KV_Pair("asset.local.scene.focus_on_load",
                                                                  match_found);
            // If we need to fly to asset on completion, then
            if (match_found && tempstr == "true")
            {
                LOG_CLASS_TRACE("Building new scene, centered on asset.");
            }

                // Otherwise, keep current scene
            else
            {
                LOG_CLASS_TRACE("Keeping Current Scene");
            }
        }
    }

    // Add asset to the render worker
    if( status.Not_Failure() )
    {
        m_render_worker->Insert_Scene_Context_Top( new_scene_context,
                                                   temp_status );
        status.Append(temp_status);
    }

    // If no errors, then continue
    if( status.Not_Failure() )
    {
        LOG_CLASS_DEBUG("Added new scene. Requesting Update.");

        // Notify to Update Scene
        emit Request_Update_Scene();
    }
    else
    {
        LOG_CLASS_ERROR("Could not add new scene. Details: " + status.To_Log_String());
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
    if( m_render_worker->Get_Scene_Count() <= 0 )
    {
        // Set the background color
        painter.setBackground(QBrush(QColor::fromRgb(0,255,0)));

        painter.drawText(rect(), Qt::AlignCenter, "No Layers Imported");
    }

    // Iterate over each layer (in order)
    else
    {
        m_render_worker->Paint_Scene(painter);
    }

    // Check status
    if( status.Not_Success() )
    {
        LOG_CLASS_ERROR( status.To_Log_String());
    }

    // Log Exit
    LOG_CLASS_EXIT();
}


/************************************/
/*        Resize the Window         */
/************************************/
void GeoViewerLocalWindow::resizeEvent(QResizeEvent *event)
{
    // Skip and log error if no scene
    if( m_current_scene != nullptr )
    {
        int width_multiple = 8;
        int height_multiple = 2;

        // Force the width of this window to be a multiple of 8
        // pixels.  This improves graphics efficiency, and makes
        // the drawing actually work across a remote X display.

        int allowed_width = width_multiple * (width() / width_multiple);
        int allowed_height = height_multiple * (height() / height_multiple);

        if ((allowed_height != m_current_scene->Get_Draw_Size().height) ||
            (allowed_width != m_current_scene->Get_Draw_Size().width))
        {
            // Create a new drawing rectangle
            cv::Size new_size(allowed_width, allowed_height);
            m_current_scene->Set_Draw_Size(new_size);

            // Notify viewer that image bounds have changed
            Bounds_Changed();

            // defer the actual redraw until we've settled down a little
            //m_redraw_timer.start(300);
            //m_redraw_timer.setSingleShot(true);


            //m_initialized = true;

        }
    }
    else
    {
        LOG_CLASS_DEBUG("Skipping Resize as no scene available.");
    }

    QWidget::resizeEvent(event); // pass the resize event up to the parent
}


/****************************************/
/*        Update Scene Completed        */
/****************************************/
void GeoViewerLocalWindow::Update_Scene_Completed(bool success)
{
    // Log Entry
    LOG_CLASS_TRACE("Start of Method: Success: " + std::to_string(success));

    // Lock the mutex
    QMutexLocker lock(&m_paint_mutex);

    // Process Failure
    if( !success )
    {
        // @todo  Need to store the error inside the render-worker.  Then allow this method to query that status obj.
        QMessageBox qmsg(QMessageBox::Warning, "Error",
                         QString("Error while updating scene."),
                         QMessageBox::Ok);
        QSpacerItem *horizontalSpacer = new QSpacerItem(800, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
        QGridLayout *layout = (QGridLayout *) qmsg.layout();
        layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
        //qmsg.setDetailedText(renderWorker->m_exceptionDetails.c_str());
        qmsg.exec();
    }

    //  Update the scene
    update();

    // @todo  Update overlay widgets here

    // Log Exit
    LOG_CLASS_EXIT();
}


/********************************************/
/*          Handling BOunds Changed         */
/********************************************/
void GeoViewerLocalWindow::Bounds_Changed()
{
    /*
    // Update the SceneView Object
    m_current_scene->Update_Transforms();

    m_xformUtm2Pix.reset();
    if(m_viewType == ViewTransformer::VIEWTYPE_PTZ) {
        double fov = m_res*m_drawSize.width()*PI/180.0f;
        double view_size_x = 2.0 * tan((double)fov/2.0f);
        m_xformUtm2Pix.translate(m_drawSize.width()/2., m_drawSize.height()/2.);
        m_xformUtm2Pix.scale(m_drawSize.width() / view_size_x, -m_drawSize.width() / view_size_x);
    } else if(m_viewType == ViewTransformer::VIEWTYPE_PANO) {
        m_xformUtm2Pix.translate(m_drawSize.width()/2., m_drawSize.height()/2.);
        m_xformUtm2Pix.scale(1.0/m_res, -1.0/m_res);
        m_xformUtm2Pix.translate(-m_utmCenter.x(), -m_utmCenter.y());
    } else if(m_viewType == ViewTransformer::VIEWTYPE_CYLINDER) {
        m_xformUtm2Pix.translate(m_drawSize.width()/2., m_drawSize.height()/2.);
        m_xformUtm2Pix.scale(1.0/m_res, -1.0/m_res);
        m_xformUtm2Pix.translate(-m_utmCenter.x(), -m_utmCenter.y());
    } else if(m_viewType == ViewTransformer::VIEWTYPE_FISHEYE) {
        m_xformUtm2Pix.translate(m_drawSize.width()/2., m_drawSize.height()/2.);
        m_xformUtm2Pix.scale(m_drawSize.width() / 2.0, -m_drawSize.height() / 2.0);
    } else { // ortho and vcam the same
        m_xformUtm2Pix.reset();
        m_xformUtm2Pix.translate(m_drawSize.width()/2., m_drawSize.height()/2.);
        m_xformUtm2Pix.scale(1.0/m_res, -1.0/m_res);
        m_xformUtm2Pix.translate(-m_utmCenter.x(), -m_utmCenter.y());
    }

    boost::shared_ptr< Condor > r = m_sessionData->GetPrimaryLayer();

    if(m_viewType == ViewTransformer::VIEWTYPE_VCAM) {
        SensorModelTransformer::ptr_t t = r->GetTransformer(m_frameNum, true);
        Pose p = t->GetBasePose();
        double yaw, pitch, roll;
        p.rot.ConvertToEulerZXZ(yaw, pitch, roll);
        m_vt.reset(new ViewTransformerProjectiveView(-yaw, pitch, -roll));
        m_vt->SetOffset(p.x, p.y, p.z);
    } else if(m_viewType == ViewTransformer::VIEWTYPE_ORTHO)
        m_vt.reset(new ViewTransformerUTM(m_utmZone, m_utmCenter.x(), m_utmCenter.y()));
    else if(m_viewType == ViewTransformer::VIEWTYPE_PTZ) {
        double el = m_utmCenter.y()*PI/180.0f;
        double az = m_utmCenter.x()*PI/180.0f;
        SensorModelTransformer::ptr_t t = r->GetTransformer(m_frameNum, true);
        Pose p = t->GetBasePose();
        m_vt.reset(new ViewTransformerProjectiveView(az, el, 0.0));
        m_vt->SetOffset(p.x, p.y, p.z);
    } else if(m_viewType == ViewTransformer::VIEWTYPE_CYLINDER) {
        SensorModelTransformer::ptr_t t = r->GetTransformer(m_frameNum, true);
        Pose p = t->GetBasePose();
        m_vt.reset(new ViewTransformerCylinderView());
        m_vt->SetOffset(p.x, p.y, p.z);
    } else if(m_viewType == ViewTransformer::VIEWTYPE_FISHEYE) {
        SensorModelTransformer::ptr_t t = r->GetTransformer(m_frameNum, true);
        Pose p = t->GetBasePose();
        m_vt.reset(new ViewTransformerFisheye);
        m_vt->SetOffset(p.x, p.y, p.z);
    } else if(m_viewType == ViewTransformer::VIEWTYPE_PANO) {
        //SensorModelTransformer::ptr_t t = r->GetTransformer(m_frameNum, true);
        //Pose p = t->GetBasePose();
        Pose p;
        p.x = 304555.2;
        p.y = 3775134.8;
        p.z = 15.17;
        sprintf(p.utmZone, "11S");
        m_vt.reset(new ViewTransformerSphericalView());
        m_vt->SetOffset(p.x, p.y, p.z);
    }

    m_xformPix2Utm = m_xformUtm2Pix.inverted();

    updateOverlayWidgets();

    Box2d pixbox(0, 0, m_drawSize.width(), m_drawSize.height());
    Polygon2d imagePoly = pixbox.ConvertToPolygon2d(5);
    QTransform &q=m_xformPix2Utm;
    CMatrix3x3 raster2view(q.m11(), q.m21(), q.m31(),
                           q.m12(), q.m22(), q.m32(),
                           q.m13(), q.m23(), q.m33());
    Polygon2d viewPoly = imagePoly.Transform(raster2view);
    viewPoly.correct();

    double res = m_res;
    QPointF sizePt(m_drawSize.width()*m_res, m_drawSize.height()*m_res);
    QRectF bounds(m_utmCenter - sizePt/2, m_utmCenter + sizePt/2);
    emit boundsChanged(bounds);
    emit regionChanged(viewPoly, m_vt);*/
}


/************************************************/
/*          Get the default projection          */
/************************************************/
OGRSpatialReference GeoViewerLocalWindow::Get_Default_Projection()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Create projection object
    OGRSpatialReference def_projection;

    // Query system configuration
    bool match_found;
    std::string proj_str = m_sys_config->Query_Config_Param(m_base_config_profile + ".projection",
                                                            match_found );

    // If not found, throw error
    if( !match_found )
    {
        QMessageBox qmsg(QMessageBox::Warning, "Error",
                         QString("No Default Projection info found in options.cfg."),
                         QMessageBox::Ok);
        QSpacerItem *horizontalSpacer = new QSpacerItem(800, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
        QGridLayout *layout = (QGridLayout *) qmsg.layout();
        layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());
        //qmsg.setDetailedText(renderWorker->m_exceptionDetails.c_str());
        qmsg.exec();

        proj_str = "EPSG:32613";
    }

    else
    {
        // Parse the string
        int epsg_code = std::stoi(proj_str.substr(5));
        def_projection.importFromEPSG(epsg_code);

        char* buffer;
        def_projection.exportToPrettyWkt(&buffer);
        LOG_CLASS_TRACE("Default Projection Constructed.  " + std::string(buffer));

        CPLFree(buffer);
    }


    // Log Exit
    LOG_CLASS_EXIT();

    return def_projection;
}

/****************************************************/
/*          Initialize QFrame Components            */
/****************************************************/
void GeoViewerLocalWindow::Initialize_Frame()
{
    setAutoFillBackground(true);
    setFocusPolicy( Qt::StrongFocus );
}
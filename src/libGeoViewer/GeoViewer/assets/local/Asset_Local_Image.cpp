/**
 * @file    Asset_Local_Image.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "Asset_Local_Image.hpp"

// Project Libraries
#include "../../log.hpp"
#include "../../geometry/SceneViewUTM.hpp"
#include "../../io/GDAL_Image_Loader.hpp"


// GeoImage Libraries
#include <GeoImage/coordinate/CoordinateFactory.hpp>

/*********************************/
/*          Constructor          */
/*********************************/
Asset_Local_Image::Asset_Local_Image( const Config_Param&  asset_info )
  : Asset_Local_Base(asset_info),
    m_class_name("Asset_Local_Image"),
    m_working_image(cv::Size(1,1),CV_8UC4)
{

}


/********************************/
/*          Constructor         */
/********************************/
Asset_Local_Image::Asset_Local_Image(const Config_Param&             asset_info,
                                     cv::Mat                         image,
                                     const std::vector<cv::Point3d>& corners,
                                     const OGRSpatialReference&      proj_info )
   : Asset_Local_Base(asset_info),
     m_class_name("Asset_Local_Image"),
     m_image(image),
     m_corners(corners),
     m_proj_info(proj_info),
     m_working_image(cv::Size(1,1),CV_8UC4)
{

}


/****************************/
/*        Destructor        */
/****************************/
Asset_Local_Image::~Asset_Local_Image()
{

}


/********************************/
/*          Load Asset          */
/********************************/
void Asset_Local_Image::Load_Asset()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Misc Vars
    bool match_found;
    Status status = Status::SUCCESS();
    Status temp_status;

    // Get the File Path
    std::string filepath = m_asset_info.Query_KV_Pair("asset.local.image.source.pathname",
                                                       match_found);

    // Check if Match Not Found
    if( !match_found )
    {
        status.Append(StatusType::FAILURE,
                      StatusReason::UNINITIALIZED,
                      "No Path Provided to Asset.");
    }

    // Load actual asset
    if( status.Not_Failure() )
    {
        GDAL_Image_Loader::Load_Image( filepath,
                                       m_image,
                                       m_corners,
                                       m_proj_info,
                                       temp_status );
        status.Append(temp_status);
    }

    // Log Exit
    LOG_CLASS_EXIT();
}


/**************************************/
/*        Update Working Image        */
/**************************************/
void Asset_Local_Image::Update_Scene(SceneViewBase::ptr_t  scene_view,
                                     const double&         current_timestamp,
                                     Status&               status)
{
    // Initialize status
    status = Status::SUCCESS();

    // Check if scene requires re-rendering working image
    bool rewarp_image = true;

    // If re-render is needed, first check resize
    if( scene_view->Get_Draw_Size().width  != m_working_image.cols ||
        scene_view->Get_Draw_Size().height != m_working_image.rows )
    {
        LOG_CLASS_DEBUG("Reallocating Working Image. Size: " + std::to_string(m_working_image.cols)
                        + " Cols, " + std::to_string(m_working_image.rows) + " Rows");
        m_working_image = cv::Mat(scene_view->Get_Draw_Size(), CV_8UC4);
        rewarp_image = true;
    }

    // Get Transform
    cv::Mat dest_to_source = cv::Mat::eye(3,3,CV_64FC1);

    // If needed, re-warp
    if( rewarp_image )
    {
        cv::warpPerspective( m_image,
                             m_working_image,
                             dest_to_source,
                             m_working_image.size());
    }

}


/*************************************/
/*        Render Imagery Layer       */
/*************************************/
void Asset_Local_Image::Render_Layer( QPainter&             painter,
                                      Status&               status )
{
    // Initialize Status
    status = Status::SUCCESS();

    // Determine if Scene has changed and requires redraw

    // Get bbox
    QRect target_bbox(QPoint(0,0), QSize(m_working_image.cols,
                                         m_working_image.rows));

    // Create pixel map
    QImage working_image((const uchar*)m_working_image.data,
                         m_working_image.cols,
                         m_working_image.rows,
                         m_working_image.step,
                         QImage::Format_RGBA8888);
    working_image.bits();

    // Copy Raster to Scene Painter
    painter.drawPixmap(target_bbox,
                       QPixmap::fromImage(working_image),
                       working_image.rect());

}


/****************************************/
/*          Create Scene View           */
/****************************************/
SceneViewBase::ptr_t  Asset_Local_Image::Create_Scene_View( const OGRSpatialReference&  default_projection,
                                                            Status&                     status )const
{
    // Initialize Status
    status = Status::SUCCESS();
    Status temp_status;

    // Create empty scene
    SceneViewBase::ptr_t scene;
    GEO::CoordinateBase::ptr_t centroid;
    SceneViewUTM::ptr_t utm_scene;
    double gsd;

    // Check the coordinate type (UTM)
    if( default_projection.GetUTMZone() != 0 )
    {
        // Get center of scene projection
        centroid = Get_Image_Center_Coordinate(temp_status);
        status.Append(temp_status);


        if (status.Not_Failure())
        {
            // Build the new scene
            scene = std::make_shared<SceneViewUTM>(default_projection);

            // cast to utm
            utm_scene = std::dynamic_pointer_cast<SceneViewUTM>(scene);

            // Compute GSD
            gsd = Compute_Initial_GSD(temp_status);
            status.Append(temp_status);
        }

        if (status.Not_Failure())
        {
            // Update the UTM Scene
            utm_scene->Set_Center_Coordinate(centroid);
            utm_scene->Set_GSD(gsd);
            utm_scene->Set_Rotation_Radians(0);

        }

        if( status.Not_Failure() )
        {
            // Log Creation
            LOG_CLASS_TRACE("Create new initial scene.\n" + utm_scene->To_Log_String());
        }
    }

    // If here, then we have no support for this projection
    else
    {
        status.Append(StatusType::FAILURE,
                      StatusReason::UNKNOWN_PROJECTION,
                      "Unknown Projection Info");
    }

    // return the scene
    return scene;
}


/********************************************************/
/*          Compute the IMage Center Coordinate         */
/********************************************************/
GEO::CoordinateBase::ptr_t Asset_Local_Image::Get_Image_Center_Coordinate(Status &status) const
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize status
    status = Status::SUCCESS();

    // Create output coordinate
    GEO::CoordinateBase::ptr_t output;
    cv::Point3d center;

    // Make sure we have corners
    if( m_corners.size() < 4 )
    {
        status.Append(StatusType::FAILURE,
                      StatusReason::NO_GEO_INFORMATION,
                      "Asset contains no corner information");
    }

    // If no errors, compute center
    if( status.Not_Failure() )
    {
        center = m_corners[0];
        for( auto i = 1; i<m_corners.size(); i++ )
        {
            center.x += m_corners[i].x;
            center.y += m_corners[i].y;
            center.z += m_corners[i].z;
        }
        center.x /= m_corners.size();
        center.y /= m_corners.size();
        center.z /= m_corners.size();
    }

    // Create Coordinate from Centroid
    if( status.Not_Failure() )
    {
        output = GEO::CoordinateFactory::Create(m_proj_info,
                                                center);
    }

    // Return coordinate
    return output;
}


/************************************/
/*          Compute the GSD         */
/************************************/
double Asset_Local_Image::Compute_Initial_GSD( Status& status)const
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize status
    status = Status::SUCCESS();

    double gsd = 0;

    // COmpute max image dimension
    int max_length = std::max( m_image.rows, m_image.cols);

    // Compute distance of that max
    cv::Point3d minPnt = m_corners[0];
    cv::Point3d maxPnt = m_corners[0];

    for( int i=1; i<m_corners.size(); i++ )
    {
        minPnt.x = std::min(minPnt.x, m_corners[i].x);
        minPnt.y = std::min(minPnt.y, m_corners[i].y);
        minPnt.z = std::min(minPnt.z, m_corners[i].z);

        maxPnt.x = std::max(maxPnt.x, m_corners[i].x);
        maxPnt.y = std::max(maxPnt.y, m_corners[i].y);
        maxPnt.z = std::max(maxPnt.z, m_corners[i].z);
    }

    // Pick a side to use
    if( m_image.rows > m_image.cols )
    {
        gsd = std::fabs(maxPnt.y - minPnt.y) / max_length;
    }
    else
    {
        gsd = std::fabs(maxPnt.x - minPnt.x) / max_length;
    }

    // Return gsd
    return gsd;
}
/**
 * @file    SceneViewUTM.cpp
 * @author  Marvin Smith
 * @date    9/3/2017
 */
#include "SceneViewUTM.hpp"

// C++ Libraries
#include <sstream>

// Project Libraries
#include "../log/System_Logger.hpp"


/********************************/
/*          Constructor         */
/********************************/
SceneViewUTM::SceneViewUTM()
 : SceneViewBase(),
   m_class_name("SceneViewUTM"),
   m_pix2scene(3,3,CV_64FC1),
   m_scene2world(3,3,CV_64FC1)
{
}


/********************************/
/*          Constructor         */
/********************************/
SceneViewUTM::SceneViewUTM( const OGRSpatialReference& projection)
    : SceneViewBase(projection),
      m_class_name("SceneViewUTM")
{
}


/************************************/
/*        Update Transforms         */
/************************************/
void SceneViewUTM::Update_Transforms()
{
    // Build Pixel 2 Scene Transform
    m_pix2scene = cv::Mat::eye(cv::Size(3,3), CV_64FC1);
    m_pix2scene.at<double>(0,0) =  m_gsd;
    m_pix2scene.at<double>(1,1) = -m_gsd;

    m_pix2scene.at<double>(0,2) = -m_draw_size.width/2.0;
    m_pix2scene.at<double>(1,2) = -m_draw_size.height/2.0;

    // Build scene 2 world
    m_scene2world = cv::Mat::eye(cv::Size(3,3), CV_64FC1);
    m_scene2world.at<double>(0,0) =  std::cos(m_rotation_rad);
    m_scene2world.at<double>(0,1) = -std::sin(m_rotation_rad);
    m_scene2world.at<double>(1,0) =  std::sin(m_rotation_rad);
    m_scene2world.at<double>(1,1) =  std::cos(m_rotation_rad);

    if( m_center != nullptr )
    {
        m_scene2world.at<double>(0, 2) = m_center->Get_X();
        m_scene2world.at<double>(1, 2) = m_center->Get_Y();
    }
    else
    {
        LOG_CLASS_WARNING("No Center Coordinate Provided.");
    }
}


cv::Mat SceneViewUTM::Get_Scene_To_World_Transform() const
{
    return m_scene2world * m_pix2scene;
}

/************************************/
/*          Print to String         */
/************************************/
std::string SceneViewUTM::To_Log_String(const int &indent) const
{
    // create gap
    std::string gap(indent, ' ');

    // Create stream
    std::stringstream sin;
    sin << gap << m_class_name << std::endl;
    sin << gap << std::string(m_class_name.size(), '-') << std::endl;

    // Print the Center
    sin << gap << "  - Center:\n" << m_center->To_String(indent+4) << std::endl;
    sin << gap << "  - GSD: " << m_gsd << std::endl;
    sin << gap << "  - Rotation (deg): " << Get_Rotation_Degrees() << std::endl;

    return sin.str();
}


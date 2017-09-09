/**
 * @file    SceneViewUTM.cpp
 * @author  Marvin Smith
 * @date    9/3/2017
 */
#include "SceneViewUTM.hpp"

// C++ Libraries
#include <sstream>


/********************************/
/*          Constructor         */
/********************************/
SceneViewUTM::SceneViewUTM()
 : SceneViewBase(),
   m_class_name("SceneViewUTM")
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


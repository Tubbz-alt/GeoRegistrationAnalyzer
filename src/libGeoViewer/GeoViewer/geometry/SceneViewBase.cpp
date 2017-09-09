/**
 * @file    SceneViewBase.cpp
 * @author  Marvin Smith
 * @date    9/3/2017
 */
#include "SceneViewBase.hpp"

/********************************/
/*          Constructor         */
/********************************/
SceneViewBase::SceneViewBase()
 : m_class_name("SceneViewBase")
{
}


/********************************/
/*          Constructor         */
/********************************/
SceneViewBase::SceneViewBase( const OGRSpatialReference& projection )
 :  m_projection(projection),
    m_class_name("SceneViewBase")
{
}


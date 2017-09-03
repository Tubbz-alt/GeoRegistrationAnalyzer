/**
 * @file    SceneViewUTM.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEOIMAGE_GEOMETRY_SCENEVIEWUTM_HPP
#define GEOIMAGE_GEOMETRY_SCENEVIEWUTM_HPP

// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "../coordinate.hpp"
#include "SceneViewBase.hpp"


namespace GEO {


/**
 * @class SceneViewUTM
 */
class SceneViewUTM : public SceneViewBase
{
    public:

        /// Pointer Type
        typedef std::shared_ptr<SceneViewUTM> ptr_t;

        /**
         * @brief Constructor
        */
        SceneViewUTM();


    private:

        /// Class Name
        std::string m_class_name;

        /// Center
        CoordinateUTM m_center;

        /// Zoom Factor
        double m_gsd;

        /// Rotation in Radians
        double m_rotation_rad;
};

} // End of GEO Namespace

#endif
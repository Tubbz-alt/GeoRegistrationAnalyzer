/**
 * @file    SceneViewBase.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEOIMAGE_GEOMETRY_SCENEVIEW_BASE_HPP
#define GEOIMAGE_GEOMETRY_SCENEVIEW_BASE_HPP

// C++ Libraries
#include <memory>
#include <string>

namespace GEO {

/**
 * @class SceneViewBase
 */
class SceneViewBase
{
    public:
        
        /**
         * @brief Constructor
         */
        SceneViewBase();

    private:

        /// Class Name
        std::string m_class_name;
};

} // End of GEO Namespace

#endif
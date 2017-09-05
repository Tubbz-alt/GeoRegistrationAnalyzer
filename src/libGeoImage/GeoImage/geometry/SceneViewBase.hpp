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

// Project Libraries
#include "../coordinate/CoordinateBase.hpp"


namespace GEO{

/**
 * @class SceneViewBase
 */
class SceneViewBase
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<SceneViewBase> ptr_t;
        

        /**
         * @brief Constructor
         */
        SceneViewBase();


        /**
         * @brief Get the Center Coordinate
         */
        virtual CoordinateBase::ptr_t Get_Center_Coordinate()const = 0;


        /**
         * @brief Get Transform
         */


    private:

        /// Class Name
        std::string m_class_name;
};

} // End of GEO Namespace

#endif

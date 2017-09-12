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


// GeoImage Libraries
#include <GeoImage/coordinate/CoordinateBase.hpp>

// GDAL Libraries
#include <ogr_spatialref.h>

// OpenCV Libraries
#include <opencv2/core/core.hpp>

// Qt Libraries
#include <QTransform>


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
         * @brief Constructor given OGR Projection info.
         * @param projection
         */
        SceneViewBase( const OGRSpatialReference& projection );


        /**
         * @brief Get the Center Coordinate
         */
        virtual GEO::CoordinateBase::ptr_t Get_Center_Coordinate()const = 0;


        /**
         * @brief Set the Center Coordinate
         * @param center
         */
        virtual void Set_Center_Coordinate( GEO::CoordinateBase::ptr_t center ) = 0;


        /**
         * @brief Get the drawing rectangle
         */
        virtual cv::Size Get_Draw_Size()const{
            return m_draw_size;
        }


        /**
         * @brief Set the Drawing Size
         */
        virtual void Set_Draw_Size(const cv::Size &draw_size){
            m_draw_size = draw_size;
            Update_Transforms();
        }


        /**
         * @brief Update Transform Data
         */
        virtual void Update_Transforms() = 0;


        /**
         * @brief Get the Scene-to-World Transform
         * @return
         */
        virtual cv::Mat Get_Scene_To_World_Transform()const = 0;


        /**
         * @brief Get Log-Worthy String
         */
        virtual std::string To_Log_String( const int& indent = 0 )const = 0;

    protected:

        /// Projection
        OGRSpatialReference m_projection;

        /// Drawing Rectangle
        cv::Size m_draw_size;

        /// Pixel to UTM Transform
        QTransform m_pixel_to_world;

        /// UTM to Pixel Transform
        QTransform m_world_to_pixel;

    private:

        /// Class Name
        std::string m_class_name;
};


#endif

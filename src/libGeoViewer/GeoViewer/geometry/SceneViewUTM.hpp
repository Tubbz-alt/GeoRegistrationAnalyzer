/**
 * @file    SceneViewUTM.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef LIB_GEO_VIEWER_GEOMETRY_SCENEVIEWUTM_HPP
#define LIB_GEO_VIEWER_GEOMETRY_SCENEVIEWUTM_HPP

// C++ Libraries
#include <cmath>
#include <memory>
#include <string>

// Project Libraries
#include "SceneViewBase.hpp"

// GeoImage Libraries
#include <GeoImage/coordinate/CoordinateUTM.hpp>


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


        /**
         * @brief Constructor with projection inro attached
         */
        SceneViewUTM( const OGRSpatialReference& projection );


        /**
         * @brief Get the Center Coordinate
         */
        inline virtual GEO::CoordinateBase::ptr_t Get_Center_Coordinate()const{
            return m_center;
        }


        /**
         * @brief Set the Center Coordinate
         */
        inline virtual void Set_Center_Coordinate( GEO::CoordinateBase::ptr_t center ){
            m_center = std::dynamic_pointer_cast<GEO::CoordinateUTM>(center);
        }


        /**
         * @brief Get the GSD
         */
        inline virtual double Get_GSD() const{
            return m_gsd;
        }


        /**
         * @brief Set the GSD
         */
        inline virtual void Set_GSD( const double& gsd ){
            m_gsd = gsd;
            Update_Transforms();
        }


        /**
         * @brief Get the Rotation in Radians
         */
        inline double Get_Rotation_Radians()const{
            return m_rotation_rad;
        }


        /**
         * @brief Get the Rotation in Degrees
         */
        inline double Get_Rotation_Degrees()const{
            return m_rotation_rad * 180 / M_PI;
        }


        /**
         * @brief Set the Rotation in Radians
         */
        inline void Set_Rotation_Radians( const double& rotation_rad ){
            m_rotation_rad = rotation_rad;
            Update_Transforms();
        }


        /**
         * @brief Update Transforms
         */
        virtual void Update_Transforms();


        /**
         * @brief Get the Scene to World Transform
         * @return
         */
        virtual cv::Mat Get_Scene_To_World_Transform()const;


        /**
         * @brief Get Log-Worthy String
         */
        virtual std::string To_Log_String( const int& indent = 0 )const;


    protected:

        /// Center
        GEO::CoordinateUTM::ptr_t m_center;

        /// Zoom Factor
        double m_gsd;

        /// Rotation in Radians
        double m_rotation_rad;


    private:

        /// Class Name
        std::string m_class_name;

        /// Image Transform
        cv::Mat m_pix2scene;
        cv::Mat m_scene2world;
};


#endif
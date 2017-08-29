/**
 * @file    GeoViewerLocal.hpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#ifndef GEOVIEWER_GEOVIEWER_LOCAL_HPP
#define GEOVIEWER_GEOVIEWER_LOCAL_HPP


// Qt Libraries
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTransform>
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "GeoViewerBase.hpp"


/**
 * @class GeoViewerLocal
 */
class GeoViewerLocal : public GeoViewerBase
{

    public:

        /**
         * @brief Constructor for Local API viewer class
         *
         * @param sys_config
         * @param parent
         */
        GeoViewerLocal( const std::string&          base_config_profile,
                        System_Configuration::ptr_t sys_config,
                        QWidget*                    parent = nullptr );


        /**
         * @brief Import Asset
         */
        virtual void Import_Asset( int asset_id );


    protected:

        /**
         * @brief Initialize the GUI
         */
        void Initialize_GUI();


    private:

        /**
         * @brief Update Configuration
         */
        void Update_Configuration();

        /**
         * @brief Initialize the Scene
         */
        void Initialize_Scene();


        /// Class Name
        std::string m_class_name;

        /// Graphics Scene
        QGraphicsScene m_scene;

        /// Main View
        QGraphicsView* m_view;

        /// Current Transforms
        QTransform m_transform;
        QTransform m_image_transform;

        /// Initialization Materials
        QGraphicsTextItem* m_warning_text;

};

#endif
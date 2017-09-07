/**
 * @file    GeoViewerLocalWindow.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEO_VIEWER_GUI_GEO_VIEWER_LOCAL_WINDOW_HPP
#define GEO_VIEWER_GUI_GEO_VIEWER_LOCAL_WINDOW_HPP

// C++ Libraries
#include <deque>


// Qt Libraries
#include <QFrame>
#include <QPainter>


// GeoImage Libraries
#include <GeoImage/geometry/SceneViewUTM.hpp>


// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "local/RenderWorker.hpp"
#include "local/Scene_Context.hpp"


/**
 * @class GeoViewerLocalWindow
 */
class GeoViewerLocalWindow : public QFrame
{
    Q_OBJECT

    signals:

        void Request_Update_Scene();

    public:

        /**
         * @brief Constructor
         *
         * @param base_config_profile
         * @param sys_config
         * @param parent
         */
        GeoViewerLocalWindow( const std::string&          base_config_profile,
                              System_Configuration::ptr_t sys_config,
                              QWidget*                    parent = nullptr );


    public slots:

        /**
         * @brief Import new asset by its ID
         * @param asset_id
         */
        void Import_Asset( int asset_id );

    protected slots:

        /**
         * @brief Render the scene
         */
        void Update_Scene();

    protected:

        /**
         * @brief Painting Event
         * @param event
         */
        void paintEvent( QPaintEvent* event );

    private:

        /**
         * @brief Configure Window
         */
        void Initialize_Frame();


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Base Config Profile
        std::string m_base_config_profile;

        /// Render Worker
        LOCAL::RenderWorker::ptr_t  m_render_worker;

        /// Frame-Number
        double m_current_timestamp;

        /// Current Scene View
        GEO::SceneViewBase::ptr_t m_current_scene;

};

#endif
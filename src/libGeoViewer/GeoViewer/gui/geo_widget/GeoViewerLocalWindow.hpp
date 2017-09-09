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
#include <QThread>
#include <QTimer>


// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "../../geometry/SceneViewUTM.hpp"
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


        /**
         * @brief Destructor
         */
        virtual ~GeoViewerLocalWindow();


        /**
         * @brief Set the Scene View Target
         */
        //void Set_Scene_Target();


    public slots:

        /**
         * @brief Import new asset by its ID
         * @param asset_id
         */
        void Import_Asset( int asset_id );


    protected:

        /**
         * @brief Painting Event
         * @param event
         */
        void paintEvent( QPaintEvent* event );


        /**
         * @brief Resize Window Event
         * @param event
         */
        void resizeEvent( QResizeEvent* event );

    protected slots:

        /**
         * @brief Trigger to notify ui that scene has finished building
         *
         * Triggers a paint.
         * @param success
         */
        void Update_Scene_Completed( bool success );

    private:


        /**
         * @brief Window Bounds have Changed
         */
        void Bounds_Changed();


        /**
         * @brief Get the default projection from the config
         *
         * @return
         */
        OGRSpatialReference Get_Default_Projection();


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

        /// Rendering Thread
        QThread m_render_thread;

        /// Frame-Number
        double m_current_timestamp;

        /// Current Scene View
        SceneViewBase::ptr_t m_current_scene;

        /// Painting Mutex Lock
        QMutex m_paint_mutex;

        /// Current Projection (WKT)
        std::string m_current_projection;

        /// Projection Loaded
        bool m_projection_loaded;

};

#endif
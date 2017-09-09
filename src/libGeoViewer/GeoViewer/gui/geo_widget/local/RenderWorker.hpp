/**
 * @file    RenderWorker.hpp
 * @author  Marvin Smith
 * @date    9/6/2017
 */
#ifndef LIB_GEO_VIEWER_GUI_LOCAL_RENDER_WORKER_HPP
#define LIB_GEO_VIEWER_GUI_LOCAL_RENDER_WORKER_HPP

// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "Scene_Context.hpp"
#include "../../../core/System_Configuration.hpp"

// Qt Libraries
#include <QMutex>
#include <QPainter>

namespace LOCAL{

/**
 * @class RenderWorker
 */
class RenderWorker : public QObject
{
    Q_OBJECT

    signals:

        void Update_Scene_Complete(bool);


    public:

        /// Pointer Type
        typedef std::shared_ptr<RenderWorker> ptr_t;

        /**
         * @brief Rendering Worker
         */
        RenderWorker( const std::string&          base_config_profile,
                      System_Configuration::ptr_t sys_config );


        /**
         * @brief Add new Scene Context
         * @param new_context
         */
        void Insert_Scene_Context_Top( Scene_Context::ptr_t new_context,
                                       Status&              status );


        /**
         * @brief Get the number of scene
         * @return
         */
        inline int Get_Scene_Count()const{
            return m_scene_render_list.size();
        }


        /**
         * @brief Paint the Scene
         */
        void Paint_Scene( QPainter& painter );


        /**
         * @brief Set the new scene-view
         * @param new_scene_view
         */
        inline void Set_Scene_View( SceneViewBase::ptr_t new_scene_view ){
            m_current_scene = new_scene_view;
        }


        /**
         * @brief Set the Current Time
         * @param timestamp  Timestamp in unix double
         */
        inline void Set_Current_Timestamp( const double& timestamp ){
            m_current_timestamp = timestamp;
        }


    public slots:

        /**
         * @brief Start the update algorithm.
         */
        void Update_Scene();

    private:

        /// Class Name
        std::string m_class_name;

        /// Base Configuration Profile Node
        std::string m_base_config_profile;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// List of Scene Context Objects
        std::vector<Scene_Context::ptr_t> m_scene_render_list;

        // Threading logic
        QMutex m_render_mutex;

        /// Current Scene View
        SceneViewBase::ptr_t m_current_scene;

        /// Current Timestamp
        double m_current_timestamp;


}; // End of RenderWorker Class


} // End of LOCAL Namespace

#endif
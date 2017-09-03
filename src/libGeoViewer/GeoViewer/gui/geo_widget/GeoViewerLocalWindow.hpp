/**
 * @file    GeoViewerLocalWindow.hpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#ifndef GEO_VIEWER_GUI_GEO_VIEWER_LOCAL_WINDOW_HPP
#define GEO_VIEWER_GUI_GEO_VIEWER_LOCAL_WINDOW_HPP

// Qt Libraries
#include <QFrame>
#include <QPainter>


// Project Libraries
#include "../../core/System_Configuration.hpp"


/**
 * @class GeoViewerLocalWindow
 */
class GeoViewerLocalWindow : public QFrame
{
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

        /// Scene



};

#endif
/**
 * @file    GeoViewerGoogle.hpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#ifndef GEOVIEWER_GEOVIEWER_GOOGLE_HPP
#define GEOVIEWER_GEOVIEWER_GOOGLE_HPP


// Qt Libraries
#include <QtWebEngine/QtWebEngine>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QWebSocket>
#include <QWebSocketServer>
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "GeoViewerBase.hpp"


/**
 * @class GeoViewerGoogle
 */
class GeoViewerGoogle : public GeoViewerBase
{

    public:

        /**
         * @brief Constructor for Google Maps API viewer class
         *
         * @param sys_config
         * @param parent
         */
        GeoViewerGoogle( const std::string&          base_config_profile,
                         System_Configuration::ptr_t sys_config,
                         QWidget*                    parent = nullptr );


        /**
         * @brief Set the Page URL
         *
         * @param[in] url
         */
        virtual void Set_URL( const std::string& url );


        /**
         * @brief Update the Asset In View
         */
        virtual void Update_Asset( const Asset_Image_Base::ptr_t new_asset );


    protected:

        /**
         * @brief Initialize Gui
         */
        void Initialize_GUI();


    private:

        void Update_Configuration();

        /// Class Name
        std::string m_class_name;

        /// Web View
        QWebEngineView* m_web_view;

        /// WebSocket Server
        QWebSocketServer* m_socket_server;

        /// List of Connections
        QList<QWebSocket*> m_socket_clients;

};

#endif
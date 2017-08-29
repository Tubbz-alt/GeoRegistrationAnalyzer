/**
 * @file    GeoViewerCesium.hpp
 * @author  Marvin Smith
 * @date    7/29/2017
 */
#ifndef GEOVIEWER_GEOVIEWER_CESIUM_HPP
#define GEOVIEWER_GEOVIEWER_CESIUM_HPP


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
class GeoViewerCesium : public GeoViewerBase
{

    public:

        /**
         * @brief Constructor for Cesium API viewer class
         *
         * @param sys_config
         * @param parent
         */
        GeoViewerCesium( const std::string&          base_config_profile,
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
        virtual void Import_Asset( const Asset_Image_Base::ptr_t new_asset );


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
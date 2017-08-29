/**
 * @file    GeoWidget.hpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#ifndef GUI_GEOWIDGET_GEOWIDGET_HPP
#define GUI_GEOWIDGET_GEOWIDGET_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/assets/Asset_Image_Base.hpp"
#include "../../core/System_Configuration.hpp"
#include "GeoViewerBase.hpp"
#include "GeoViewerFactory.hpp"


/**
 * @class QWidget
 */
class GeoWidget : public QWidget
{
        Q_OBJECT

    public:

        /**
         * @brief Constructor for base viewer class
         *
         * @param sys_config
         * @param parent
         */
        GeoWidget( const std::string&          base_config_profile,
                   System_Configuration::ptr_t sys_config,
                   QWidget*                    parent = nullptr );


        /**
         * @brief Handler Message
         */
        void Handle_Message( const std::string& topic_name,
                             const std::string& message );


    public slots:

        /**
         * @brief Import new asset via Asset-Manager ID.
         */
        void Import_Asset_ID( const int& id );


    protected:

        /**
         * @brief Initialize GUI
         */
        void Initialize_GUI();


        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Viewer Name
        std::string m_viewer_name;

        /// Viewer ID
        std::string m_viewer_id;

    private:

        /**
         * @brief Update Configuration
         */
        void Update_Configuration();


        /// Class Name
        std::string m_class_name;

        /// Base Config Profile
        std::string m_base_config_profile;

        /// GeoWidget Viewer
        std::map<std::string,GeoViewerBase*> m_geo_viewers;

}; // End of GeoWidget Class

#endif
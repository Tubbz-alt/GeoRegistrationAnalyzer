/**
 * @file    GeoViewerBase.hpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#ifndef GEOVIEWER_GEOVIEWER_BASE_HPP
#define GEOVIEWER_GEOVIEWER_BASE_HPP


// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "../../core/assets/Asset_Image_Base.hpp"


/**
 * @class GeoViewerBase
 */
class GeoViewerBase : public QWidget
{

    public:

        /**
         * @brief Constructor for base viewer class
         *
         * @param sys_config
         * @param parent
         */
        GeoViewerBase( const std::string&          base_config_profile,
                       System_Configuration::ptr_t sys_config,
                       QWidget*                    parent = nullptr );


        /**
         * @brief Update the Asset In View
         */
        virtual void Update_Asset( const Asset_Image_Base::ptr_t new_asset ) = 0;


    protected:

        /// Configuration Base Key
        std::string m_base_config_profile;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

    private:

        /// Class Name
        std::string m_class_name;

};

#endif
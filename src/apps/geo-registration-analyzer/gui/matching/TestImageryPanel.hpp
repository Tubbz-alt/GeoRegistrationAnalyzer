/**
 * @file    TestImageryPanel.hpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#ifndef TEST_IMAGERY_PANEL_HPP
#define TEST_IMAGERY_PANEL_HPP

// Qt Libraries
#include <QWidget>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>
#include <GeoViewer/core/assets/Asset_Image_Base.hpp>
#include <GeoViewer/gui/geo_widget/GeoWidget.hpp>

// Project Libraries
#include "TestToolbar.hpp"


/**
 * @class TestImageryPanel
*/
class TestImageryPanel : public QWidget
{
    public:

        /**
         * @brief Constructor
        */
        TestImageryPanel( System_Configuration::ptr_t sys_config,
                          QWidget*                    parent = nullptr );



        void Update_Geo_Viewer( const std::string&      asset_type,
                                Asset_Image_Base::ptr_t new_asset );

    protected:

        /**
         * @brief Initialize the GUI
        */
        void Initialize_GUI();


        /**
         * @brief Register Message Service
         */
        void Handle_Message( const std::string& topic_name,
                             const std::string& message );

        
    private:

        /**
         * @brief Initialize Configuration
         */
        void Initialize_Configuration();

        // Class Name
        std::string m_class_name;

        // System Configuration
        System_Configuration::ptr_t m_sys_config;

        // GeoViewer
        GeoWidget* m_geo_widget;

        /// Test Toolbar
        TestToolbar* m_toolbar;

}; // End of TestImageryPanel Class

#endif

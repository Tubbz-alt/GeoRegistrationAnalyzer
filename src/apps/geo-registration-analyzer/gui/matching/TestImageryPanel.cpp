/**
 * @file    TestImageryPanel.cpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#include "TestImageryPanel.hpp"

// C++ Libraries
#include <sstream>


// Qt Libraries
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVBoxLayout>


// GeoViewer Libraries
#include <GeoViewer/assets/Asset_Image_Base.hpp>
#include <GeoViewer/assets/Asset_Manager.hpp>
#include <GeoViewer/core/System_Manager.hpp>
#include <GeoViewer/log/System_Logger.hpp>


/********************************/
/*          Constructor         */
/********************************/
TestImageryPanel::TestImageryPanel( System_Configuration::ptr_t sys_config,
                                    QWidget*                    parent )
  : QWidget(parent),
    m_class_name("TestImageryPanel"),
    m_sys_config(sys_config)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();

    // Register Handler
    MessageService::HANDLER_TYPE handler = std::bind( &TestImageryPanel::Handle_Message,
                                                      this,
                                                      std::placeholders::_1,
                                                      std::placeholders::_2);

    // Add Handler
    System_Manager::Get_Message_Service()->Subscribe("test_imagery_load", handler );
}


/************************************************/
/*            Update the Geo-Viewer             */
/************************************************/
void TestImageryPanel::Update_Geo_Viewer( const int&  asset_id )

{
    // Check the current geo-viewer type
    int asset_idd = asset_id;
    m_geo_widget->Import_Asset_ID( asset_idd );

}


/************************************/
/*          Initialize GUI          */
/************************************/
void TestImageryPanel::Initialize_GUI()
{
    // Get the Base Configuration
    bool value_found;
    std::string base_conf = "system.matching.test";

    // Create the main layout
    QVBoxLayout* main_layout = new QVBoxLayout();
    main_layout->setContentsMargins(2,2,2,2);

    // Create the geo widget
    m_geo_widget = new GeoWidget( base_conf,
                                  m_sys_config,
                                  this);
    main_layout->addWidget(m_geo_widget);

    // Create the toolbar
    m_toolbar = new TestToolbar(m_sys_config, this);
    main_layout->addWidget(m_toolbar);

    // Set the main layout
    setLayout(main_layout);

    // Set the Window Title
    setWindowTitle("Test Imagery");
}


/************************************/
/*          Handle Message          */
/************************************/
void TestImageryPanel::Handle_Message(const std::string& topic_name,
                                      const std::string& message)
{
    // Log Entry
    LOG_CLASS_TRACE( "Start of Method. Topic: (" + topic_name
                     + "), Message: (" + message + ")");

    //  Check if we received command to load image
    if( topic_name == "test_imagery_load" )
    {
        // Convert
        QJsonDocument json_doc;
        QJsonObject json_obj;

        json_doc = QJsonDocument::fromJson(QByteArray(message.c_str()));
        json_obj = json_doc.object();
        std::stringstream sss;
        sss << "Parsed JSON Obj: " << json_obj.size();
        LOG_CLASS_TRACE(sss.str());

        // Extract the asset id
        int asset_id           = json_obj["asset_id"].toInt(-1);
        std::string asset_type = json_obj["source"].toString().toStdString();

        // Update or reconstruct new GeoViewer
        Update_Geo_Viewer( asset_id );

    }

}


/*********************************************************/
/*          Initialize the System Configuration          */
/*********************************************************/
void TestImageryPanel::Initialize_Configuration()
{

    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.matching.test.provider",
                                   "local",
                                   "#  Default Provider for the Reference Panel",
                                   false);
}
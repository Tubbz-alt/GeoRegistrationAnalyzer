/**
 * @file GeoViewerGoogle.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "GeoViewerGoogle.hpp"

// Qt Libraries
#include <QVBoxLayout>


/*********************************/
/*          Constructor          */
/*********************************/
GeoViewerGoogle::GeoViewerGoogle( const std::string&          base_config_profile,
                                  System_Configuration::ptr_t sys_config,
                                  QWidget*                    parent)
 : GeoViewerBase( base_config_profile,
                  sys_config,
                  parent),
   m_class_name("GeoViewerGoogle")
{
    // Update the Configuration Object
    Update_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/*******************************/
/*         Set the URL         */
/*******************************/
void GeoViewerGoogle::Set_URL( const std::string& url )
{
    std::string turl = url;
    for( size_t i=0; i<turl.size(); i++ ){
        if( turl[i] == '\\' ){
            turl[i] = '/';
        }
    }
    m_web_view->setUrl(QUrl(turl.c_str()));
}


/****************************************/
/*          Initialize the GUI          */
/****************************************/
void GeoViewerGoogle::Initialize_GUI()
{
    // Create Layout
    QVBoxLayout* main_layout = new QVBoxLayout();

    // Create Web Engine
    m_web_view = new QWebEngineView(this);
    main_layout->addWidget( m_web_view );
    main_layout->setContentsMargins(0,0,0,0);


    // Set layout
    setLayout(main_layout);

    // Set the initial URL
    bool found;
    std::string base_url = m_sys_config->Query_Config_Param("system.core.html_path",
                                                            found,
                                                            "file://localhost/",
                                                            true );

    std::string url = base_url + "/google_maps.html";
    m_web_view->setUrl(QUrl(url.c_str()));
}

/*************************************************/
/*          Update the Configuration Object      */
/*************************************************/
void GeoViewerGoogle::Update_Configuration()
{

}


/**
 * @class GeoWidget.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include "GeoWidget.hpp"

// GeoViewer Libraries
#include "../../core/Status.hpp"
#include "../../core/System_Manager.hpp"
#include "../../core/assets/Asset_Manager.hpp"
#include "../../log/System_Logger.hpp"


// Qt Libraries
#include <QVBoxLayout>


/*********************************/
/*          Constructor          */
/*********************************/
GeoWidget::GeoWidget( const std::string&          base_config_profile,
                      System_Configuration::ptr_t sys_config,
                      QWidget*                    parent)
 : QWidget(parent),
   m_sys_config(sys_config),
   m_class_name("GeoWidget"),
   m_base_config_profile(base_config_profile)
{
    // Grab the viewer attributes
    bool value_found;
    m_viewer_name = m_sys_config->Query_Config_Param(m_base_config_profile + ".name",
                                                     value_found);
    if(!value_found){ m_viewer_name = "UNKNOWN"; }
    m_viewer_id   = m_sys_config->Query_Config_Param(m_base_config_profile + ".id",
                                                     value_found);
    if(!value_found){ m_viewer_id = "UNKNOWN"; }


    // Initialize Config
    Update_Configuration();

    // Initialize GUI
    Initialize_GUI();

    // Bind to Message-Service
    std::function<void(std::string,std::string)> handler = std::bind(&GeoWidget::Handle_Message, this, std::placeholders::_1, std::placeholders::_2);
    System_Manager::Get_Message_Service()->Subscribe( "GEO_WIDGET", handler );

}


/****************************************************/
/*          Handle Message-Service Messages         */
/****************************************************/
void GeoWidget::Handle_Message( const std::string& topic_name,
                                const std::string& message )
{
    // Log Entry
    LOG_CLASS_TRACE( "Received Message. Topic (" + topic_name + "), Message: " + message);

    // Check if topic-name is from Asset-Manager
    if( topic_name == "GEO_WIDGET" )
    {
        // Parse the Message
        Status status;
        Config_Param msg_data = Config_Param::FromJsonString(message, status );

        if( status.Not_Success() )
        {
            LOG_CLASS_ERROR(status.To_Log_String());
        }

        // If no errors continue
        else
        {
            // Get command-type
            bool match_found;
            const std::string command = msg_data.Query_KV_Pair("command.name", match_found);

            if(match_found)
            {
                // Check Against List
                if( command == "import" )
                {
                    // Get Asset ID
                    int asset_id = std::stoi(msg_data.Query_KV_Pair("command.import.asset_id", match_found));
                    LOG_CLASS_TRACE("Importing New Asset: " + std::to_string(asset_id));
                    Import_Asset_ID(asset_id);
                }

                // Log Error
                else
                {
                    LOG_CLASS_ERROR("Unsupported Command: " + command);
                }
            }

            // Otherwise, error
            else
            {
                LOG_CLASS_ERROR("Message Data Has Invalid Structure. " + msg_data.ToString());
            }
        }

    }
}


/*************************************/
/*      Import new Asset at ID.      */
/*************************************/
void GeoWidget::Import_Asset_ID(const int& asset_id)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Check ID.
    Asset_Base::ptr_t new_asset = Asset_Manager::Query_Asset(asset_id);
    if( new_asset == nullptr )
    {
        LOG_CLASS_ERROR("Asset (" + std::to_string(asset_id) + ") returned was null.");
    }

    // If no errors, load
    else
    {
        for( auto viewer : m_geo_viewers )
        {
            viewer.second->Import_Asset(asset_id);
        }
    }

    // Log Exit
    LOG_CLASS_EXIT();
}

/****************************************/
/*          Update Configuration        */
/****************************************/
void GeoWidget::Update_Configuration()
{

}


/***********************************/
/*          Initialize GUI         */
/***********************************/
void GeoWidget::Initialize_GUI()
{
    bool value_found;
    std::string provider = m_sys_config->Query_Config_Param(m_base_config_profile + ".provider",
                                                            value_found);
    std::cout << "Base Profile: " << m_base_config_profile << ", Loading Provider: " << provider << std::endl;

    // Create the layout
    QVBoxLayout* main_layout = new QVBoxLayout();
    main_layout->setContentsMargins(0,0,0,0);

    // Create the viewers
    m_geo_viewers[provider] = GeoViewerFactory::Create( m_base_config_profile, m_sys_config, provider);
    main_layout->addWidget(m_geo_viewers[provider]);


    // set main layout
    setLayout(main_layout);
}

/**
 * @file    Asset_Manager_Widget.cpp
 * @author  Marvin Smith
 * @date    8/7/2017
 */
#include "Asset_Manager_Widget.hpp"

// C++ Libraries
#include <functional>
#include <sstream>

// GeoViewer Libraries
#include <GeoViewer/core/System_Manager.hpp>
#include <GeoViewer/assets/Asset_Manager.hpp>
#include <GeoViewer/log/System_Logger.hpp>


/********************************/
/*          Constructor         */
/********************************/
Asset_Manager_Widget::Asset_Manager_Widget(System_Configuration::ptr_t sys_config,
                                           QWidget *parent)
  : QGroupBox("Asset Manager", parent),
    m_class_name("Asset_Manager_Widget"),
    m_sys_config(sys_config)
{
    // Initialize System Configuration Options
    Initialize_Configuration();

    // Build Dialogs
    Build_Dialogs();

    // Initialize the Widgets
    Initialize_GUI();

    // Subscribe Listener for Asset-Manager
    std::function<void(std::string,std::string)> handler = std::bind(&Asset_Manager_Widget::Handle_Message, this, std::placeholders::_1, std::placeholders::_2);
    System_Manager::Get_Message_Service()->Subscribe( "ASSET_MANAGER", handler );

}


/****************************************************/
/*          Handle Message-Service Messages         */
/****************************************************/
void Asset_Manager_Widget::Handle_Message( const std::string& topic_name,
                                           const std::string& message )
{
    // Log Entry
    LOG_CLASS_TRACE( "Received Message. Topic (" + topic_name + "), Message: " + message);

    // Check if topic-name is from Asset-Manager
    if( topic_name == "ASSET_MANAGER" )
    {
        // Parse the Message
        std::stringstream sin;
        sin << message;

        std::string action;
        sin >> action;

        // Check the action
        if( action == "ASSET_REGISTERED" )
        {
            // Grab the Asset-ID
            int asset_id;
            sin >> asset_id;
            LOG_CLASS_TRACE("New Asset: " + std::to_string(asset_id));
            Add_Asset_Element(asset_id);
        }

        // Otherwise, error
        else{
            LOG_CLASS_ERROR("Unknown Action (" + action + ")");
        }
    }
}

/*************************************************/
/*          Trigger Add Layer Response           */
/*************************************************/
void Asset_Manager_Widget::Trigger_Import_Asset_Response()
{
    // Show the dialog
    m_import_asset_dialog->show();


}


/************************************/
/*          Add Tree Element        */
/************************************/
void Asset_Manager_Widget::Add_Asset_Element(const int &asset_id)
{
    // Query Asset Information
    Asset_Base::ptr_t asset = Asset_Manager::Query_Asset(asset_id);

    if( asset == nullptr )
    {
        LOG_CLASS_ERROR("Asset Returned for ID (" + std::to_string(asset_id) + ").");
    }
    else
    {
        // Post Asset Information
        Config_Param asset_info = asset->Get_Asset_Info();
        LOG_CLASS_TRACE(asset_info.ToString(0));

        bool found;
        std::string asset_type = asset_info.Query_KV_Pair("asset.generator",found);
        if( !found )
        {
            asset_type = "Unknown";
        }
        std::string asset_details = asset_info.Query_KV_Pair("asset.details",found);
        if( !found )
        {
            asset_type = "Unknown";
        }

        // Add Widget
        m_registered_assets[asset_id] = new QTreeWidgetItem(m_asset_widget);
        m_registered_assets[asset_id]->setText(0, std::to_string(asset_id).c_str());
        m_registered_assets[asset_id]->setText(1, asset_type.c_str());
        m_registered_assets[asset_id]->setText(2, asset_details.c_str());
    }
}


/*************************************************/
/*          Initialize the Configuration         */
/*************************************************/
void Asset_Manager_Widget::Initialize_Configuration()
{
    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.toolbar.asset_manager.add_layer.icon",
                                   "add.png",
                                   "#  Path to Add Layer Button",
                                   false);

    m_sys_config->Add_Config_Param("system.toolbar.asset_manager.default.toolbutton.width",
                                   "50",
                                   "#  Button Cols",
                                   false );

    m_sys_config->Add_Config_Param("system.toolbar.asset_manager.default.toolbutton.height",
                                   "50",
                                   "#  Button Rows",
                                   false );
}


/**************************************/
/*          Initialize the GUI        */
/**************************************/
void Asset_Manager_Widget::Initialize_GUI()
{
    // Create the main layout
    m_main_layout = new QHBoxLayout();

    // Create the tree widget
    Build_Tree_Widget();

    // Build the toolbar
    Build_Toolbar();

    // Set main layout
    setLayout(m_main_layout);
}


/*****************************************/
/*          Build the Tree Widget        */
/*****************************************/
void Asset_Manager_Widget::Build_Tree_Widget()
{
    // create widget
    m_asset_widget = new QTreeWidget(this);

    // Set Horizontal Labels
    QStringList labels;
    labels.push_back("Name");
    labels.push_back("Asset Type");
    labels.push_back("Details");
    m_asset_widget->setHeaderLabels(labels);


    // Add to layout
    m_main_layout->addWidget(m_asset_widget);
}


/*****************************************/
/*          Build the Toolbar            */
/*****************************************/
void Asset_Manager_Widget::Build_Toolbar()
{
    // Build Toolbar Widget
    QWidget* toolbar_widget = new QWidget(this);//GroupBox(this);
    toolbar_widget->setContentsMargins(5,5,5,5);


    QVBoxLayout* toolbar_layout = new QVBoxLayout();
    toolbar_layout->setAlignment(Qt::AlignTop);
    toolbar_layout->setContentsMargins(0,0,0,0);


    // Get the default information
    bool value_found;
    std::string icon_path, button_icon_path;
    int def_button_width  = m_sys_config->Query_Config_Param_Int32("system.toolbar.asset_manager.default.toolbutton.width", value_found);
    int def_button_height = m_sys_config->Query_Config_Param_Int32("system.toolbar.asset_manager.default.toolbutton.height", value_found);
    std::string icon_base_path = m_sys_config->Get_Icon_Path();


    // Create the Add Layer Button
    button_icon_path = m_sys_config->Query_Config_Param("system.toolbar.asset_manager.add_layer.icon", value_found);
    icon_path = icon_base_path + "/" + button_icon_path;
    m_tool_buttons.push_back(new QToolButton(toolbar_widget));
    m_tool_buttons.back()->setIcon(QIcon(icon_path.c_str()));
    m_tool_buttons.back()->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    m_tool_buttons.back()->setFixedSize(def_button_width, def_button_height);
    m_tool_buttons.back()->setIconSize(QSize(def_button_width-5, def_button_height-5));
    m_tool_buttons.back()->setToolTip("Import Layer to Geo-Viewer");
    connect(m_tool_buttons.back(), SIGNAL(clicked()), this, SLOT(Trigger_Import_Asset_Response()));
    toolbar_layout->addWidget(m_tool_buttons.back());


    // Set layout
    toolbar_widget->setLayout(toolbar_layout);

    // Add to main layout
    m_main_layout->addWidget(toolbar_widget);
}

/*************************************************/
/*            Build Internal Dialogs             */
/*************************************************/
void Asset_Manager_Widget::Build_Dialogs()
{
    // Create an Import-Asset Dialog
    m_import_asset_dialog = new ImportAssetDialog(m_sys_config, this);

}

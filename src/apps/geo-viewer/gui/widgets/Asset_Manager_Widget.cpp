/**
 * @file    Asset_Manager_Widget.cpp
 * @author  Marvin Smith
 * @date    8/7/2017
 */
#include "Asset_Manager_Widget.hpp"

// C++ Libraries
#include <iostream>


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

}


/*************************************************/
/*          Trigger Add Layer Response           */
/*************************************************/
void Asset_Manager_Widget::Trigger_Import_Asset_Response()
{
    // Show the dialog
    m_import_asset_dialog->show();


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
    labels.push_back("Type");
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
    QGroupBox* toolbar_widget = new QGroupBox();
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


    // Add buttons
    for( auto btn : m_tool_buttons )
    {
        toolbar_layout->addWidget(btn);
    }


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
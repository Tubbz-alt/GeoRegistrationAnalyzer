/**
 * @file    ImportAssetDialog.cpp
 * @author  Marvin Smith
 * @date    8/7/2017
 */
#include "ImportAssetDialog.hpp"

// Qt Libraries
#include <QGroupBox>
#include <QHBoxLayout>
#include <QSizePolicy>


// GeoViewer Libraries
#include <GeoViewer/core/assets.hpp>
#include <GeoViewer/core/System_Manager.hpp>
#include <GeoViewer/log/System_Logger.hpp>


/********************************/
/*          Constructor         */
/********************************/
ImportAssetDialog::ImportAssetDialog(System_Configuration::ptr_t sys_config,
                                     QWidget*                    parent)
  : QDialog(parent),
    m_class_name("ImportAssetDialog"),
    m_sys_config(sys_config)
{
    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();

}


/************************************/
/*          Reset the Dialog        */
/************************************/
void ImportAssetDialog::Reset_Action()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Reset Easy Import WIdget
    m_easy_import_widget->Reset_Action();

    // Set Index
    Set_Panel_Index(0);

    // Log Exit
    LOG_CLASS_EXIT();
}


/************************************/
/*          Import the Asset        */
/************************************/
void ImportAssetDialog::Import_Action()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Get Asset Info
    Config_Param asset_info;
    if( m_import_viewer_stack->currentIndex() == 1 )
    {
        asset_info = m_easy_import_widget->Get_Asset_Info();
    }
    else{
        LOG_CLASS_ERROR("Invalid Index: " + std::to_string(m_import_viewer_stack->currentIndex()));
    }

    // Load Asset
    Status status;
    Asset_Base::ptr_t new_asset = Asset_Loader::Load_Asset( asset_info, status );

    // Check the status
    if( status.Not_Failure() )
    {
        // Add Asset
        auto asset_id = Asset_Manager::Register_Asset(new_asset);
        LOG_CLASS_TRACE("Registered New Asset with ID (" + std::to_string(asset_id) + ")");

        // Imply to Geo-Viewers that it should import this imagery
        Config_Param geo_viewer_message_data;
        geo_viewer_message_data.Add_KV_Pair("commands.import.asset_id", std::to_string(asset_id));
        geo_viewer_message_data.Add_KV_Pair("commands.show.asset_id",std::to_string(asset_id));

        System_Manager::Get_Message_Service()->Send("GEO_VIEWER","IMPORT  " + std::to_string(asset_id));

    }

    // Close the dialog
    close();

    LOG_CLASS_EXIT();
}


/************************************/
/*          Cancel Action           */
/************************************/
void ImportAssetDialog::Cancel_Action()
{
    // Log Entry
    LOG_CLASS_ENTRY();


    // Close the Dialog
    close();

    // Log Exit
    LOG_CLASS_EXIT();
}


/****************************************/
/*          Set the Panel Index         */
/****************************************/
void ImportAssetDialog::Set_Panel_Index( int index)
{
    // Log Entry
    LOG_CLASS_TRACE("Start of Method. Index: " + std::to_string(index));

    // Set the Index
    m_import_viewer_stack->setCurrentIndex(index);

    // Disable Import Button
    m_import_button->setEnabled(false);
}


/****************************************/
/*          Show Easy Import Pane       */
/****************************************/
void ImportAssetDialog::Show_Easy_Import_Pane()
{
    Set_Panel_Index(1);
}


/****************************************/
/*       Enable the Import Button       */
/****************************************/
void ImportAssetDialog::Enable_Import_Button()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    m_import_button->setEnabled(true);
}


/*********************************************************/
/*         Initialize the Configuration Settings         */
/*********************************************************/
void ImportAssetDialog::Initialize_Configuration()
{

}


/*********************************************************/
/*                 Initialize the GUI                    */
/*********************************************************/
void ImportAssetDialog::Initialize_GUI()
{
    // Create the main layout
    m_main_layout = new QVBoxLayout();

    // Create stack widget
    m_import_viewer_stack = new QStackedWidget(this);
    m_main_layout->addWidget(m_import_viewer_stack);

    // Build Title Layer
    Build_Title_Pane();

    // Build the Easy Import Pane
    Build_Easy_Import_Pane();

    // Build the Advanced Pane
    Build_Advanced_Import_Pane();

    // Build the Toolbar
    Build_Toolbar();

    // Set the layout
    setLayout(m_main_layout);
}


/************************************/
/*          Build the Toolbar       */
/************************************/
void ImportAssetDialog::Build_Toolbar()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Create the toolbar widget
    QGroupBox*  toolbar_widget = new QGroupBox("Toolbar",this);

    // Create the toolbar layout
    QHBoxLayout* toolbar_layout = new QHBoxLayout();

    // Create Reset Button
    m_reset_button = new QToolButton(toolbar_widget);
    m_reset_button->setText("Reset");
    toolbar_layout->addWidget(m_reset_button);
    connect(m_reset_button, SIGNAL(clicked()), this, SLOT(Reset_Action()));

    // Create Save Button
    m_import_button = new QToolButton(toolbar_widget);
    m_import_button->setText("Import");
    toolbar_layout->addWidget(m_import_button);
    connect(m_import_button, SIGNAL(clicked()), this, SLOT(Import_Action()));
    m_import_button->setEnabled(false);


    // Create Cancel Button
    m_cancel_button = new QToolButton(toolbar_widget);
    m_cancel_button->setText("Cancel");
    toolbar_layout->addWidget(m_cancel_button);
    connect(m_cancel_button, SIGNAL(clicked()), this, SLOT(Cancel_Action()));

    // Set toolbar layout
    toolbar_widget->setLayout(toolbar_layout);

    // Add to main layout
    m_main_layout->addWidget(toolbar_widget);
}


/****************************************/
/*          Build the Title Pane        */
/****************************************/
void ImportAssetDialog::Build_Title_Pane()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Build actual widget
    QWidget* title_pane = new QWidget(m_import_viewer_stack);

    // Create Layout
    QVBoxLayout* title_layout = new QVBoxLayout();

    // Create Easy Button
    QToolButton* easy_button = new QToolButton(title_pane);
    easy_button->setText("File Import");
    title_layout->addWidget(easy_button);
    connect(easy_button, SIGNAL(clicked()), this, SLOT(Show_Easy_Import_Pane()));


    // Create Advanced Button
    QToolButton* advanced_button = new QToolButton();
    advanced_button->setText("Advanced Import");
    advanced_button->setToolTip("Not Implemented Yet");
    title_layout->addWidget(advanced_button);

    // Add to widget
    title_pane->setLayout(title_layout);

    // Add to stack widget
    m_import_viewer_stack->addWidget(title_pane);

    // Log Exit
    LOG_CLASS_EXIT();
}


/**********************************************/
/*          Build the Easy Import Pane        */
/**********************************************/
void ImportAssetDialog::Build_Easy_Import_Pane()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Create widget
    m_easy_import_widget = new ImportAssetEasyWidget(m_sys_config, this);
    connect( m_easy_import_widget, SIGNAL(Enable_Import_Button()), this, SLOT(Enable_Import_Button()));


    // Add to stack
    m_import_viewer_stack->addWidget(m_easy_import_widget);

    // Log Exit
    LOG_CLASS_EXIT();
}


/******************************************/
/*      Build the Advanced Import Pane    */
/******************************************/
void ImportAssetDialog::Build_Advanced_Import_Pane()
{

}



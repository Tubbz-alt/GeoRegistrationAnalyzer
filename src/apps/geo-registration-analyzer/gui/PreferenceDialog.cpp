/**
 * @file    PreferencesDialog.cpp
 * @author  Marvin Smith
 * @date    5/16/2017
 */
#include "PreferenceDialog.hpp"

// C++ Libraries
#include <iostream>

// Qt Libraries
#include <QHBoxLayout>
#include <QHeaderView>
#include <QTableWidgetItem>

// Project Libraries
#include "LogViewerPanel.hpp"

/**
 * @brief Update the Configuration Table
 */
void Update_Configuration_Table_Worker( System_Configuration::ptr_t sys_config,
                                        QTableWidget*               config_list,
                                        std::mutex&                 lock )
{
    // Lock the mutex
    lock.lock();

    // Get list of config options
    std::map<std::string,std::string> config_map = sys_config->Get_Config_List();

    // Resize the table
    config_list->setRowCount(config_map.size());
    config_list->setColumnCount(3);

    int idx = 0;
    for( auto it = config_map.begin(); it != config_map.end(); it++ )
    {
        config_list->setItem(idx, 0, new QTableWidgetItem(it->first.c_str()));
        config_list->setItem(idx, 1, new QTableWidgetItem(it->second.c_str()));

        // Increment Index
        idx++;
    }

    // Unlock the mutex
    lock.unlock();
}

/*******************************/
/*          Constructor        */
/*******************************/
PreferenceDialog::PreferenceDialog(System_Configuration::ptr_t sys_config,
                                   QWidget*                    parent)
  : QDialog(parent),
    m_class_name("PreferenceDialog"),
    m_sys_config(sys_config)
{
    // Update the Configuration
    Update_Configuration();

    // Initialize GUI
    Initialize_GUI();

    Update_Configuration_Table();
}


/*************************************************/
/*          Update the Configuration Table       */
/*************************************************/
void PreferenceDialog::Update_Configuration_Table()
{
    // Start worker thread
    if( m_config_option_thread.joinable())
    {
        m_config_option_thread.join();
    }

    m_config_option_thread = std::thread(Update_Configuration_Table_Worker,
                                         std::ref(m_sys_config),
                                         std::ref(m_config_option_list),
                                         std::ref(m_config_option_list_lock));

}


/***********************************/
/*          Initialize GUI         */
/***********************************/
void PreferenceDialog::Initialize_GUI()
{
    // Create the Main Layout
    m_main_layout = new QVBoxLayout();

    // Build the Tabbed Widget
    m_main_widget = new QTabWidget(this);
    m_main_layout->addWidget(m_main_widget);

    // Add each page
    Build_Configuration_Panel();

    Build_Logging_Panel();

    // Set the layout
    setLayout(m_main_layout);


    /// Set the Window Title
    bool val_found;
    std::string title_val = m_sys_config->Query_Config_Param("system.gui.preference_dialog.title",
                                                             val_found );

    setWindowTitle(title_val.c_str());
}


/*************************************/
/*        Update Configuration       */
/*************************************/
void PreferenceDialog::Update_Configuration()
{
    // Title of Pref Dialog
    m_sys_config->Add_Config_Param("system.gui.preference_dialog.title",
                                   "Application Preferences",
                                   "#  Title of Dialog",
                                    false );
}


/**********************************************/
/*          Build the Configuration Panel     */
/**********************************************/
void PreferenceDialog::Build_Configuration_Panel()
{
    // Create Widget
    QWidget*  config_panel = new QWidget(m_main_widget);

    // Create Layout
    QVBoxLayout* config_layout = new QVBoxLayout();

    // Create Log Table
    QStringList header_labels;
    header_labels.push_back("Key");
    header_labels.push_back("Value");
    m_config_option_list = new QTableWidget(1, 2, config_panel);
    m_config_option_list->setHorizontalHeaderLabels( header_labels );
    m_config_option_list->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeMode::ResizeToContents);
    m_config_option_list->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeMode::ResizeToContents);
    config_layout->addWidget(m_config_option_list);

    // Set layout
    config_panel->setLayout(config_layout);

    // Add to tab panel
    m_main_widget->addTab( config_panel, "Configuration");
}


/*********************************************/
/*          Build the Logging Panel          */
/*********************************************/
void PreferenceDialog::Build_Logging_Panel()
{
    // Create Widget
    QWidget*  log_panel = new LogViewerPanel(m_sys_config, this);

    // Add to tab panel
    m_main_widget->addTab( log_panel, "Logging");
}

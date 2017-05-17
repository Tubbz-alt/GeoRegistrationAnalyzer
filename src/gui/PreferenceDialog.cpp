/**
 * @file    PreferencesDialog.cpp
 * @author  Marvin Smith
 * @date    5/16/2017
 */
#include "PreferenceDialog.hpp"

// Qt Libraries
#include <QHBoxLayout>



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
}


/***********************************/
/*          Initialize GUI         */
/***********************************/
void PreferenceDialog::Initialize_GUI()
{
    // Create the Main Layout
    m_main_layout = new QVBoxLayout();

    // Build the Title Widget
    Build_Title_Widget();

    // Build the Config Widget

    // Set the layout
    setLayout(m_main_layout);

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


/*******************************************/
/*          Build the Title Widget         */
/*******************************************/
void PreferenceDialog::Build_Title_Widget()
{
    // Create Title Widget
    QWidget* title_widget = new QWidget(this);

    // Create layout
    QHBoxLayout* title_layout = new QHBoxLayout();



    // Set the layout
    title_widget->setLayout(title_layout);

    // Add to main layout
    m_main_layout->addWidget(title_widget);
}

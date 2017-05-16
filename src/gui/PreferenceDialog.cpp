/**
 * @file    PreferencesDialog.cpp
 * @author  Marvin Smith
 * @date    5/16/2017
 */
#include "PreferenceDialog.hpp"


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

}


/*************************************/
/*        Update Configuration       */
/*************************************/
void PreferenceDialog::Update_Configuration()
{

}

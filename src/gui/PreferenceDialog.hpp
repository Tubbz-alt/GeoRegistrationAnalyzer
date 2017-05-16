/**
 * @file    PreferencesDialog.hpp
 * @author  Marvin Smith
 * @date    5/16/2017
 */
#ifndef GUI_PREFERENCES_DIALOG_HPP
#define GUI_PREFERENCES_DIALOG_HPP

// Qt Libraries
#include <QDialog>

// Project Libraries
#include "../core/System_Configuration.hpp"


/**
 * @class PreferenceDialog
 */
class PreferenceDialog : public QDialog
{
    public:

        /**
         * @brief Constructor
         */
        PreferenceDialog( System_Configuration::ptr_t sys_config,
                          QWidget*                    parent = nullptr );


    protected:

        /**
         * @brief Initialize GUI
         */
        void Initialize_GUI();


    private:

        /**
         * @brief Update Configuration
         */
        void Update_Configuration();


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t  m_sys_config;

}; // End of PreferenceDialog


#endif
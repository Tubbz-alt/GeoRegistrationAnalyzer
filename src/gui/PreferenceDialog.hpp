/**
 * @file    PreferencesDialog.hpp
 * @author  Marvin Smith
 * @date    5/16/2017
 */
#ifndef GUI_PREFERENCES_DIALOG_HPP
#define GUI_PREFERENCES_DIALOG_HPP

// C++ Libraries
#include <mutex>
#include <thread>


// Qt Libraries
#include <QDialog>
#include <QTabWidget>
#include <QTableWidget>
#include <QVBoxLayout>

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


    public slots:

        /**
         * @brief Update the Configuration Table
         */
        void Update_Configuration_Table();

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

        /**
         * @brief Build the Configuration Panel
         */
        void Build_Configuration_Panel();


        /**
         * @brief Build the logging panel
         */
        void Build_Logging_Panel();


        /// Class Name
        std::string m_class_name;

        /// Main Layout
        QVBoxLayout* m_main_layout;

        /// Stack Widget
        QTabWidget* m_main_widget;

        /// Configuration Table
        QTableWidget* m_config_option_list;

        /// System Configuration
        System_Configuration::ptr_t  m_sys_config;

        /// COnfig option mutex
        std::mutex m_config_option_list_lock;

        std::thread m_config_option_thread;

}; // End of PreferenceDialog


#endif
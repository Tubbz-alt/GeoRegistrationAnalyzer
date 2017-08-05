/**
 * @file    ConfigurationSaveDialog.hpp
 * @author  Marvin Smith
 * @date    5/16/2017
 */
#ifndef GUI_CONFIGURATION_SAVE_DIALOG_HPP
#define GUI_CONFIGURATION_SAVE_DIALOG_HPP

// Qt Libraries
#include <QDialog>
#include <QLineEdit>
#include <QToolButton>


// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>


/**
 * @class ConfigurationSaveDialog
 */
class ConfigurationSaveDialog : public QDialog
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        ConfigurationSaveDialog( System_Configuration::ptr_t sys_config,
                                 QWidget*                    parent = 0 );

        /**
         * @brief Check if we are saving the config file
         *
         */
        inline bool Save_Configuration()const{
            return m_save_config;
        }


    public slots:

        /**
         * @brief Save Action
         */
        void Save_Action();

        /**
         * @brief Cancel Action
         */
        void Cancel_Action();


        /**
         * @brief Update Configuration Path
         */
        void Update_Pathname();

    protected:

        /**
         * @brief Initialize the GUI
         */
        void Initialize_GUI();


    private:

        /**
         * @brief Initialize Configuration
         */
        void Initialize_Configuration();


        /// Class Name
        std::string m_class_name;

        /// Save Configuration File
        bool m_save_config;

        /// Pathname Edit
        QLineEdit* m_pathname_line_edit;

        /// Pathname Edit Button
        QToolButton* m_pathname_button;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

}; // End of ConfigurationSaveDialog Class


#endif
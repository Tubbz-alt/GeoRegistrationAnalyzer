/**
 * @file    ImportAssetDialog.hpp
 * @author  Marvin Smith
 * @date    8/6/2017
 */
#ifndef GEO_VIEWER_GUI_IMPORT_ASSET_DIALOG_HPP
#define GEO_VIEWER_GUI_IMPORT_ASSET_DIALOG_HPP

// Qt Libraries
#include <QDialog>
#include <QVBoxLayout>


// Geo-Viewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>


/**
 * @class ImportAssetDialog
 */
class ImportAssetDialog : public QDialog
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        ImportAssetDialog( System_Configuration::ptr_t sys_config,
                           QWidget*                    parent = nullptr );


    private:

        /**
         * @brief Initialize Configuration
         */
        void Initialize_Configuration();


        /**
         * @brief Initialize the GUI
         */
        void Initialize_GUI();


        /**
         * @brief Initialize
         */


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Layout
        QVBoxLayout* m_main_layout;


}; // End of ImportAssetDialog Class

#endif
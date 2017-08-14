/**
 * @file    ImportAssetDialog.hpp
 * @author  Marvin Smith
 * @date    8/6/2017
 */
#ifndef GEO_VIEWER_GUI_IMPORT_ASSET_DIALOG_HPP
#define GEO_VIEWER_GUI_IMPORT_ASSET_DIALOG_HPP

// Qt Libraries
#include <QDialog>
#include <QFileDialog>
#include <QLabel>
#include <QStackedWidget>
#include <QToolButton>
#include <QVBoxLayout>

// C++ Libraries
#include <map>

// Geo-Viewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>

// Project Libraries
#include "ImportAssetEasyWidget.hpp"


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

    public slots:


        /**
         * @brief Reset Requested
         */
        void Reset_Action();


        /**
         * @brief Import Requested
         */
        void Import_Action();


        /**
         * @brief Cancel Action
         */
        void Cancel_Action();


        /**
         * @brief Set Panel ID
         */
        void Set_Panel_Index( int index );


        /**
         * @brief Show the Easy Import Pane
         */
        void Show_Easy_Import_Pane();


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
         * @brief Create Title Widget
         */
        void Build_Title_Pane();


        /**
         * @brief Build Easy Import Widget
         */
        void Build_Easy_Import_Pane();


        /**
         * @brief Build Advanced Import Widget
         */
        void Build_Advanced_Import_Pane();


        /**
         * @brief Build Toolbar
         */
        void Build_Toolbar();


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Layout
        QVBoxLayout* m_main_layout;

        /// Stack Widget
        QStackedWidget* m_import_viewer_stack;

        /// Easy Import Widget
        ImportAssetEasyWidget* m_easy_import_widget;


}; // End of ImportAssetDialog Class

#endif
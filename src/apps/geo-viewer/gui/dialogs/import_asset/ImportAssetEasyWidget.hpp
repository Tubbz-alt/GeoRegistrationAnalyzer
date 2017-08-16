/**
 * @file    ImportAssetEasyWidget.hpp
 * @author  Marvin Smith
 * @date    8/12/2017
 */
#ifndef GEO_VIEWER_GUI_IMPORT_ASSET_EASY_WIDGET_HPP
#define GEO_VIEWER_GUI_IMPORT_ASSET_EASY_WIDGET_HPP

// Qt Libraries
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

// C++ Libraries
#include <string>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>


/**
 * @class ImportAssetEasyWidget
 */
class ImportAssetEasyWidget : public QWidget
{
    Q_OBJECT

    signals:

        void Enable_Import_Button();

    public:

        /**
         * @brief Constructor
         */
        ImportAssetEasyWidget( System_Configuration::ptr_t sys_config,
                               QWidget*                    parent = nullptr );

    public slots:

        /**
         * @brief Reset the Widget
         */
        void Reset_Action();


        /**
         * @brief Response to when select file button is pressed.
         */
        void Select_File_Action();


        /**
         * @brief  Notify Asset Is Valid
         */
        void Notify_Asset_Valid();

    private:

        /**
         *
         */
        void Initialize_GUI();

        /**
         * @brief Build the Path Widget
         */
        void Build_Path_Widget();

        /**
         * @brief Build the Info Widget
         */
        void Build_Info_Widget();

        /**
         * @brief Process Asset
         */
        void Check_Asset_Info( const std::string& asset_path );


        /**
         * @brief Replace the info panel to show
         * @param widget
         */
        void Replace_Info_Panel( QWidget* widget );


        /// Class Name
        std::string m_class_name;

        /// Easy Import Layout
        QGridLayout* m_main_layout;

        /// Easy Import Path
        QLabel* m_path_label;

        /// Active Asset Information
        QWidget* m_info_panel;

}; // End of ImportAssetEasyWidget Class


#endif
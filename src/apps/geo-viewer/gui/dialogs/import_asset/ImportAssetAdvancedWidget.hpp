/**
 * @file    ImportAssetEasyWidget.hpp
 * @author  Marvin Smith
 * @date    8/12/2017
 */
#ifndef GEO_VIEWER_GUI_IMPORT_ASSET_ADVANCED_WIDGET_HPP
#define GEO_VIEWER_GUI_IMPORT_ASSET_ADVANCED_WIDGET_HPP

// Qt Libraries
#include <QGridLayout>
#include <QLabel>
#include <QVBoxLayout>

// C++ Libraries
#include <string>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>


/**
 * @class ImportAssetAdvancedWidget
 */
class ImportAssetAdvancedWidget : public QWidget
{
    Q_OBJECT

    signals:

        void Enable_Import_Button();

    public:

        /**
         * @brief Constructor
         */
        ImportAssetAdvancedWidget( System_Configuration::ptr_t sys_config,
                                   QWidget*                    parent = nullptr );


        /**
         * @brief Get Asset Information
         */
        Config_Param Get_Asset_Info()const;

    public slots:

        /**
         * @brief Reset the Widget
         */
        void Reset_Action();


        /**
         * @brief  Notify Asset Is Valid
         */
        void Notify_Asset_Valid();

    private:

        /**
         * @brief Initialize GUI Objects
         */
        void Initialize_GUI();


        /// Class Name
        std::string m_class_name;

        /// Easy Import Layout
        QGridLayout* m_main_layout;


}; // End of ImportAssetAdvancedWidget Class


#endif
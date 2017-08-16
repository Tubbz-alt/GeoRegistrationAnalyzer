/**
 * @file    Asset_Info_Widget_ESRI.hpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#ifndef GEO_VIEWER_GUI_ASSET_INFO_WIDGET_ESRI_HPP
#define GEO_VIEWER_GUI_ASSET_INFO_WIDGET_ESRI_HPP

// C++ Libraries
#include <string>
#include <tuple>
#include <vector>

// Qt Libraries
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QTableWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

// Project Libraries
#include "Asset_Info_Widget_Base.hpp"


/**
 * @class Asset_Info_Widget_ESRI
 */
class Asset_Info_Widget_ESRI : public Asset_Info_Widget_Base
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        Asset_Info_Widget_ESRI( const Config_Param& asset_info,
                                QWidget*            parent = nullptr );


        /**
         * @brief Destructor
         */
        virtual ~Asset_Info_Widget_ESRI();


        /**
         * @brief Get the Name
         */
        virtual std::string Get_Generator_Name()const{
            return "esri";
        }

    public slots:

        /**
         * @brief Update Table Widget Fields
         */
        void Update_Table_Data();

    private:

        /**
         * @brief Initialize the GUI
         */
        void Initialize_GUI();

        /**
         * @brief Build Table Widget
         */
        void Build_Table_Widget();


        /**
         * @brief Build the Status Widget
         */
        void Build_Status_Widget();

        /// Class Name
        std::string m_class_name;

        /// Main Layout
        QVBoxLayout* m_main_layout;

        /// Status Widget
        QGroupBox* m_status_group;
        QGridLayout* m_status_layout;
        QLabel* m_status_label;
        QTextEdit* m_status_details;

        /// Asset Info Widget
        QGroupBox* m_info_group;
        QVBoxLayout* m_info_layout;
        QTableWidget* m_info_table;
        std::vector<std::tuple<std::string,std::string>> m_asset_info_list;

}; // End of Asset_Info_Widget_Base Class

#endif
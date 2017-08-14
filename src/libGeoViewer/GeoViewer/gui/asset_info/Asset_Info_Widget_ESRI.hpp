/**
 * @file    Asset_Info_Widget_ESRI.hpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#ifndef GEO_VIEWER_GUI_ASSET_INFO_WIDGET_ESRI_HPP
#define GEO_VIEWER_GUI_ASSET_INFO_WIDGET_ESRI_HPP

// Qt Libraries
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

// Project Libraries
#include "Asset_Info_Widget_Base.hpp"


/**
 * @class Asset_Info_Widget_ESRI
 */
class Asset_Info_Widget_ESRI : public Asset_Info_Widget_Base
{
    //Q_OBJECT

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

    private:

        /**
         * @brief Initialize the GUI
         */
        void Initialize_GUI();

        /// Class Name
        std::string m_class_name;

        /// Main Layout
        QVBoxLayout* m_main_layout;

}; // End of Asset_Info_Widget_Base Class

#endif
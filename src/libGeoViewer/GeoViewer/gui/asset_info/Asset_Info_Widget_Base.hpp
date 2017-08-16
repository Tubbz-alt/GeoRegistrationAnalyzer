/**
 * @file    Asset_Info_Widget_Base.hpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#ifndef GEO_VIEWER_GUI_ASSET_INFO_WIDGET_BASE_HPP
#define GEO_VIEWER_GUI_ASSET_INFO_WIDGET_BASE_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/Config_Param.hpp"


class Asset_Info_Widget_Base : public QWidget
{
    Q_OBJECT

    signals:

        void Valid_Asset();

    public:

        /**
         * @brief Constructor
         */
        Asset_Info_Widget_Base( const Config_Param& asset_info,
                                QWidget*            parent = nullptr );


        /**
         * @brief Destructor
         */
        virtual ~Asset_Info_Widget_Base();


        /**
         * @brief Get the Name
         */
        virtual std::string Get_Generator_Name()const{
            return "base";
        }


        inline virtual bool Is_Valid_Asset()const{
            return m_valid_asset;
        }

    protected:

        /// Asset Info
        Config_Param m_asset_info;

        bool m_valid_asset;
        std::string m_asset_status;

    private:

        /// Class Name
        std::string m_class_name;

}; // End of Asset_Info_Widget_Base Class

#endif
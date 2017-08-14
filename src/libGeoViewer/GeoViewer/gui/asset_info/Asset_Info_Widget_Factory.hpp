/**
 * @file    Asset_Info_Widget_Factory.hpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#ifndef GEO_VIEWER_GUI_ASSET_INFO_WIDGET_FACTORY_HPP
#define GEO_VIEWER_GUI_ASSET_INFO_WIDGET_FACTORY_HPP

// Project Libraries
#include "Asset_Info_Widget_Base.hpp"
#include "../../core/Config_Param.hpp"
#include "../../core/Status.hpp"


/**
 * @class Asset_Info_Widget_Factory
 */
class Asset_Info_Widget_Factory
{
    public:

        /**
         * @brief Create Asset Info Widget
         */
        Asset_Info_Widget_Base*  Create( const Config_Param& asset_info,
                                         QWidget*            parent,
                                         Status&             status );


}; // End of Asset_Info_Widget_Factory Class

#endif
/**
 * @file    Asset_Info_Widget_Factory.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "Asset_Info_Widget_Factory.hpp"

// Project Libraries
#include "../../log/System_Logger.hpp"
#include "Asset_Info_Widget_ESRI.hpp"

/********************************************/
/*          Create Asset Info Widget        */
/********************************************/
Asset_Info_Widget_Base* Asset_Info_Widget_Factory::Create(const Config_Param& asset_info,
                                                          QWidget*            parent,
                                                          Status&             status)
{
    // Log Entry
    const std::string m_class_name = "Asset_Info_Widget_Factory";
    LOG_CLASS_ENTRY();

    // Initialize Status
    status = Status::SUCCESS();
    Status temp_status = Status::SUCCESS();

    Asset_Info_Widget_Base* output = nullptr;

    // Get the Asset Name
    bool match_found;
    std::string asset_name = asset_info.Query_KV_Pair("asset.generator", match_found);
    if( !match_found )
    {
        status.Append( StatusType::FAILURE,
                       StatusReason::NOT_REGISTERED,
                       "No Matching asset info found (\"asset.generator\") Found.");
    }

    // Check if ESRI
    if( status.Not_Failure() && asset_name == "esri" )
    {
        output = new Asset_Info_Widget_ESRI( asset_info,
                                             parent );
    }

    // Otherwise, unregistered
    else if( status.Not_Failure() )
    {
        status.Append(StatusType::FAILURE,
                      StatusReason::NOT_REGISTERED,
                      "No Matching Asset-Info-Widget (" + asset_name + ") Found.");
    }

    // Log Exit
    LOG_CLASS_EXIT();
    return output;
}


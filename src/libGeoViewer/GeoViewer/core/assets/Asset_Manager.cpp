/**
 * @file    Asset_Manager.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "Asset_Manager.hpp"


// Global Instance
Asset_Manager::ptr_t local_inst;


/*********************************/
/*          Initialize           */
/*********************************/
void Asset_Manager::Initialize(System_Configuration::ptr_t sys_config)
{
    if( Get_Instance() == nullptr )
    {
        Get_Instance() = Asset_Manager::ptr_t(new Asset_Manager(sys_config));
    }
}


/*********************************/
/*          Initialize           */
/*********************************/
void Asset_Manager::Finalize()
{
    // Get instance
    local_inst = nullptr;
}


/**********************************/
/*          Register Asset        */
/**********************************/
int64_t Asset_Manager::Register_Asset(Asset_Base::ptr_t asset)
{
    // Asset ID
    int64_t asset_id = -1;

    // Make sure instance is not null
    if( Get_Instance() == nullptr )
    {
        std::cerr << "Assset_Manager is currently null." << std::endl;
    }

    else
    {
        // Generate an id
        asset_id = Get_Instance()->m_assets.size();

        Get_Instance()->m_assets[asset_id] = asset;

        // Notify Message Service
        if( Get_Instance()->m_message_service )
        {
            Get_Instance()->m_message_service->Send("ASSET_MANAGER","ASSET_REGISTERED " + std::to_string(asset_id));
        }
    }

    return asset_id;
}


/*************************************/
/*          Query the Asset          */
/*************************************/
Asset_Base::ptr_t Asset_Manager::Query_Asset( const int& asset_id )
{
    // Check if the asset exists
    if( Get_Instance()->m_assets.find(asset_id) != Get_Instance()->m_assets.end())
    {
        return Get_Instance()->m_assets.find(asset_id)->second;
    }
    return nullptr;
}


/*************************************/
/*          Query the Asset          */
/*************************************/
Asset_Base::ptr_t Asset_Manager::Query_Asset( const int&  asset_id,
                                              Status&     status )
{
    // Initialize Status
    status = Status::SUCCESS();

    // Check if the asset exists
    if( Get_Instance()->m_assets.find(asset_id) != Get_Instance()->m_assets.end())
    {
        return Get_Instance()->m_assets.find(asset_id)->second;
    }

    status.Append(StatusType::FAILURE,
                  StatusReason::NOT_REGISTERED,
                  "No Asset Found with ID (" + std::to_string(asset_id) + ")");
    return nullptr;
}


/************************************************/
/*          Register Message Service            */
/************************************************/
void Asset_Manager::Register_Message_Service(MessageService::ptr_t message_service)
{
    Get_Instance()->m_message_service = message_service;
}


/*********************************/
/*          Constructor          */
/*********************************/
Asset_Manager::Asset_Manager(System_Configuration::ptr_t sys_config)
  : m_class_name("Asset_Manager"),
    m_sys_config(sys_config)
{

}


/***********************************/
/*         Get an Instance         */
/***********************************/
Asset_Manager::ptr_t& Asset_Manager::Get_Instance()
{
    return local_inst;
}

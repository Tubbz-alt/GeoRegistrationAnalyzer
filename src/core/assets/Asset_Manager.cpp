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
    // Get instance
    Asset_Manager::ptr_t inst = Get_Instance();

    if( inst == nullptr )
    {

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

    // Get an instance
    auto inst = Get_Instance();

    // Generate an id
    int64_t asset_id = inst->m_assets.size();

    inst->m_assets[asset_id] = asset;

    return asset_id;
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
Asset_Manager::ptr_t Asset_Manager::Get_Instance()
{
    return local_inst;
}

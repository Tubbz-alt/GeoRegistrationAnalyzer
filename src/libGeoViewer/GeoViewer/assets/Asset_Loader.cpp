/**
 * @file    Asset_Loader.cpp
 * @author  Marvin Smith
 * @date    8/12/2017
 */
#include "Asset_Loader.hpp"

// Boost Libraries
#include <boost/filesystem.hpp>

// C++ Libraries
#include <memory>

// Project Libraries
#include "../log.hpp"


// Single-Copy
static std::shared_ptr<Asset_Loader> loader_ref;


/************************************************/
/*          Initialize the Asset Loader         */
/************************************************/
void Asset_Loader::Initialize(Status &status)
{
    // Initialize the status
    status = Status::SUCCESS();

    // Create the instance
    if( loader_ref == nullptr ) {
        Get_Instance() = std::shared_ptr<Asset_Loader>(new Asset_Loader());
    }
    else
    {
        status.Append( StatusType::WARNING,
                       StatusReason::ALREADY_INITIALIZED,
                       "Asset Loader Already Initialized.");
    }

}


/************************************************/
/*          Finalize the Asset Loader           */
/************************************************/
void Asset_Loader::Finalize(Status &status)
{
    // Initialize Status
    status = Status::SUCCESS();

    Get_Instance().reset();
}


/***************************************************/
/*              Register Asset Generator           */
/***************************************************/
void Asset_Loader::Register_Asset_Generator(Asset_Generator_Base::ptr_t asset_generator)
{
    // Make sure we are initialized
    Get_Instance()->m_generators[asset_generator->Get_Generator_Name()] = asset_generator;
}


/*******************************************************/
/*               Load Asset Information                */
/*******************************************************/
Config_Param Asset_Loader::Load_File_Asset_Info( const std::string&  pathname,
                                                 Config_Param&       config_options,
                                                 Status&             status )
{
    // Initialize Status
    status = Status::SUCCESS();
    Status temp_status = Status::SUCCESS();
    std::string error_message;

    // CHeck if config-optiosn contains specific driver
    bool match_found = false;
    std::string generator_name = config_options.Query_KV_Pair("generator",match_found);

    // If Generator Name is specified
    if( generator_name != "" )
    {
        // Make sure the generator exists
        if( Get_Instance()->m_generators.find(generator_name) == Get_Instance()->m_generators.end() )
        {
            status.Append(StatusType::FAILURE,
                          StatusReason::UNINITIALIZED,
                          "No Generator found with name (" + generator_name + ")" );
            return Config_Param();
        }

        // If it does
        else
        {
            // Process
            if( Get_Instance()->m_generators[generator_name]->Is_Valid_Asset_Path(pathname, error_message ) )
            {
                return Get_Instance()->m_generators[generator_name]->Load_Asset_Info( pathname,
                                                                                      status);
            }
            else
            {
                status.Append(StatusType::FAILURE,
                              StatusReason::UNKNOWN,
                              "Unable to load asset info. MSG: " + error_message);
                return Config_Param();
            }
        }
    }

    // Otherwise,
    else
    {
        for (auto generator : Get_Instance()->m_generators)
        {
            if (generator.second->Is_Valid_Asset_Path(pathname, error_message))
            {
                return generator.second->Load_Asset_Info(pathname,
                                                         status);
            }
        }
    }

    status.Append( StatusType::FAILURE,
                   StatusReason::NOT_REGISTERED,
                   "No Matching Asset-Generators Found.");
    return Config_Param();
}


/********************************/
/*          Load an Asset       */
/********************************/
Asset_Base::ptr_t Asset_Loader::Load_Asset(const Config_Param&  asset_info,
                                           Status&              status)
{
    // Log Entry
    const std::string m_class_name = "Asset_Loader";
    LOG_CLASS_ENTRY();

    // Initialize Status
    status = Status::SUCCESS();
    Status temp_status = Status::SUCCESS();
    bool value_found;

    // Grab Asset Name
    std::string asset_name = asset_info.Query_KV_Pair("asset.generator", value_found );

    if( !value_found )
    {
        status.Append(StatusType::FAILURE,
                      StatusReason::NOT_REGISTERED,
                      "No Matching Generator Found (Asset Generator: " + asset_name + ").");
    }

    // Otherwise, iterate over generators
    else
    {
        for (auto generator : Get_Instance()->m_generators)
        {
            // Check Instance
            if( generator.second == nullptr )
            {
                status.Append(StatusType::FAILURE,
                              StatusReason::UNINITIALIZED,
                              "Asset-Loader is initialized yet has null generator registered.");
            }

            // Otherwise, continue
            else if (generator.second->Get_Generator_Name() == asset_name)
            {
                return generator.second->Load_Asset(asset_info,
                                                    status);
            }
        }
    }

    status.Append( StatusType::FAILURE,
                   StatusReason::NOT_REGISTERED,
                   "No Matching Asset-Generators Found.");
    return nullptr;
}


/****************************************/
/*          Get Loader Instance         */
/****************************************/
std::shared_ptr<Asset_Loader>&  Asset_Loader::Get_Instance()
{
    return loader_ref;
}


/********************************/
/*          Constructor         */
/********************************/
Asset_Loader::Asset_Loader()
 : m_class_name("Asset_Loader")
{
}

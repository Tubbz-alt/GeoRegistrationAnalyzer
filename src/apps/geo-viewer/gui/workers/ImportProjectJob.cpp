/**
 * @file    ImportProjectJob.cpp
 * @author  Marvin Smith
 * @date    8/6/2017
 */
#include "ImportProjectJob.hpp"

// C++ Libraries
#include <sstream>
#include <vector>

// Qt Libraries
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

// GeoViewer Libraries
#include <GeoViewer/core/System_Manager.hpp>
#include <GeoViewer/assets/local/Asset_Local_Base.hpp>
#include <GeoViewer/assets/Asset_Manager.hpp>
#include <GeoViewer/io/GDAL_Image_Loader.hpp>
#include <GeoViewer/log/System_Logger.hpp>


/*********************************/
/*          Constructor          */
/*********************************/
ImportProjectJob::ImportProjectJob( const Config_Param&         project_info,
                                    System_Configuration::ptr_t sys_config)
  : m_class_name("ImportProjectJob"),
    m_sys_config(sys_config),
    m_project_info(project_info)
{

}


/*****************************/
/*          Execute          */
/*****************************/
int ImportProjectJob::Execute()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Build the Reference Imagery Asset
    Build_Image_Asset("reference",
                      "project.reference_imagery");

    // Build the Test Imagery Asset
    Build_Image_Asset("test",
                      "project.test_imagery");


    // Log Exit
    LOG_CLASS_EXIT();

    return 1;
}


/********************************************/
/*          Build the Image Asset           */
/********************************************/
void ImportProjectJob::Build_Image_Asset( const std::string& panel_type,
                                          const std::string& base_element )const
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Resulting Asset
    Asset_Local_Base::ptr_t new_asset;

    // JSon Elements
    QJsonObject json_obj;

    // Grab the source type
    bool value_found, success, first_asset_loaded = false;
    std::string error_msg;
    int asset_id;
    std::string source = m_project_info.Query_KV_Pair(base_element + ".source", value_found);
    json_obj["source"] = source.c_str();


    // Check source type
    if( source == "local" )
    {
        // Get the file list, if so
        std::string list_type = m_project_info.Query_KV_Pair(base_element + ".local.path_list_format", value_found);
        std::vector<std::string> image_path_list;
        LOG_CLASS_TRACE("Local Asset Path List Type: " + list_type );

        if( list_type == "file" )
        {
            /*
            std::string list_path = m_project_info.Query_KV_Pair(base_element + ".local.path_list_string", value_found);
            LOG_CLASS_TRACE("Local Asset Path List String: " + list_path);
            image_path_list = Image_Asset_Builder::Load_Path_File(list_path, success, error_msg);

            if( !success )
            {
                LOG_CLASS_ERROR(error_msg);
            }*/
        }

        // Get the type
        std::string local_type = m_project_info.Query_KV_Pair(base_element + ".local.type", value_found);
        LOG_CLASS_TRACE("Local Asset Driver: " + local_type);


        // if GDAL
        if( local_type == "gdal" )
        {
            // Load Files
            for( auto fname : image_path_list )
            {
                /*
                LOG_CLASS_TRACE("Loading Image: " + fname);

                // Create asset
                new_asset = GDAL_Image_Loader::Load_Image( fname, success, error_msg);

                // Check status
                if( !success )
                {
                    LOG_CLASS_ERROR(error_msg);
                }
                // Process
                else
                {
                    // Register asset
                    asset_id = Asset_Manager::Register_Asset(new_asset);
                    if( !first_asset_loaded )
                    {
                        json_obj["asset_id"] = asset_id;
                        first_asset_loaded = true;
                    }
                }
                 */
            }
        }
    }

    // Send the Comm Message
    if( first_asset_loaded )
    {
        // Create message
        std::stringstream sin;
        QJsonDocument json_doc(json_obj);

        sin << json_doc.toJson().toStdString();
        System_Manager::Get_Message_Service()->Send( "imagery_load",
                                                     sin.str());
    }
}

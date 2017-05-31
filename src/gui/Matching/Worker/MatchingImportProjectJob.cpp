/**
 * @file    MatchingImportProjectJob.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "MatchingImportProjectJob.hpp"

// C++ Libraries
#include <vector>


// Project Libraries
#include "../../../core/assets/Asset_Image_Local.hpp"
#include "../../../core/assets/Image_Asset_Builder.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
MatchingImportProjectJob::MatchingImportProjectJob(const Config_Param&         project_info,
                                                   System_Configuration::ptr_t sys_config)
  : m_class_name("MatchingImportProjectJob"),
    m_sys_config(sys_config),
    m_project_info(project_info)
{

}


/*****************************/
/*          Execute          */
/*****************************/
int MatchingImportProjectJob::Execute()
{

    // Build the Reference Imagery Asset
    Build_Image_Asset("project.matching.reference_imagery");

    // Build the Test Imagery Asset
    Build_Image_Asset("project.matching.test_imagery");



    return 1;
}


/********************************************/
/*          Build the Image Asset           */
/********************************************/
void MatchingImportProjectJob::Build_Image_Asset( const std::string& base_element )const
{
    // Grab the source type
    bool value_found, success;
    std::string source = m_sys_config->Query_Config_Param(base_element + ".source", value_found);

    // Check source type
    if( source == "local" )
    {
        // Get the file list, if so
        std::string list_type = m_sys_config->Query_Config_Param(base_element + ".path_list_format", value_found);
        std::vector<std::string> path_list;

        if( list_type == "file" )
        {

            std::string list_path = m_sys_config->Query_Config_Param(base_element + ".path_list_string", value_found);
            path_list = Image_Asset_Builder::Load_Path_File(list_path, success);
        }

        // Get the type
        std::string local_type = m_sys_config->Query_Config_Param(base_element + ".type", value_found);

        // if GDAL
        if( local_type == "gdal" )
        {
            // Load Files
            for( auto fname : path_list )
            {
                std::cout << "Loading Path: " << fname << std::endl;
            }
        }
    }

}

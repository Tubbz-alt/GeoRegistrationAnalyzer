/**
 * @file    MatchingImportProjectJob.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "MatchingImportProjectJob.hpp"


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

    // Check the desired driver types
    bool value_found;
    std::string driver_type_ref = m_project_info.Query_KV_Pair("project.matching.reference_imagery.source", value_found);
    std::string driver_type_tst = m_project_info.Query_KV_Pair("project.matching.test_imagery.source", value_found);

    // Process the reference type first
    return 1;
}
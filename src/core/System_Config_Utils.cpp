/**
 * @file    System_Config_Utils.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include "System_Config_Utils.hpp"

/****************************************/
/*      Generate Default Parameters     */
/****************************************/
Config_Param Generate_Default_Parameters()
{
    // Create output map
    Config_Param output;

    // Determine OS Name
    std::string os_name = "UNKNOWN";
#ifdef __linux__
    os_name = "LINUX";
#endif


    //  Add Default Logging Options

    output.Add_KV_Pair("system.logging.level",       "info", "#  Default Logging Level");
    output.Add_KV_Pair("system.logging.file_enabled", "true", "#  Logging to File Enabled");

    //  Add OS Options
    output.Add_KV_Pair("system.os.name",  os_name, "#  Name of Operating System");


    // Send outputs
    return output;
}

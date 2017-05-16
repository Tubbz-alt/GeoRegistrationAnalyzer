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
    std::string home_dir = getenv("HOME");
#ifdef __linux__
    os_name = "LINUX";
#endif

    // Determine Default Config Pathname
    std::string config_pathname;
    if( os_name == "WINDOWS" )
    {

    }
    else
    {
        config_pathname = home_dir + "/.geo-registration-analyzer.cfg";
    }

    // Add default configuration path
    output.Add_KV_Pair("system.config_pathname", config_pathname, "# Default Configuration File Pathname.");

    //  Add Default Logging Options
    output.Add_KV_Pair("system.logging.level",       "info", "#  Default Logging Level");
    output.Add_KV_Pair("system.logging.file_enabled", "true", "#  Logging to File Enabled");

    //  Add OS Options
    output.Add_KV_Pair("system.os.name",  os_name, "#  Name of Operating System");


    // Send outputs
    return output;
}

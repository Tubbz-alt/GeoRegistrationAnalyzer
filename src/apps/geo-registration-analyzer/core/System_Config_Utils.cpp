/**
 * @file    System_Config_Utils.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include "System_Config_Utils.hpp"

/****************************************/
/*      Generate Default Parameters     */
/****************************************/
Config_Param Viewer_Config_Generator::Generate()
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
    std::string icon_path = std::string(getenv("GEO_VIEWER_BASE")) + "/icons";
    std::string html_path = "file://" + std::string(getenv("GEO_VIEWER_BASE")) + "/html";
    std::string project_base_path = std::string(getenv("HOME")) + "/.geo-viewer";
    if( os_name == "WINDOWS" )
    {

    }
    else
    {
        config_pathname = home_dir + "/.geo-viewer/options.cfg";
    }

    // Add HTML and Icon Path
    output.Add_KV_Pair("system.core.project_base", project_base_path, "#  Base Project Directory");
    output.Add_KV_Pair("system.core.html_path", html_path, "#  HTML Path");
    output.Add_KV_Pair("system.core.icon_path", icon_path, "#  Icon Path");

    // Add default configuration path
    output.Add_KV_Pair("system.config_pathname", config_pathname, "# Default Configuration File Pathname.");

    //  Add Default Logging Options
    output.Add_KV_Pair("system.logging.file.level",   "info", "#  Default Logging Level");
    output.Add_KV_Pair("system.logging.file.enabled", "true", "#  Logging to File Enabled");
    output.Add_KV_Pair("system.logging.file.pathname", "~/.geo-viewer/output.log", "#  Path to Log File");

    output.Add_KV_Pair("system.logging.console.level",   "debug", "#  Default Logging Level");
    output.Add_KV_Pair("system.logging.console.enabled", "true",  "#  Logging Enabled Flag");

    output.Add_KV_Pair("system.logging.qt.enabled",  "true",  "#  Logging Enabled Flag");
    output.Add_KV_Pair("system.logging.qt.level",    "debug", "#  Logging Level");


    //  Add OS Options
    output.Add_KV_Pair("system.os.name",  os_name, "#  Name of Operating System");


    // Send outputs
    return output;
}

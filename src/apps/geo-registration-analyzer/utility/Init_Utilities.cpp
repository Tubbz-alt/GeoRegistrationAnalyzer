/**
 * @file    Init_Utilities.cpp
 * @author  Marvin Smith
 * @date    4/20/2017
 */
#include "Init_Utilities.hpp"

// Project Libraries
#include "../../../libGeoViewer/log/Log_Handler_Console.hpp"
#include "../../../libGeoViewer/log/Log_Handler_File.hpp"


/**************************************/
/*         Initialize Logging         */
/**************************************/
void Initialize_Logging( const System_Configuration::ptr_t sys_config )
{
    // Check the sys config
    if( sys_config == nullptr )
    {
        throw std::runtime_error("System-Configuration is null.");
    }

    // Build the list of log handlers
    bool value_found;
    std::string value, level_str;
    LogSeverity log_level;
    std::vector<Log_Handler_Base::ptr_t> log_handlers;


    // Check if file logging enabled
    std::cout << "Querying Parameter" << std::endl;
    value     = sys_config->Query_Config_Param("system.logging.file.enabled", value_found);

    if( !value_found )
    {
        throw std::runtime_error("Unable to find File Logging Configuration Param. Returned: " + value);
    }

    if( value == "true" )
    {
        // Get the log level
        level_str = sys_config->Query_Config_Param("system.logging.file.level", value_found);
        log_level = StringToLogSeverity(level_str);

        Log_Handler_Config_File::ptr_t file_config = std::make_shared<Log_Handler_Config_File>( log_level );
        log_handlers.push_back(std::make_shared<Log_Handler_File>(file_config));
    }


    // Check if Console Logging Enabled
    value = sys_config->Query_Config_Param("system.logging.console.enabled", value_found);
    if( !value_found )
    {
        throw std::runtime_error("Unable to find Console Logging Configuration Param.");
    }

    if( value == "true" )
    {
        // Get the log level
        level_str = sys_config->Query_Config_Param("system.logging.console.level", value_found);
        if( value_found ){ std::cout << "LEVEL: " << level_str << std::endl; }
        else{ std::cout << "NO LEVEL FOUND!" << std::endl;}
        log_level = StringToLogSeverity(level_str);


        Log_Handler_Config_Console::ptr_t console_config = std::make_shared<Log_Handler_Config_Console>( log_level );
        log_handlers.push_back(std::make_shared<Log_Handler_Console>(console_config));
    }

    // Create output
    System_Logger::Initialize( sys_config, log_handlers );

    // Test Output
    LOG_INFO( "Logging Initialized" );
}
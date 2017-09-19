/**
 * @file    Test_Options.cpp
 * @author  Marvin Smith
 * @date    9/15/2017
 */
#include "Test_Options.hpp"

// C++ Libraries
#include <deque>
#include <iostream>

// GeoViewer Libraries
#include <GeoViewer/log/Log_Handler_Console.hpp>


/********************************/
/*          Constructor         */
/********************************/
Test_Options::Test_Options(int argc, char **argv)
 : m_class_name("Test_Options")
{
    // Parse the Command-Line
    Parse_Command_Line(argc, argv);

    // Initialize Logging
    Initialize_Logging();

}


/********************************************/
/*          Parse the Command Line          */
/********************************************/
void Test_Options::Parse_Command_Line( int argc, char* argv[] )
{
    // Set the Application Name
    m_application_name = argv[0];

    // The the rest into list
    std::deque<std::string> args;
    for( int i=1; i<=(argc-1); i++ )
    {
        args.push_back(argv[i]);
    }


    // Iterate over command-line options
    std::string arg;
    while( args.size() > 0 )
    {
        // Pop next argument
        arg = args.front();
        args.pop_front();

        // Process the arguments
        if( arg == "-v" )
        {
            m_log_severity = LogSeverity::DEBUG;
        }
        if( arg == "-vv" )
        {
            m_log_severity = LogSeverity::TRACE;
        }

        // Otherwise, ignore (for now)
    }
}


/****************************************/
/*          Initialize Logging          */
/****************************************/
void Test_Options::Initialize_Logging()
{
    // Create dummy system-configuration
    System_Configuration::ptr_t sys_config;

    // Create the console config
    auto console_config = std::make_shared<Log_Handler_Config_Console>(m_log_severity);

    // Create the log handlers
    std::vector<Log_Handler_Base::ptr_t> log_handlers;
    log_handlers.push_back(std::make_shared<Log_Handler_Console>(console_config));


    // Initialize the Logger
    System_Logger::Initialize( sys_config,
                               log_handlers );

    // Make first log message
    LOG_FUNCTION_INFO("Logger Initialized");
}

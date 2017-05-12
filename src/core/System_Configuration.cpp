/**
 * @file    System_Configuration.cpp
 * @author  Marvin Smith
 * @date    4/21/2017
 */
#include "System_Configuration.hpp"

// C++ Libraries
#include <deque>
#include <iostream>

// Boost Libraries
#include <boost/filesystem.hpp>

using namespace bf = boost::filesystem;

/****************************************/
/*              Constructor             */
/****************************************/
System_Configuration::System_Configuration( int argc, char* argv[] )
 : m_class_name("System_Configuration")
{
    // Parse the Command-Line
    Parse_Command_Line( argc, argv );

    // Parse the Configuration File


}


/**************************************/
/*             Finalize               */
/**************************************/
void System_Configuration::Finalize()
{



}


/********************************************/
/*          Parse the Command-Line          */
/********************************************/
void System_Configuration::Parse_Command_Line(int argc, char **argv)
{
    // Set the Application Name
    m_application_name = argv[0];

    // The the rest into list
    std::deque<std::string> args;
    for( int i=1; i<=argc; i++ )
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

        // Check for config file flag
        if( arg == "-c")
        {
            // Make sure there is an argument left to parse
            if( args.size() <= 0 ){
                std::cerr << "No Arguments Left to Process" << std::endl;
            }

            m_config_pathname = args.front();
            args.pop_front();
        }

        // Otherwise, ignore (for now)
    }

}


/********************************************/
/*          Parse the COnfig File           */
/********************************************/
void System_Configuration::Parse_Configuration_File()
{
    // Check if the file exists
    if( !bf::exists(bf::path(m_config_pathname)))
    {
        std::cerr << "Config File (" << m_config_pathname << ") Does Not Exist." << std::endl;
        std::exit(-1);
    }

    // Otherwise, process
    else
    {

    }
}


/**********************************************/
/*         Generate a Configuration File      */
/**********************************************/
void System_Configuration::Generate_Configuration_File()
{

}


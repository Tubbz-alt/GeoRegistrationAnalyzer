/**
 * @file    geo-viewer.cpp
 * @author  Marvin Smith
 * @date    8/4/2017
*/

// Qt Libraries
#include <QApplication>

// GeoViewer Libraries
#include <GeoViewer/core/assets/Asset_Manager.hpp>
#include <GeoViewer/core/GeoViewer_Initialization.hpp>
#include <GeoViewer/core/Signal_Handlers.hpp>
#include <GeoViewer/core/System_Manager.hpp>
#include <GeoViewer/log/System_Logger.hpp>

// Project Libraries
#include "core/System_Config_Utils.hpp"
#include "gui/Main_Window.hpp"
#include "utility/Init_Utilities.hpp"

// OS Libraries
#include <csignal>


/**
 * @brief Main Method
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char* argv[] )
{
    // Dump the stack on a segmentation fault
    signal( SIGSEGV, Stack_Trace_Signal_Handler);

    // Create the Qt Application
    QApplication app(argc, argv);

    // Misc Variables
    Status status = Status::SUCCESS();
    Status temp_status = Status::SUCCESS();


    // Create the config file generator
    auto config_generator = std::make_shared<Viewer_Config_Generator>();

    // Load the Configuration
    auto system_config = std::make_shared<System_Configuration>(argc, argv,
                                                                config_generator);

    // Initialize the System Logger
    Initialize_Logging( system_config );


    // Initialize GeoViewer
    GEOVIEWER_INITIALIZE(temp_status);
    status.Append(temp_status);

    // Initialize the Asset-Manager
    Asset_Manager::Initialize( system_config );


    // Initialize System-Manager
    System_Manager::Initialize( system_config );
    auto system_manager = System_Manager::Get_Instance();


    // Create the Main Widget
    Main_Window* main_window = new Main_Window( system_config );


    // Load any Pre-Loaded Project Files
    if( system_config->Project_Path_Provided() )
    {
        LOG_TRACE("Project Path Provided. Loading: " + system_config->Get_Project_Pathname());
        main_window->Load_Project( system_config->Get_Project_Pathname() );
    }
    else
    {
        LOG_TRACE("Project Path Not Provided. Using Default Project Settings.");
    }

    // Show the GUI
    main_window->show();


    // Start the Application and Release Control
    return app.exec();
}
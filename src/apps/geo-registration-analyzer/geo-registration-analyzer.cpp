/**
 * @file    geo-registration-analyzer.cpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/

// Qt Libraries
#include <QApplication>

// GeoViewer Libraries
#include <GeoViewer/core/assets/Asset_Manager.hpp>
#include <GeoViewer/core/System_Manager.hpp>
#include <GeoViewer/log/System_Logger.hpp>

// Project Libraries
#include "core/System_Config_Utils.hpp"
#include "gui/Main_Window.hpp"
#include "utility/Init_Utilities.hpp"


/**
 * @brief Main Method
 *
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char* argv[] )
{
    
    //   Create the Qt Application
    QApplication app(argc, argv);

    // Create the config file generator
    auto config_generator = std::make_shared<Viewer_Config_Generator>();

    // Load the Configuration
    auto system_configuration = std::make_shared<System_Configuration>(argc, argv,
                                                                       config_generator );


    // Initialize the System Logger
    Initialize_Logging( system_configuration );


    // Initialize the Asset-Manager
    Asset_Manager::Initialize( system_configuration );


    // Initialize System-Manager
    System_Manager::Initialize( system_configuration );
    auto system_manager = System_Manager::Get_Instance();


    // Initialize the Message Service


    // Create the Main Widget
    Main_Window* main_window = new Main_Window( system_configuration );

    // Load any Pre-Loaded Project Files
    if( system_configuration->Project_Path_Provided() )
    {
        LOG_TRACE("Project Path Provided. Loading: " + system_configuration->Get_Project_Pathname());
        main_window->Load_Project( system_configuration->Get_Project_Pathname() );
    }
    else
    {
        LOG_TRACE("Project Path Not Provided. Using Default Project Settings.");
    }

    // Show the GUI
    main_window->show();

    // Start Application
    return app.exec();
}

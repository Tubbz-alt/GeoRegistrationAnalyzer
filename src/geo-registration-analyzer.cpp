/**
 * @file    geo-registration-analyzer.cpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/

// Qt Libraries
#include <QApplication>

// C++ Libraries


// Project Libraries
#include "core/System_Configuration.hpp"
#include "core/System_Manager.hpp"
#include "core/assets/Asset_Manager.hpp"
#include "log/System_Logger.hpp"
#include "gui/Main_Window.hpp"
#include "utility/Init_Utilities.hpp"


int main( int argc, char* argv[] )
{
    
    //   Create the Qt Application
    QApplication app(argc, argv);
    
    // Load the Configuration
    auto system_configuration = std::make_shared<System_Configuration>(argc, argv);


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
        main_window->Load_Project( system_configuration->Get_Project_Pathname() );
    }

    // Show the GUI
    main_window->show();

    // Start Application
    return app.exec();
}

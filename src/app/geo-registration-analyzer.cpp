/**
 * @file    geo-registration-analyzer.cpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/

// Qt Libraries
#include <QApplication>

// C++ Libraries


// Project Libraries
#include "core/System_Manager.hpp"


int main( int argc, char* argv[] )
{
    //  Build System Manager
    System_Manager system_manager;

    // Initialize
    system_manager.Initialize( argc, argv);

    //   Create the Qt Application
    QApplication app(argc, argv);


    // Exit Application
    return app.exec();
}

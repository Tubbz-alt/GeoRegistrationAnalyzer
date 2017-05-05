/**
 * @file    TEST_System_Configuration.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include <gtest/gtest.h>


// Project Libraries
#include <core/System_Configuration.hpp>


/*****************************************************/
/*          Simple Constructor Unit Test             */
/*****************************************************/
TEST( System_Configuration, Default_Constructor )
{
    // Create configuration
    int argc = 1;
    char** argv = new char*[1];
    argv[0] = "unit-test";

    System_Configuration config( argc, argv);

    delete [] argv;
}

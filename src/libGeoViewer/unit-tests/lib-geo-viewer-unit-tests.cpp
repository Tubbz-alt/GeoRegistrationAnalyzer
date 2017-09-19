/**
 * @file    lib-geo-viewer-unit-tests.cpp
 * @author  Marvin Smith
 * @date    8/25/2017
 */
#include <gtest/gtest.h>

// Project Libraries
#include "UNIT_TEST_ONLY/Test_Options.hpp"

// GDAL Libraries
#include <gdal.h>


/**
 * @brief Start Unit-Tests
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char* argv[] )
{
    // Parse Command-Line Options
    Test_Options options(argc, argv);

    // Init GDAL
    GDALAllRegister();

    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();

    return 0;
}
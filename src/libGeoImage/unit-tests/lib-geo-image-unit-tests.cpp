/**
 * @file    lib-geo-image-unit-tests.cpp
 * @author  Marvin Smith
 * @date    9/3/2017
 */
#include <gtest/gtest.h>


/**
 * @brief Start Unit-Tests
 * @param argc
 * @param argv
 * @return
 */
int main( int argc, char* argv[] )
{
    printf("Running main() from gtest_main.cc\n");
    testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();

    return 0;
}
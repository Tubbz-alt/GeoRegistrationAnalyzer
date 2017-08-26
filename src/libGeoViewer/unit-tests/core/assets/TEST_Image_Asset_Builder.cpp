/**
 * @file    TEST_Image_Asset_Builder.cpp
 * @author  Marvin Smith
 * @date    6/2/2017
 */
#include <gtest/gtest.h>


// Project Libraries
#include <core/assets/Image_Asset_Builder.hpp>


/**********************************************************/
/*          Test the Load_Path_File Method                */
/**********************************************************/
TEST( Image_Asset_Builder, Load_Path_File )
{
    // Create the test data paths
    std::string test_path_01 = "some-bad-path";
    std::string test_path_02 = "data/unit-tests-data/test-project-file-list-01.csv";

    // Run the method
    bool success;
    std::string error_msg;
    std::vector<std::string>  path_list;

    // Test 01 : Should Fail
    path_list = Image_Asset_Builder::Load_Path_File( test_path_01, success, error_msg);
    ASSERT_FALSE( success );
    ASSERT_EQ( path_list.size(), 0 );

    // Test 02 : Should Pass
    path_list = Image_Asset_Builder::Load_Path_File(  test_path_02, success, error_msg);
    ASSERT_TRUE( success );
    ASSERT_EQ( path_list.size(), 1);
    ASSERT_EQ( path_list[0], "/home/foo/test-path.jpg");

}
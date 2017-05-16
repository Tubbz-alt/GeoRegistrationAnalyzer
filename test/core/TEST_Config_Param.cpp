/**
 * @file    TEST_Config_Param.cpp
 * @author  Marvin Smith
 * @date    5/12/2017
 */
#include <gtest/gtest.h>


// Project Libraries
#include <core/Config_Param.hpp>


/*****************************************************/
/*          Test the Parse-Key Method                */
/*****************************************************/
TEST( Config_Param, Parse_Key )
{
    // Build Valid Test Keynames
    std::string key_name_01 = "system.logging.level";
    std::string key_name_02 = "System.logging.Log_file_enabled";

    std::vector<std::string> output_01 { "system", "logging", "level"};
    std::vector<std::string> output_02 { "System", "logging", "Log_file_enabled"};

    // Build Invalid Test Keynames
    std::string key_name_03 = "";
    std::string key_name_04 = "system..logging";

    std::vector<std::string> output_03;
    std::vector<std::string> output_04 { "system", "", "logging"};

    // Run Tests
    ASSERT_EQ( Config_Param::Parse_Key( key_name_01), output_01);
    ASSERT_EQ( Config_Param::Parse_Key( key_name_02), output_02);
    ASSERT_EQ( Config_Param::Parse_Key( key_name_03), output_03);
    ASSERT_EQ( Config_Param::Parse_Key( key_name_04), output_04);

}


/*****************************************************/
/*          Test the Subtract Key Method             */
/*****************************************************/
TEST( Config_Param, Pop_Key_Front )
{
    // Build Valid Test Keynames
    std::string key_name_01 = "system.logging.level";
    std::string key_name_02 = "System.logging.Log_file_enabled";
    std::string key_name_03 = "system.logging.a";

    std::string output_01 = "logging.level";
    std::string output_02 = "logging.Log_file_enabled";
    std::string output_03 = "logging.a";

    // Build Invalid Test Keynames
    std::string key_name_04 = "";
    std::string key_name_05 = "system..logging";

    std::string output_04 = "";
    std::string output_05 = ".logging";

    // Run Tests
    ASSERT_EQ( Config_Param::Pop_Key_Front( key_name_01), output_01);
    ASSERT_EQ( Config_Param::Pop_Key_Front( key_name_02), output_02);
    ASSERT_EQ( Config_Param::Pop_Key_Front( key_name_03), output_03);
    ASSERT_EQ( Config_Param::Pop_Key_Front( key_name_04), output_04);
    ASSERT_EQ( Config_Param::Pop_Key_Front( key_name_05), output_05);
}


/************************************************/
/*          Test the Add KV Pair Method         */
/************************************************/
TEST( Config_Param, Add_KV_Pair )
{
    // Create config
    Config_Param config;
    std::map<std::string,Config_Param> sub_configs;
    std::map<std::string,std::string>  kv_pairs;
    std::map<std::string,std::string>  comment_pairs;

    // Add Test Values
    config.Add_KV_Pair( "system.logging.level", "trace", "# Logging Level");
    config.Add_KV_Pair( "application_name", "Add_KV_Pair", "# Unit Test Title");

    // Get the SubConfigs
    sub_configs = config.Get_Sub_Configs();
    kv_pairs = config.Get_KV_Pairs();
    comment_pairs = config.Get_Comment_Pairs();

    // Check base name
    ASSERT_EQ( config.Get_Key_Name(), "base");

    // Check length
    ASSERT_EQ( sub_configs.size(), 1 );
    ASSERT_EQ( kv_pairs.size(), 1 );
    ASSERT_EQ( comment_pairs.size(), 1);

    ASSERT_EQ( sub_configs["system"].Get_Key_Name(), "system");
    ASSERT_EQ( kv_pairs["application_name"], "Add_KV_Pair");
    ASSERT_EQ( comment_pairs["application_name"], "# Unit Test Title");
}


/************************************************/
/*          Test the Add KV Pair Method         */
/************************************************/
TEST( Config_Param, Query_KV_Pair )
{
    // Create config
    Config_Param config;
    std::map<std::string,Config_Param> sub_configs;
    std::map<std::string,std::string>  kv_pairs;
    std::map<std::string,std::string>  comment_pairs;

    // Add Test Values
    config.Add_KV_Pair( "system.logging.level", "trace", "# Logging Level");
    config.Add_KV_Pair( "application_name", "Add_KV_Pair", "# Unit Test Title");


    // Check the query results
    std::string result_01;
    config.Query_KV_Pair( "system.logging.level",
                          result_01 );
    ASSERT_EQ( result_01, "trace");
}
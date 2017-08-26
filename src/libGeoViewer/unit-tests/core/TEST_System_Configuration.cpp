/**
 * @file    TEST_System_Configuration.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include <gtest/gtest.h>


// Project Libraries
#include <core/System_Configuration.hpp>


/*****************************************************/
/*            Test without Config File               */
/*****************************************************/
TEST( System_Configuration, No_Config_File_Test_01 )
{
    // Misc Variables
    Config_Param config_params, config_params2;
    std::map<std::string,Config_Param> sub_configs, sub_configs2;

    std::string default_config = std::string(getenv("HOME")) + "/.geo-registration-analyzer.cfg";

    // Create configuration
    int argc = 1;
    char** argv = new char*[3];
    argv[0] = "unit-tests";

    // Build the System Configuration
    System_Configuration config( argc, argv);

    // Get the Configuration File Pathname
    ASSERT_EQ( config.Get_Configuration_File_Pathname(), default_config);

    // Get the config object
    config_params = config.Get_Config_Params();
    sub_configs = config_params.Get_Sub_Configs();

    // Check the key names
    ASSERT_EQ( sub_configs.size(), 1);
    ASSERT_TRUE( sub_configs.find("system") != sub_configs.end());

    // Check SubConfigs
    config_params2 = sub_configs["system"];
    sub_configs2 = config_params2.Get_Sub_Configs();

    ASSERT_EQ( sub_configs2["logging"].Get_Key_Name(), "logging");


    delete [] argv;
}


/*****************************************************/
/*          Simple Constructor Unit Test             */
/*****************************************************/
TEST( System_Configuration, Sample_Config_File_01 )
{
    // Misc Variables
    Config_Param config_params;
    std::map<std::string, Config_Param> sub_configs;

    // Create configuration
    int argc = 3;
    char** argv = new char*[3];
    argv[0] = "unit-tests";
    argv[1] = "-c";
    argv[2] = "../data/unit-tests-data/sample-config-01.cfg";

    // Build the System Configuration
    System_Configuration config( argc, argv);

    // Get the Configuration File Pathname
    ASSERT_EQ( config.Get_Configuration_File_Pathname(), "../data/unit-tests-data/sample-config-01.cfg");

    // Get the config object
    config_params = config.Get_Config_Params();
    sub_configs = config_params.Get_Sub_Configs();


    // Check the key names
    ASSERT_EQ( sub_configs.size(), 3);
    ASSERT_TRUE( sub_configs.find("gui") != sub_configs.end());
    ASSERT_TRUE( sub_configs.find("system") != sub_configs.end());
    ASSERT_TRUE( sub_configs.find("geowidget") != sub_configs.end());

    delete [] argv;
}

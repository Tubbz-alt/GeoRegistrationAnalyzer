/**
 * @file    System_Configuration.cpp
 * @author  Marvin Smith
 * @date    4/21/2017
 */
#include "System_Configuration.hpp"




/****************************************/
/*              Constructor             */
/****************************************/
System_Configuration::System_Configuration( int argc, char* argv[] )
 : m_class_name("System_Configuration")
{
    // Parse the Command-Line
    Parse_Command_Line( argc, argv );

    // Parse the Configuration File


}


/**************************************/
/*             Finalize               */
/**************************************/
void System_Configuration::Finalize()
{



}


/********************************************/
/*          Parse the Command-Line          */
/********************************************/
void System_Configuration::Parse_Command_Line(int argc, char **argv)
{

}


/********************************************/
/*          Parse the COnfig File           */
/********************************************/
void System_Configuration::Parse_Configuration_File()
{

}


/**********************************************/
/*         Generate a Configuration File      */
/**********************************************/
void System_Configuration::Generate_Configuration_File()
{

}


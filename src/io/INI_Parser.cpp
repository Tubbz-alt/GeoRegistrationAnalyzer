/**
 * @file    INI_Parser.cpp
 * @author  Marvin Smith
 * @date    4/22/2017
*/
#include "INI_Parser.hpp"


/********************************/
/*          Constructor         */
/********************************/
INI_Parser::INI_Parser()
 : m_class_name("INI_Parser")
{

}

/**********************************/
/*          Constructor           */
/**********************************/
INI_Parser::INI_Parser( const std::string& pathname )
  : m_class_name("INI_Parser")
{

    // Load the file
    Initialize( pathname );
}

/******************************************/
/*          Initialize the Parser         */
/******************************************/
void INI_Parser::Initialize( const std::string& pathname )
{

    // Check if the file exists
    if( )


}

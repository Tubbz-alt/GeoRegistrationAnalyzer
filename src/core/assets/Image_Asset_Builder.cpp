/**
 * @file    Image_Asset_Builder.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "Image_Asset_Builder.hpp"

// C++ Libraries
#include <fstream>

// Project Libraries
#include "../../utility/String_Utilities.hpp"


/*****************************************/
/*         Create an Image Asset         */
/*****************************************/
Asset_Base::ptr_t Image_Asset_Builder::Create( const Config_Param& project_info )
{

    return nullptr;
}


/***************************************/
/*         Load the Path File          */
/***************************************/
std::vector<std::string> Image_Asset_Builder::Load_Path_File( const std::string& pathname,
                                                              bool&              success )
{
    // Assume success unless failure
    success = true;

    // Create output list
    std::vector<std::string> output;

    std::ifstream fin;
    fin.open(pathname.c_str());

    std::string line, templine;
    std::getline(fin, line);

    while( fin.good() )
    {
        // Add to list
        templine = String_Trim( line );

        if( templine.size() > 0 )
        {
            output.push_back(templine);
        }

        // Get more list
        std::getline( fin, line);

    }

    // Close the file
    fin.close();

    // return the output
    return output;
}
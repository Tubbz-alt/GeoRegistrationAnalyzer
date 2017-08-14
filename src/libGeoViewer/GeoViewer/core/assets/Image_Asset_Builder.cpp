/**
 * @file    Image_Asset_Builder.cpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#include "Image_Asset_Builder.hpp"

// C++ Libraries
#include <fstream>

// Boost Libraries
#include <boost/filesystem.hpp>

// Project Libraries
#include "../../utility/String_Utilities.hpp"

namespace bf = boost::filesystem;

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
                                                              bool&              success,
                                                              std::string&       error_msg )
{
    // Assume success unless failure
    success = true;
    error_msg = "";

    // Create output list
    std::vector<std::string> output;

    // Make sure file exists
    if( !bf::exists(bf::path(pathname)))
    {
        error_msg = "Path file (" + pathname + ") does not exist. Aborting.";
        success = false;
    }

    // Continue
    else
    {
        std::ifstream fin;
        fin.open(pathname.c_str());

        std::string line, templine;
        getline(fin, line);

        while (fin.good())
        {
            // Add to list
            templine = String_Trim(line);

            if (templine.size() > 0) {
                output.push_back(templine);
            }

            // Get more list
            getline(fin, line);

        }

        // Close the file
        fin.close();
    }

    // return the output
    return output;
}


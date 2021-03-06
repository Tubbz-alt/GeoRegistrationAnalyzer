/**
 * @file    System_Configuration.cpp
 * @author  Marvin Smith
 * @date    4/21/2017
 */
#include "System_Configuration.hpp"

// C++ Libraries
#include <deque>
#include <fstream>
#include <iostream>

// Qt Libraries
#include <QMessageBox>


// Boost Libraries
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>


// Project Libraries
#include "../log/System_Logger.hpp"
#include "../utility/String_Utilities.hpp"


namespace bf = boost::filesystem;

/****************************************/
/*              Constructor             */
/****************************************/
System_Configuration::System_Configuration( int argc, char* argv[],
                                            Default_Config_Generator::ptr_t config_generator )
 : m_class_name("System_Configuration"),
   m_config_generator(config_generator),
   m_project_pathname_provided(false)
{

    // Set Default Values
    Set_Defaults();

    // Parse the Command-Line
    Parse_Command_Line( argc, argv );

    // Parse the Configuration File
    if( !bf::exists(bf::path(m_config_pathname)))
    {
        QMessageBox::Icon window_icon = QMessageBox::Icon::Question;
        QString window_title = "System Configuration";
        std::string window_text = "Configuration File does not exist.\nPath: ";
        window_text += m_config_pathname + "\n";
        window_text += "Would you like to create file now?";
        QMessageBox::StandardButtons window_buttons = QMessageBox::StandardButton::Save | QMessageBox::StandardButton::Discard;

        QMessageBox* box = new QMessageBox( window_icon,
                                            window_title,
                                            QString(window_text.c_str()),
                                            window_buttons );

        int ret = box->exec();
        if( ret == QMessageBox::StandardButton::Save )
        {
            Generate_Configuration_File();
        }
    }

    if( bf::exists(bf::path(m_config_pathname))) {
        Parse_Configuration_File();
    }

    // Build Project Structure
    Build_Project_Structure();


    m_config_params.Set_Change_Tracking(true);

}


/**************************************/
/*             Finalize               */
/**************************************/
void System_Configuration::Finalize()
{



}


/****************************************/
/*          Get the Icon Path           */
/****************************************/
std::string System_Configuration::Get_Icon_Path()
{
    
    // query
    std::string output;
    m_config_params.Query_KV_Pair("system.core.icon_path",
                                  output,
                                  "",
                                  false );
    return output;
}


/****************************************/
/*          Get the Icon Path           */
/****************************************/
std::string System_Configuration::Get_HTML_Path()
{

    // query
    std::string output;
    m_config_params.Query_KV_Pair("system.core.html_path",
                                  output,
                                  "",
                                  false );
    return output;
}


/*******************************************/
/*      Add a Configuration Parameter      */
/*******************************************/
void System_Configuration::Add_Config_Param( const std::string&  key_name,
                                             const std::string&  value,
                                             const std::string&  comment,
                                             const bool&         override )
{
    m_config_params.Add_KV_Pair(key_name, value, comment, override);
}


/********************************************/
/*      Query a Configuration Parameter     */
/********************************************/
std::string System_Configuration::Query_Config_Param(const std::string& key_name,
                                                     bool&              value_found )const
{
    return m_config_params.Query_KV_Pair( key_name, value_found);
}


/********************************************/
/*      Query a Configuration Parameter     */
/********************************************/
std::string System_Configuration::Query_Config_Param(const std::string& key_name,
                                                     bool&              value_found,
                                                     const std::string& default_value,
                                                     const bool&        write_if_not_found )
{
    value_found = true;
    std::string output;

    // Split Keyname
    m_config_params.Query_KV_Pair(key_name, output, default_value, write_if_not_found);

    if( output == default_value )
    {
        value_found = false;
    }
    return output;
}


/********************************************/
/*      Query a Configuration Parameter     */
/********************************************/
std::string System_Configuration::Query_Config_Param_NL( const std::string& key_name,
                                                         bool&              value_found,
                                                         const std::string& default_value,
                                                         const bool&        write_if_not_found )
{
    value_found = true;
    std::string output;

    // Split Keyname
    m_config_params.Query_KV_Pair(key_name, output, default_value, write_if_not_found);

    if( output == default_value )
    {
        value_found = false;
    }

    // Cleanup Path
    boost::replace_all(output, "\\n", "\n");

    return output;
}


/********************************************/
/*      Query a Configuration Parameter     */
/********************************************/
int System_Configuration::Query_Config_Param_Int32( const std::string& key_name,
                                                    bool&              value_found,
                                                    const int&         default_value,
                                                    const bool&        write_if_not_found )
{
    bool output_found = true;
    std::string output;
    int int_output;

    // Build the default value string
    std::string default_value_str = std::to_string(default_value);

    // Split Keyname
    m_config_params.Query_KV_Pair(key_name, output, default_value_str, write_if_not_found);

    if( output == default_value_str )
    {
        output_found = false;
    }

    // Convert to int
    int_output = std::stoi(output);
    return int_output;
}

/*************************************************/
/*          Check if Config Path Exists          */
/*************************************************/
bool System_Configuration::Config_File_Path_Exists() const
{
    return bf::exists(bf::path(m_config_pathname));
}

/**********************************************/
/*         Generate a Configuration File      */
/**********************************************/
void System_Configuration::Generate_Configuration_File()
{
    // Check if the configuration file exists
    if( m_config_pathname != "" )
    {
        // Open the file
        std::cout << "Writing to " << m_config_pathname << std::endl;
        std::ofstream fout;
        fout.open(m_config_pathname.c_str());

        fout << "#  Configuration file created at " << std::endl;
        fout << "#" << std::endl;
        fout << std::endl;

        // Pass to Config Params Object
        m_config_params.Write_Stream(fout);

        // Close the file
        fout.close();
    }

    // Otherwise, log error
    else
    {
        std::cerr << "Config Path Is Not Valid" << std::endl;
    }
}

/**********************************************/
/*          Check for config changes          */
/**********************************************/
bool System_Configuration::Has_Changed() const
{
    return m_config_params.Has_Changed();
}


/*****************************************************/
/*          Get the Configuration File List          */
/*****************************************************/
std::map<std::string,std::string> System_Configuration::Get_Config_List() const
{
    return m_config_params.Get_Config_List();
}

/********************************************/
/*            Set Default Values            */
/********************************************/
void System_Configuration::Set_Defaults()
{
    // Set default configuration path
    m_config_params = m_config_generator->Generate();

    // Set the default config file
    m_config_params.Query_KV_Pair("system.config_pathname",
                                  m_config_pathname,
                                  "",
                                  false);
}


/**********************************************/
/*         Build the Project Structure        */
/**********************************************/
void System_Configuration::Build_Project_Structure()
{
    // Check the base directory
    bool value_found;
    std::string project_path = Query_Config_Param("system.core.project_base", value_found);
    if( !bf::exists(bf::path(project_path)))
    {
        std::string msg = "Building: " + project_path;
        std::cout << msg << std::endl;
        bf::create_directories(bf::path(project_path));
        bf::create_directories(bf::path(project_path + "/projects"));
    }
}


/********************************************/
/*          Parse the Command-Line          */
/********************************************/
void System_Configuration::Parse_Command_Line(int argc, char **argv)
{
    // Set the Application Name
    m_application_name = argv[0];

    // The the rest into list
    std::deque<std::string> args;
    for( int i=1; i<=(argc-1); i++ )
    {
        args.push_back(argv[i]);
    }


    // Iterate over command-line options
    std::string arg;
    while( args.size() > 0 )
    {
        // Pop next argument
        arg = args.front();
        args.pop_front();

        // Process the arguments

        // Check for config file flag
        if( arg == "-c") {
            // Make sure there is an argument left to parse
            if (args.size() <= 0) {
                std::cerr << "No Arguments Left to Process" << std::endl;
            } else {
                m_config_pathname = args.front();
                args.pop_front();
            }
        }

        // Check for the project file flag
        else if( arg == "-p" )
        {
            // make sure there is an argument left to parse
            if( args.size() <= 0 )
            {
                std::cerr << "No Arguments Left to Process" << std::endl;
            }
            else
            {
                m_project_pathname_provided = true;
                m_project_pathname = args.front();
            }
        }

        // Otherwise, ignore (for now)
    }

}


/********************************************/
/*          Parse the COnfig File           */
/********************************************/
void System_Configuration::Parse_Configuration_File()
{
    // Check if the file exists
    if( !bf::exists(bf::path(m_config_pathname)))
    {
        std::cerr << "Config File (" << m_config_pathname << ") Does Not Exist." << std::endl;
        std::exit(-1);
    }

    // Otherwise, process
    else
    {
        // Open the file
        std::ifstream fin;
        fin.open(m_config_pathname.c_str());

        // Read the first line
        std::string line, trimmed_line;
        std::getline( fin, line);

        // Misc Params
        bool comment_set = false;
        std::string comment_str;


        while( fin.good() )
        {
            // Trim the string
            trimmed_line = String_Trim(line);

            // Skip if Empty
            if( trimmed_line.size() <= 0 )
            {
            }

            // Check if comment
            else if( trimmed_line[0] == '#' )
            {
                // Check if a comment has already been created
                if(comment_set)
                {
                    comment_str = trimmed_line;
                }

                // Otherwise, set again
                else
                {
                    comment_set = true;
                    comment_str = trimmed_line;
                }
            }

            // Otherwise, check for param
            else
            {
                // Split based on equal operator
                std::vector<std::string> comps = String_Split( trimmed_line,
                                                               "=");

                // Check if enough comps
                if( comps.size() < 2 )
                {
                    std::cerr << "Warning: Line (" << trimmed_line << ") does not have enough components" << std::endl;
                }
                else
                {
                    // Add the kv pair
                    Add_Config_Param( comps[0], comps[1], comment_str, true);

                    // Clear any comments
                    comment_set = false;
                    comment_str = "";
                }

            }

            // Get next line
            getline( fin, line);

        } // End of while(fin.good)

        // Close the file
        fin.close();
    }
}




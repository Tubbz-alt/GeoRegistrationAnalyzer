/**
 *  @file    System_Configuration.hpp
 *  @author  Marvin Smith
 *  @date    4/21/2017
 */
#ifndef SYSTEM_CONFIGURATION_HPP
#define SYSTEM_CONFIGURATION_HPP

// C++ Libraries
#include <memory>
#include <string>


/**
 * @class System_Configuration
 */
class System_Configuration
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<System_Configuration> ptr_t;


        /**
         * @brief Constructor
         */
        System_Configuration( int argc, char* argv[] );
        

        /**
         * @brief Finalize
         */
        void Finalize();

    protected:

        /**
         * @brief Parse the Command-Line
         *
         * @param[in] argv
         * @param[in] argc
         */
        void Parse_Command_Line( int argc, char* argv[] );


        /**
         * @brief Parse the Configuration File
         */
        void Parse_Configuration_File();


        /**
         * @brief Generate the Configuration File
         */
        void Generate_Configuration_File();


    private:

        /// Class Name
        std::string m_class_name;

        /// Application Name
        std::string m_application_name;

        /// Configuration File Path
        std::string m_config_pathname;


}; // End of System_Configuration Class


#endif

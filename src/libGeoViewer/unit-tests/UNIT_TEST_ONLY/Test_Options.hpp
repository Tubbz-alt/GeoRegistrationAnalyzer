/**
 * @file    Test_Options.hpp
 * @author  Marvin Smith
 * @date    9/15/2017
 */
#ifndef LIB_GEO_VIEWER_UNIT_TESTS_TEST_OPTIONS_HPP
#define LIB_GEO_VIEWER_UNIT_TESTS_TEST_OPTIONS_HPP

// C++ Libraries
#include <string>


/**
 * @class Test_Options
 */
class Test_Options
{
    public:

        /**
         * @brief Constructor
         */
        Test_Options( int argc, char* argv[] );

    private:

        /**
         * @brief Parse Command-Line Options
         * @param argc
         * @param argv
         */
        void Parse_Command_Line( int argc, char* argv[] );

        /**
         * @brief Initialize Logging
         */
        void Initialize_Logging();

        /// Class Name
        std::string m_class_name;


}; // End of Test_Options Class


#endif
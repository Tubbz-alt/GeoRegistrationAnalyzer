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


    private:

        /// Class Name
        std::string m_class_name;


}; // End of System_Configuration Class


#endif

/**
 * @file    System_Manager.hpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

// C++ Libraries
#include <string>


/**
 * @class System_Manager
*/
class System_Manager
{
    public:

        /**
         * @brief Constructor
        */
        System_Manager();


        /**
         * @brief Destructor
        */
        virtual ~System_Manager();


        /**
         * @brief Initialize System Manager
        */
        void Initialize( int argc, char* argv[] );


        /**
         * @brief Finalize System Manager
        */
        void Finalize();


    private:

        /// Class Name
        std::string m_class_name;

}; // End of System_Manager Class

#endif

/**
 * @file    System_Logger.hpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#ifndef SYSTEM_LOGGER_HPP
#define SYSTEM_LOGGER_HPP

// C++ Libraries
#include <memory>
#include <string>


/**
 * @class System_Logger
*/
class System_Logger
{
    public:

        /**
         * @brief Destructor
        */
        virtual ~System_Logger();


        /**
         * @brief Inialize the Logger
        */
        static void Initialize( Log_Handler_Base::ptr_t log_handler );


        /**
         * @brief Finalize
        */
        static void Finalize();


}; // End of System_Logger Class


#endif

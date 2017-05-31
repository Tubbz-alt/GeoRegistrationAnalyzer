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
#include <vector>


// Project Libraries
#include "Log_Handler_Base.hpp"
#include "../core/System_Configuration.hpp"


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
        static void Initialize( System_Configuration::ptr_t          sys_config,
                                std::vector<Log_Handler_Base::ptr_t> log_handlers );


        /**
         * @brief Finalize
        */
        static void Finalize();


        /**
         * @brief Check if Initialized
         */
        static bool Is_Initialized();



    private:

        /// Pointer Type
        typedef std::shared_ptr<System_Logger> ptr_t;

        /**
         * @brief Constructor
         */
        System_Logger();


        /**
         * @brief Copy Constructor
         */
        System_Logger( const System_Logger& rhs ) = delete;


        /**
         * @brief Assignment operator
         */
        void operator = ( System_Logger const& rhs ) = delete;


        /**
         * @brief Get the Instance
         */
        static System_Logger::ptr_t&  Get_Instance();


        /// Class Name
        std::string m_class_name;

        /// List of Log Handlers
        std::vector<Log_Handler_Base::ptr_t> m_log_handlers;


}; // End of System_Logger Class


#endif

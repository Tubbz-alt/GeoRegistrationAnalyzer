/**
 * @file    System_Manager.hpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#ifndef SYSTEM_MANAGER_HPP
#define SYSTEM_MANAGER_HPP

// C++ Libraries
#include <memory>
#include <string>

// Project Libraries
#include "System_Configuration.hpp"
#include "../comm/MessageService.hpp"


/**
 * @class System_Manager
*/
class System_Manager
{
    public:
        
        /// Pointer Type
        typedef std::shared_ptr<System_Manager> ptr_t;

        /**
         * @brief Destructor
        */
        virtual ~System_Manager();


        /**
         * @brief Initialize System Manager
        */
        static void Initialize( System_Configuration::ptr_t system_configuration );


        /**
         * @brief Finalize System Manager
        */
        static void Finalize();


        /**
         * @brief Get the Message-Service
         * @return
         */
        static MessageService::ptr_t& Get_Message_Service();
        

        /**
         * @brief Get Instance.
         */
        static System_Manager::ptr_t& Get_Instance();

    protected:

        /**
         * @brief Update Configuration
         */
        void Update_Configuration();

    private:
        
        /**
         * @brief Constructor
        */
        System_Manager( System_Configuration::ptr_t system_configuration);

        /**
         * @brief Deleted Copy Constructor
         */
        System_Manager( const System_Manager& rhs ) = delete;

        /**
         * @brief Get Reference.
         */
        static ptr_t& Get_Reference();


        /**
         * @brief Deleted Assignment operator
         */
        void operator = (const System_Manager& rhs ) = delete;


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_system_configuration;

        /// Message Service
        MessageService::ptr_t m_message_service;

}; // End of System_Manager Class

#endif

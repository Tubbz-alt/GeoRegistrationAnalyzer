/**
 * @file    System_Manager.cpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#include "System_Manager.hpp"


// C++ Libraries
#include <iostream>

// Other Libraries
#include <gdal_priv.h>

// Project Libraries
#include "../log.hpp"


/************************************/
/*            Constructor           */
/************************************/
System_Manager::System_Manager( System_Configuration::ptr_t system_configuration)
  : m_class_name("System_Manager"),
    m_system_configuration(system_configuration)
{
    // Update Configuration
    Update_Configuration();

    // Initialize GDAL
    GDALAllRegister();

    // Create Message-Service
    MessageServiceConfig::ptr_t msg_svc_config = std::make_shared<MessageServiceConfig>();
    m_message_service = std::make_shared<MessageService>( msg_svc_config );

    // Initialize
    m_message_service->Initialize();

}


/************************************/
/*             Destructor           */
/************************************/
System_Manager::~System_Manager()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Finalize Message Service
    if( m_message_service == nullptr )
    {
        LOG_CLASS_ERROR("Why is MessageService null?");
    }
    else
    {
        m_message_service.reset();
    }

    // Log Exit
    LOG_CLASS_EXIT();
}


/***************************************/
/*            Get Instance             */
/***************************************/
System_Manager::ptr_t& System_Manager::Get_Instance()
{
    return Get_Reference();
}


/***************************************/
/*            Get Instance             */
/***************************************/
System_Manager::ptr_t& System_Manager::Get_Reference()
{
    static System_Manager::ptr_t reference;
    return reference;
}


/************************************/
/*             Initialize           */
/************************************/
void System_Manager::Initialize( System_Configuration::ptr_t system_configuration)
{
    // Check if it has been created
    if( Get_Reference() == nullptr )
    {
        Get_Reference() = System_Manager::ptr_t( new System_Manager( system_configuration ));
    }

    // Otherwise, log error
    else
    {
        std::cerr << "ERROR: System Manager Already Initialized." << std::endl;
    }

}

/************************************/
/*             Finalize             */
/************************************/
void System_Manager::Finalize()
{
    // Delete Manager
    const std::string m_class_name = "System_Manager";
    if( Get_Reference() != nullptr )
    {
        // Finalize the Message-Service
        Get_Reference()->m_message_service->Finalize();

        // Delete the System-Manager
        Get_Reference().reset();
    } else
    {
        LOG_CLASS_WARNING("System-Manager is currently null");
    }
}


/*******************************************/
/*          Get the message service        */
/*******************************************/
MessageService::ptr_t& System_Manager::Get_Message_Service()
{
    // return message service
    return Get_Reference()->m_message_service;
}

/******************************************/
/*          Update Configuration          */
/******************************************/
void System_Manager::Update_Configuration()
{
    // Set any required config parameters
}

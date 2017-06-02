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

}


/************************************/
/*             Destructor           */
/************************************/
System_Manager::~System_Manager()
{
    // Finalize
    Finalize();
}


/***************************************/
/*            Get Instance             */
/***************************************/
System_Manager::ptr_t System_Manager::Get_Instance()
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
    // Grab Reference
    auto reference = Get_Reference();

    // Check if it has been created
    if( reference == nullptr )
    {
        reference = System_Manager::ptr_t( new System_Manager( system_configuration ));
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
    // Grab Reference
    auto reference = Get_Reference();
    
    // Delete Manager
    if( reference != nullptr )
    {
        reference.reset();
    }
}


/******************************************/
/*          Update Configuration          */
/******************************************/
void System_Manager::Update_Configuration()
{
    // Set any required config parameters
}

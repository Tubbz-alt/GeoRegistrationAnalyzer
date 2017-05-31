/**
 * @file    System_Logger.cpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#include "System_Logger.hpp"




/************************************/
/*            Constructor           */
/************************************/
System_Logger::System_Logger()
 : m_class_name("System_Logger")
{

}


/*************************************/
/*            Destructor             */
/*************************************/
System_Logger::~System_Logger()
{

}


/*********************************************/
/*           Initialize the Logger           */
/*********************************************/
void System_Logger::Initialize( System_Configuration::ptr_t          sys_config,
                                std::vector<Log_Handler_Base::ptr_t> log_handlers )
{
    // Check if the logger is initialized
    if( Is_Initialized() )
    {
        std::cerr << "Logger already initialized" << std::endl;
    }

    // Otherwise, initialize
    else
    {
        // Build the instance
        Get_Instance() = System_Logger::ptr_t(new System_Logger());

        Get_Instance()->m_log_handlers = log_handlers;
    }


}


/****************************************/
/*          Finalize the Logger         */
/****************************************/
void System_Logger::Finalize()
{

}


/*****************************************/
/*          Check if Initialized         */
/*****************************************/
bool System_Logger::Is_Initialized()
{
    if( Get_Instance() == nullptr )
    {
        return false;
    }
    return true;
}


/********************************/
/*        Get Instance          */
/********************************/
System_Logger::ptr_t&  System_Logger::Get_Instance()
{
    static System_Logger::ptr_t inst;
    return inst;
}


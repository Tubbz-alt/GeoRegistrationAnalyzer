/**
 * @file    System_Logger.cpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#include "System_Logger.hpp"

// C++ Libraries
#include <ctime>


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


/*******************************/
/*         Log Message         */
/*******************************/
void System_Logger::Log( const LogSeverity& severity,
                         const std::string& message )
{
    // Grab the time
    time_t timeval;
    time(&timeval);


    // Check if initialized
    if( !Is_Initialized() )
    {
        // FOrmat the timestamp
        struct tm * timeinfo = localtime(&timeval);
        char buffer [80];

        strftime (buffer,80,"%Y%m%d %H%M%S",timeinfo);
        std::string time_str = std::string(buffer);

        std::cerr << "Warning:  Logger Not Initialized. Time: " << time_str << " Severity: ";
        std::cerr << LogSeverityToString(severity) << ", MSG: " << message << std::endl;
    }

    // Continue
    else
    {
        // Get Instance
        auto inst = Get_Instance();

        // Iterate over handlers
        for( auto handler : inst->m_log_handlers )
        {
            handler->Log( severity, timeval, message );
        }
    }

}


/*******************************/
/*         Log Message         */
/*******************************/
void System_Logger::Log( const LogSeverity& severity,
                         const std::string& class_name,
                         const std::string& func_name,
                         const int&         line_no,
                         const std::string& message )
{
    // Grab the time
    time_t timeval;
    time(&timeval);


    // Check if initialized
    if( !Is_Initialized() ) {
        // FOrmat the timestamp
        struct tm *timeinfo = localtime(&timeval);
        char buffer[80];

        strftime(buffer, 80, "%Y%m%d %H%M%S", timeinfo);
        std::string time_str = std::string(buffer);

        std::cerr << "Warning:  Logger Not Initialized. Time: " << time_str << " Severity: ";
        std::cerr << LogSeverityToString(severity) << ", MSG: " << message << std::endl;
    }

    // Continue
    else
    {
        // Get Instance
        auto inst = Get_Instance();

        // Iterate over handlers
        for( auto handler : inst->m_log_handlers )
        {
            handler->Log_Class( severity,
                                timeval,
                                class_name,
                                func_name,
                                line_no,
                                message );
        }
    }

}


/********************************/
/*        Get Instance          */
/********************************/
System_Logger::ptr_t&  System_Logger::Get_Instance()
{
    static System_Logger::ptr_t inst;
    return inst;
}


/**
 * @file    System_Logger.cpp
 * @author  Marvin Smith
 * @date    4/17/2017
*/
#include "System_Logger.hpp"

// C++ Libraries
#include <ctime>

static std::shared_ptr<System_Logger> global_inst;

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

        // Lock
        Get_Instance()->m_log_lock.lock();
        Get_Instance()->m_log_handlers = log_handlers;
        Get_Instance()->m_log_lock.unlock();
    }


}


/****************************************/
/*          Finalize the Logger         */
/****************************************/
void System_Logger::Finalize()
{
    // Clear the list of loggers
    if( Get_Instance() == nullptr )
    {
        std::cerr << "WARNING: System-Logger already finalized." << std::endl;
    }
    else
    {
        // Clear out log handlers
        Get_Instance()->m_log_lock.lock();
        Get_Instance()->m_log_handlers.clear();
        Get_Instance()->m_log_lock.unlock();

        // Wipe out instance
        global_inst.reset();
    }
    std::cout << "##########################################" << std::endl;
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
        // Check Instance
        if( Get_Instance() == nullptr )
        {
            std::cerr << "ERROR: Logger says it is initialized yet the instance is null." << std::endl;
        }

        // Otherwise, Iterate over handlers
        else
        {
            Get_Instance()->m_log_lock.lock();
            for (auto handler : Get_Instance()->m_log_handlers)
            {
                if( handler == nullptr )
                {
                    std::cerr << "ERROR: Logger says it is initialized yet a registered handler is null." << std::endl;
                }
                else
                {
                    handler->Log(severity, timeval, message);
                }
            }
            Get_Instance()->m_log_lock.unlock();
        }
    }

}


/*******************************/
/*         Log Message         */
/*******************************/
void System_Logger::Log_Class( const LogSeverity& severity,
                               const std::string& class_name,
                               const std::string& file_name,
                               const std::string& func_name,
                               const int&         line_no,
                               const std::string& message )
{
    // Grab the time
    time_t timeval;
    time(&timeval);


    // Check if initialized
    if( Get_Instance() == nullptr )
    {
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
        // Check Instance
        if( Get_Instance() == nullptr )
        {
            std::cerr << "ERROR: Logger says it is initialized yet the instance is null." << std::endl;
        }

            // Otherwise, Iterate over handlers
        else
        {
            int counter = 0;
            Get_Instance()->m_log_lock.lock();
            for (auto handler : Get_Instance()->m_log_handlers)
            {
                if( handler == nullptr )
                {
                    std::cerr << "ERROR: Logger says it is initialized yet a registered handler is null." << std::endl;
                }
                else
                {
                    handler->Log_Class( severity,
                                        timeval,
                                        class_name,
                                        file_name,
                                        func_name,
                                        line_no,
                                        message );
                }
            }
            Get_Instance()->m_log_lock.unlock();
        }
    }

}


/*******************************/
/*         Log Message         */
/*******************************/
void System_Logger::Log_Function( const LogSeverity& severity,
                                  const std::string& file_name,
                                  const std::string& func_name,
                                  const int&         line_no,
                                  const std::string& message )
{
    // Grab the time
    time_t timeval;
    time(&timeval);


    // Check if initialized
    if( !Is_Initialized() )
    {
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
        Get_Instance()->m_log_lock.lock();

        // Iterate over handlers
        for( auto handler : Get_Instance()->m_log_handlers )
        {
            handler->Log_Function( severity,
                                   timeval,
                                   file_name,
                                   func_name,
                                   line_no,
                                   message );
        }

        Get_Instance()->m_log_lock.unlock();
    }

}

/********************************/
/*        Get Instance          */
/********************************/
System_Logger::ptr_t&  System_Logger::Get_Instance()
{

    return global_inst;
}


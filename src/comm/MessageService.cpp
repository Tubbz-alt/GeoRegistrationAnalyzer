/**
 * @file    MessageService.cpp
 * @author  Marvin Smith
 * @date    4/19/2017
*/
#include "MessageService.hpp"

// C++ Libraries
#include <iostream>
#include <sstream>


// Project Libraries
#include "../log/System_Logger.hpp"


/****************************************/
/*             Constructor              */
/****************************************/
MessageServiceConfig::MessageServiceConfig()
  : m_class_name("MessageServiceConfig")
{

}

/****************************************/
/*             Constructor              */
/****************************************/
MessageService::MessageService( MessageServiceConfig::ptr_t config )
  : m_class_name("MessageService"),
    m_config(config),
    m_is_initialized(false),
    m_listen_state(false)
{

}


/****************************************/
/*              Destructor              */
/****************************************/
MessageService::~MessageService()
{
    // Check if initialized
    if( Is_Initialized() )
    {
        Finalize();
    }
}

/****************************************/
/*             Initialize               */
/****************************************/
void MessageService::Initialize()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Start the queue
    m_queue.Start();

    // Set the listen flag
    m_listen_state = true;
    m_listen_thread = std::thread( &MessageService::Run_Listener, this);

    // If No Errors, set to true
    m_is_initialized = true;

    // Log Exit
    LOG_CLASS_EXIT();
}

/****************************************/
/*               Finalize              */
/****************************************/
void MessageService::Finalize()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Set status and close thread
    m_listen_state = false;
    m_queue.Complete();
    if( m_listen_thread.joinable() )
    {
        m_listen_thread.join();
    }

    // Note that we are no longer initialized
    m_is_initialized = false;

    // Log Exit
    LOG_CLASS_EXIT();
}

/*******************************************/
/*           Subscribe a Listener          */
/*******************************************/
void MessageService::Subscribe( const std::string& topic_name,
                                HANDLER_TYPE handler_method )
{
    LOG_CLASS_TRACE( "Subscribing Handler.  Topic: " + topic_name);

    // Add to List of Subscribers
    m_subscribers[topic_name].push_back(handler_method);
}


/*********************************/
/*          Send Message         */
/*********************************/
void MessageService::Send( const std::string& topic_name,
                           const std::string& message )
{
    // Add to Queue
    LOG_CLASS_TRACE("Sending Message.  Topic: " + topic_name);
    m_queue.Push( std::make_tuple(topic_name, message ));


}


/********************************/
/*         Run Listener         */
/********************************/
void MessageService::Run_Listener()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    std::tuple<std::string,std::string> tp;
    bool status;

    while( m_listen_state )
    {

        // Wait to pop
        status = m_queue.Pop( tp );

        // Log release
        LOG_CLASS_TRACE("Released from Queue. Status: " + std::to_string(status));

        // Check if Topic is in list of Subscribers
        if( !status )
        {
            LOG_CLASS_TRACE( "Pop returned fail state.  Complete: " + std::to_string(m_queue.Is_Complete())
                             + ", Invalid: " + std::to_string(m_queue.Is_Invalid()));
        }

        else if( m_subscribers.find(std::get<0>(tp)) == m_subscribers.end() )
        {
            // Should Log Something Here
            LOG_CLASS_TRACE("Unable to find subscriber for topic: " + std::get<0>(tp));
        }

        // Otherwise, pass to all handlers
        else
        {
            std::deque<HANDLER_TYPE> handlers = m_subscribers.find(std::get<0>(tp))->second;
            for( HANDLER_TYPE handler : handlers )
            {
                LOG_CLASS_TRACE("Calling Handler. Topic: " + std::get<0>(tp));
                handler(std::get<0>(tp),
                        std::get<1>(tp));
            }
        }
    }

    // Log Exit
    LOG_CLASS_EXIT();
}

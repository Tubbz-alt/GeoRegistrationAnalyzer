/**
 * @file    Thread_Pool.cpp
 * @author  Marvin Smith
 * @date    5/21/2017
 */
#include "Thread_Pool.hpp"


// C++ Standard Libraries
#include <iostream>
#include <unistd.h>



/***************************************/
/*             Constructor             */
/***************************************/
Worker_Thread::Worker_Thread()
  : m_class_name("Worker_Thread"),
    m_is_running(false)
{
}


/***************************************/
/*              Destructor             */
/***************************************/
Worker_Thread::~Worker_Thread()
{
}

/***************************************/
/*        Worker Thread Execute        */
/***************************************/
int Worker_Thread::Execute()
{
    return 0;
}


/***************************************/
/*          Default Constructor        */
/***************************************/
Thread_Pool::Thread_Pool( const int& max_threads )
  : m_class_name("Thread_Pool"),
    m_pool_size(max_threads),
    m_pool_state((int)ThreadPoolStatusType::POOL_STOPPED),
    m_number_assigned_workers(0),
    m_number_running_threads(0)
{
    // Make sure we have a minimum number
    if( m_pool_size < 1 )
    {
        m_pool_size = 1;
    }

    // Resize the thread pool
    m_threads.resize(m_pool_size);
}


/**************************************/
/*             Destructor             */
/**************************************/
Thread_Pool::~Thread_Pool(){

    // Clear the work queue
    if( m_pool_state != (int)ThreadPoolStatusType::POOL_STOPPED )
    {
        bool status;
        Destroy_Pool( status );
    }
}


/**************************************/
/*      Get Remaining Work Jobs       */
/**************************************/
int Thread_Pool::Get_Remaining_Work()
{
    int result;
    m_mutex.lock();
    result = m_queue.size();
    m_mutex.unlock();
    return result;
}


/****************************************************/
/*         Check if Thread Pool is Running          */
/****************************************************/
bool Thread_Pool::Is_Running()const
{
    if( m_pool_state == (int)ThreadPoolStatusType::POOL_STARTED )
    {
        return true;
    }
    return false;
}


/******************************************/
/*              Initialize                */
/******************************************/
void Thread_Pool::Initialize( bool& status )
{
    // Initialize the thread pool
    status = true;

    // Set the state
    m_pool_state = (int)ThreadPoolStatusType::POOL_STARTED;
    
    // Set the return and create threads
    int ret = -1;
    for( int i=0; i<m_pool_size; i++ )
    {
        // Create the thread
        m_threads[i] = std::thread( &Thread_Pool::Execute_Thread, this );
    }

}


/****************************************************/
/*                  Destroy the pool                */
/****************************************************/
void Thread_Pool::Destroy_Pool( bool& status )
{
    // Initialize the Status
    status = true;

    // Lock the mutex
    m_mutex.lock();

    // Set the state
    m_pool_state = (int)ThreadPoolStatusType::POOL_STOPPED;
        
    // Unlock Mutex
    m_mutex.unlock();

    // Send broadcast
    m_condv.notify_all();

    // Set our return variable
    int ret = -1;
    for( int i=0; i< m_pool_size; i++ )
    {
        // Join the thread
        if( m_threads[i].joinable() )
        {
            m_threads[i].join();
        }
        m_condv.notify_all();
    }
    
    // Clear each worker
    for( int i=0; i<m_queue.size(); i++ )
    {
        if( m_queue[i] != NULL || 
            m_queue[i] != nullptr )
        {
            m_queue[i].reset();
        }
    }
    m_queue.clear();

    // Clear the thread list
    m_threads.clear();
}


/***********************************************************************/
/*          Wait until the Thread Pool has finished all work           */
/***********************************************************************/
void Thread_Pool::Wait_Until_Pool_Empty( bool& status )
{
    // Initialize Status
    status = true;

    //  Get the remaining work, skip if empty
    while( m_number_assigned_workers > 0 )
    {
        // Create the lock
        std::unique_lock<std::mutex> lck(m_number_assigned_workers_mutex);

        // Wait
        m_number_assigned_workers_cv.wait(lck);
    }
}


#include <sched.h>

/***********************************************/
/*              Execute the Thread             */
/***********************************************/
void Thread_Pool::Execute_Thread()
{
    // Create Task
    Worker_Thread::ptr_t worker_thread = nullptr;



    // Work until done
    while( true )
    {
        
        while( (m_pool_state != (int)ThreadPoolStatusType::POOL_STOPPED) &&
               m_queue.empty() )
        {
            std::cout << "AAA" << std::endl;
            // Wait
            std::unique_lock<std::mutex> lck(m_mutex);
            bool state = (m_pool_state != (int)ThreadPoolStatusType::POOL_STOPPED);
            m_condv.wait(lck, [&]{ return state;});
            
        }

        // Lock the mutex
        m_mutex.lock();
        
        // If we stopped, then exit
        if( m_queue.size() <= 0 && m_pool_state == (int)ThreadPoolStatusType::POOL_STOPPED )
        {

            std::cout << "BBB" << std::endl;
            // Unlock the mutex
            m_mutex.unlock();

            // Stop the thread
            return;
        }

        std::cout << "CCC" << std::endl;
        // pop the next task
        worker_thread = m_queue.front();
        m_queue.pop_front();
        

        std::cout << "DDD" << std::endl;
        // Unlock the mutex
        m_mutex.unlock();
        std::cout << "EEE" << std::endl;

        // Execute the Task
        worker_thread->Set_Running_Flag(true);
        m_number_running_threads++;
        worker_thread->Execute();
        worker_thread->Set_Running_Flag(false);
        m_number_running_threads--;

        // Delete the job
        worker_thread.reset();


        std::cout << "FFF" << std::endl;
        std::unique_lock<std::mutex> lck(m_number_assigned_workers_mutex);

        // Decrement the counter
        m_number_assigned_workers--;

        // Check if empty, if so notify the worker condition variable
        if( m_number_assigned_workers <= 0 ){
            m_number_assigned_workers_cv.notify_all();
        }
    }
    std::cout << "GGG" << std::endl;
    
}


/***********************************************/
/*          Assign Work to the Queue           */
/***********************************************/
void Thread_Pool::Assign_Work( Worker_Thread::ptr_t new_thread )
{
    
    // Make sure the new worker is not null
    if( new_thread == nullptr ){ 
        return; 
    }

    // Lock the mutex
    std::cout << "Waiting on Mutex" << std::endl;
    m_mutex.lock();
    std::cout << "Inside Mutex" << std::endl;


    // Add a task
    m_queue.push_back( std::move(new_thread) );

    
    // Increment the counter
    {
        std::unique_lock<std::mutex> lck(m_number_assigned_workers_mutex);
        m_number_assigned_workers++;
    }

    // Signal the next job
    m_condv.notify_one();


    // Unlock the mutex
    m_mutex.unlock();
}


/********************************************/
/*      Get the list of running threads     */
/********************************************/
int Thread_Pool::Get_Current_Running_Threads()
{
    return m_number_running_threads;
}
            

/***********************************************/
/*          Count Work in  the Queue           */
/***********************************************/
int Thread_Pool::Get_Current_Work_Items()
{
    std::unique_lock<std::mutex> lck(m_number_assigned_workers_mutex);
    return m_number_assigned_workers;
}
            


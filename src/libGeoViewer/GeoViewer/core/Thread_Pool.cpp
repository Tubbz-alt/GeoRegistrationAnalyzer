/**
 * @file    Thread_Pool.cpp
 * @author  Marvin Smith
 * @date    5/21/2017
 */
#include "Thread_Pool.hpp"


// C++ Standard Libraries
#include <iostream>
//#include <unistd.h>



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
    m_number_assigned_workers(0)
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
uint64_t Thread_Pool::Get_Remaining_Work()
{
    return m_queue.Size();
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
        std::cout << "Creating thread " << i << std::endl;
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
    m_queue.Clear();
    m_queue.Complete();

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


    // Wait for pool to empty
    std::cout << "Waiting for Work Queue to Complete" << std::endl;
    m_queue.Complete();


    //  Wait for workers to complete
    std::cout << "Waiting for Assigned Workers to Complete" << std::endl;
    while( m_number_assigned_workers > 0 )
    {
        // Create the lock
        std::unique_lock<std::mutex> lck(m_number_assigned_workers_mutex);

        // Wait
        m_number_assigned_workers_cv.wait(lck, [this]{return m_number_assigned_workers <= 0; });
    }

    std::cout << "Assigned Workers Completed" << std::endl;
}


//#include <sched.h>

/***********************************************/
/*              Execute the Thread             */
/***********************************************/
void Thread_Pool::Execute_Thread()
{
    // Create Task
    Worker_Thread::ptr_t worker_thread = nullptr;
    bool status;

    // Work until done
    while( m_pool_state != (int)ThreadPoolStatusType::POOL_STOPPED )
    {

        // Pop an item from the queue
        status = m_queue.Pop( worker_thread );

        // Make sure there was not a problem
        if( !status || worker_thread == nullptr )
        {
            std::cout << "Work Queue Popped item with error." << std::endl;
            continue;
        }

        // Otherwise, if no errors, check run state
        else if( m_pool_state == (int)ThreadPoolStatusType::POOL_STOPPED )
        {
            std::cout << "Pool has stopped.  Exiting." << std::endl;
        }


        // Otherwise, continue
        else
        {
            // Execute the Task
            worker_thread->Set_Running_Flag(true);
            m_number_assigned_workers++;
            worker_thread->Execute();
            worker_thread->Set_Running_Flag(false);

            // Delete the job
            worker_thread.reset();

            // Decrement the counter
            m_number_assigned_workers--;

        }

    }
    
}


/***********************************************/
/*          Assign Work to the Queue           */
/***********************************************/
void Thread_Pool::Assign_Work( Worker_Thread::ptr_t new_thread )
{
    
    // Make sure the new worker is not null
    if( new_thread == nullptr )
    {

    }

    // Otherwise, continue
    else
    {
        // Add the work
        m_queue.Push(new_thread);
    }
}


/********************************************/
/*      Get the list of running threads     */
/********************************************/
uint64_t Thread_Pool::Get_Current_Running_Threads()
{
    return m_threads.size();
}
            

/***********************************************/
/*          Count Work in  the Queue           */
/***********************************************/
int Thread_Pool::Get_Current_Work_Items()
{
    return m_number_assigned_workers;
}
            


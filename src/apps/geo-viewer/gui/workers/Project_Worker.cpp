/**
 * @file    Project_Worker.cpp
 * @author  Marvin Smith
 * @date    8/6/2017
 */
#include "Project_Worker.hpp"

// Project Info
#include "ImportProjectJob.hpp"

// GeoViewer Libraries
#include <GeoViewer/log/System_Logger.hpp>


/*****************************/
/*      Matching Worker      */
/*****************************/
Project_Worker::Project_Worker(System_Configuration::ptr_t sys_config)
  : m_sys_config(sys_config),
    m_class_name("Project_Worker")
{

}


/*************************************************/
/*         Initialize the Matching-Worker        */
/*************************************************/
void Project_Worker::Initialize()
{

    // Build the thread pool
    int pool_size = 2;
    m_thread_pool = std::make_shared<Thread_Pool>(pool_size);

    // Initialize the pool
    bool success;
    m_thread_pool->Initialize(success);

}


/*************************************************/
/*          Finalize the Matching-Worker         */
/*************************************************/
void Project_Worker::Finalize()
{
    // Destroy the thread pool
    bool status;
    m_thread_pool->Destroy_Pool(status);
    m_thread_pool = nullptr;

}


/***************************************/
/*         Import the Project          */
/***************************************/
void Project_Worker::Import_Project( const Config_Param& project_info )
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Create a load job
    Worker_Thread::ptr_t worker_thread = std::make_shared<ImportProjectJob>( project_info,
                                                                             m_sys_config );

    // Add to Thread Pool
    LOG_CLASS_TRACE("Adding Import-Project Worker Job");
    m_thread_pool->Assign_Work(worker_thread);

    // Log Exit
    LOG_CLASS_EXIT();
}

/**
 * @file    Matching_Worker.cpp
 * @author  Marvin Smith
 * @date    5/21/2017
 */
#include "Matching_Worker.hpp"


/*****************************/
/*      Matching Worker      */
/*****************************/
Matching_Worker::Matching_Worker(System_Configuration::ptr_t sys_config)
  : m_sys_config(sys_config),
    m_class_name("Matching_Worker")
{

}


/*************************************************/
/*         Initialize the Matching-Worker        */
/*************************************************/
void Matching_Worker::Initialize()
{

    // Build the thread pool
    int pool_size = 2;
    m_thread_pool = std::make_shared<Thread_Pool>(pool_size);

}


/*************************************************/
/*          Finalize the Matching-Worker         */
/*************************************************/
void Matching_Worker::Finalize()
{

}


/***************************************/
/*         Import the Project          */
/***************************************/
void Matching_Worker::Import_Project()
{

}

/**
 * @file    Main_Window.cpp
 * @author  Marvin Smith
 * @date    4/21/2017
 */
#include "Main_Window.hpp"


/**********************************/
/*          Constructor           */
/**********************************/
Main_Window::Main_Window( System_Configuration::ptr_t sys_config,
                          QWidget*                    parent )
 : QMainWindow(parent),
   m_class_name("Main_Window"),
   m_sys_config(sys_config)
{
}



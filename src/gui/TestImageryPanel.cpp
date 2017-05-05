/**
 * @file    TestImageryPanel.cpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#include "TestImageryPanel.hpp"

/********************************/
/*          Constructor         */
/********************************/
TestImageryPanel::TestImageryPanel( System_Configuration::ptr_t sys_config,
                                    QWidget*                    parent )
  : QWidget(parent),
    m_class_name("TestImageryPanel"),
    m_sys_config(sys_config)
{

    Initialize_GUI();
}

/************************************/
/*          Initialize GUI          */
/************************************/
void TestImageryPanel::Initialize_GUI()
{

    // Set the Window Title
    setWindowTitle("Test Imagery");
}

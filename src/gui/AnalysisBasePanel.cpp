/**
 * @brief AnalysisBasePanel.cpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#include "AnalysisBasePanel.hpp"


/********************************/
/*          Constructor         */
/********************************/
AnalysisBasePanel::AnalysisBasePanel( System_Configuration::ptr_t  sys_config,
                                      QWidget*                     parent )
  : QWidget(parent),
    m_class_name("AnalysisBasePanel"),
    m_sys_config(sys_config)
{

}

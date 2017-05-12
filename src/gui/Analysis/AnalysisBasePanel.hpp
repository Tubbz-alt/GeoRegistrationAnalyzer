/**
 * @file    AnalysisBasePanel.hpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#ifndef ANALYSIS_BASE_PANEL_HPP
#define ANALYSIS_BASE_PANEL_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"


/**
 * @class AnalysisBasePanel
*/
class AnalysisBasePanel : public QWidget
{

    public:

        /**
         * @brief Constructor
        */
        AnalysisBasePanel( System_Configuration::ptr_t sys_config,
                           QWidget*                    parent = nullptr );

    private:

        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t  m_sys_config;

}; // End of AnalysisBasePanel Class

#endif

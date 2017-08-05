/**
 * @file    AnalysisBasePanel.hpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#ifndef ANALYSIS_BASE_PANEL_HPP
#define ANALYSIS_BASE_PANEL_HPP

// Qt Libraries
#include <QWidget>

// GeoViewer Libraries
#include <GeoViewer/core/System_Configuration.hpp>

// Project Libraries
#include "../ProjectBasePanel.hpp"


/**
 * @class AnalysisBasePanel
*/
class AnalysisBasePanel : public ProjectBasePanel
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

}; // End of AnalysisBasePanel Class

#endif

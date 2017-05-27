/**
 * @file    NewProjectPanelMatching.hpp
 * @author  Marvin Smith
 * @date    5/25/2017
 */
#ifndef GUI_MATCHING_NEW_PROJECT_PANEL_MATCHING_HPP
#define GUI_MATCHING_NEW_PROJECT_PANEL_MATCHING_HPP

// C++ Libraries
#include <string>

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../NewProjectPanelBase.hpp"


/**
 * @class NewProjectPanelMatching
 */
class NewProjectPanelMatching : public NewProjectPanelBase
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        NewProjectPanelMatching( System_Configuration::ptr_t sys_config,
                                 QWidget*                    parent = nullptr );


    private:

        /// Class Name
        std::string m_class_name;

}; // End of NewProjectPanelMatching Class

#endif
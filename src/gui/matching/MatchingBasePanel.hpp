/**
 * @file    MatchingBasePanel.hpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#ifndef MATCHING_BASE_PANEL_HPP
#define MATCHING_BASE_PANEL_HPP

// Qt Libraries
#include <QSplitter>
#include <QTableWidget>
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "../ProjectBasePanel.hpp"
#include "ReferenceImageryPanel.hpp"
#include "TestImageryPanel.hpp"
#include "Toolbar/MatchingToolbarWidget.hpp"
#include "Worker/Matching_Worker.hpp"


/**
 * @class MatchingBasePanel
*/
class MatchingBasePanel : public ProjectBasePanel
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
        */
        MatchingBasePanel( System_Configuration::ptr_t sys_config,
                           QWidget*                    parent = nullptr );


        /**
         * @brief Destructor
         */
        virtual ~MatchingBasePanel();


        /**
        * @brief Import a new project
        *
        * @param project_info
        */
        virtual void Import_Project( const Config_Param& project_info );


    protected:

        /**
         * @brief Initialize the GUI
        */
        void Initialize_GUI();

    private:

        /// Class Name
        std::string m_class_name;

        /// Main Widgets
        QSplitter* m_main_splitter;

        /// Toolbar Widget
        MatchingToolbarWidget* m_toolbar_widget;

        /// Matching Worker
        Matching_Worker m_worker;

}; // End of MatchingBasePanel Class

#endif

/**
 * @file    Main_Window.hpp
 * @author  Marvin Smith
 * @date    4/21/2017
 */
#ifndef GUI_MAIN_WINDOW_HPP
#define GUI_MAIN_WINDOW_HPP

// Qt Libraries
#include <QMainWindow>
#include <QStackedWidget>


// Project Libraries
#include "../core/System_Configuration.hpp"
#include "AnalysisBasePanel.hpp"
#include "MatchingBasePanel.hpp"


/**
 * @class Main_Window
 */
class Main_Window : public QMainWindow
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         */
        Main_Window( System_Configuration::ptr_t  system_configuration,
                     QWidget*                     parent = nullptr );


    protected:

        /**
         * @brief Initialize GUI
        */
        void Initialize_GUI();

        /**
         * @brief Close the GUI
         *
         * @param event
         */
        void closeEvent(QCloseEvent *event);


    private:

        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Widget Stack
        QStackedWidget* m_stack_widget;

}; // End of Main_Window Class

#endif

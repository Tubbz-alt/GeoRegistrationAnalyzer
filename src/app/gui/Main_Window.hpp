/**
 * @file    Main_Window.hpp
 * @author  Marvin Smith
 * @date    4/21/2017
 */
#ifndef GUI_MAIN_WINDOW_HPP
#define GUI_MAIN_WINDOW_HPP

// Qt Libraries
#include <QMainWindow>

// Project Libraries
#include "../core/System_Configuration.hpp"

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


    private:
        
        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;


}; // End of Main_Window Class

#endif

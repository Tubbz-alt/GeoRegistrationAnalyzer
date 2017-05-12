/**
 * @file    TestImageryPanel.hpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#ifndef TEST_IMAGERY_PANEL_HPP
#define TEST_IMAGERY_PANEL_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"


/**
 * @class TestImageryPanel
*/
class TestImageryPanel : public QWidget
{
    public:

        /**
         * @brief Constructor
        */
        TestImageryPanel( System_Configuration::ptr_t sys_config,
                          QWidget*                    parent = nullptr );

    protected:

        /**
         * @brief Initialize the GUI
        */
        void Initialize_GUI();

        
    private:

        // Class Name
        std::string m_class_name;

        // System Configuration
        System_Configuration::ptr_t m_sys_config;

}; // End of TestImageryPanel Class

#endif

/**
 * @file    TestToolbar.hpp
 * @author  Marvin Smith
 * @date    5/18/2017
 */
#ifndef GUI_MATCHING_TEST_TOOLBAR_HPP
#define GUI_MATCHING_TEST_TOOLBAR_HPP

// Qt Libraries
#include <QGridLayout>
#include <QLineEdit>
#include <QToolButton>
#include <QWidget>


// Project Libraries
#include "../../core/System_Configuration.hpp"


/**
 * @class TestToolbar
 */
class TestToolbar : public QWidget
{
    public:

        /**
         * @brief Constructor
         */
        TestToolbar( System_Configuration::ptr_t sys_config,
                          QWidget*                    parent = nullptr );


    protected:

        /**
         * @brief Initialize GUI
         */
        void Initialize_GUI();


    private:

        /**
         * @brief Initialize Configuration
         */
        void Initialize_Configuration();

        /**
         * @brief Build the Source Widget
         */
        void Build_Source_Widget();


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Main Layout
        QGridLayout* m_main_layout;

        /// Datasource LineEdit
        QLineEdit* m_datasource_edit;

        /// Datasource Update Button
        QToolButton* m_datasource_update_button;

};


#endif
/**
 * @file    ProjectMatchingToolbarPane.hpp
 * @author  Marvin Smith
 * @date    5/19/2017
 */
#ifndef GUI_MATCHING_TOOLBAR_PROJECTMATCHINGTOOLBARPANE_HPP
#define GUI_MATCHING_TOOLBAR_PROJECTMATCHINGTOOLBARPANE_HPP

// C++ Libraries
#include <map>
#include <string>


// Qt Libraries
#include <QGridLayout>
#include <QLabel>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>


// Project Libraries
#include "../../../core/System_Configuration.hpp"


/**
 * @class PrimaryMatchingToolbarPane
 */
class ProjectMatchingToolbarPane : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         * @param sys_config
         * @param parent
         */
        ProjectMatchingToolbarPane( System_Configuration::ptr_t sys_config,
                                    QWidget*                    parent = nullptr );

    signals:

        /**
         * @brief Notify the back button was pressed.
         */
        void Notify_Change_Panel( int );

    protected:

        /**
         * @brief Initialize the GUI
         */
        void Initialize_GUI();

    private slots:

        /**
         * @brief Handle user pressing back button
         */
        void Back_Button_Pressed();

    private:

        /**
         * @brief Initialize the Configuration
         */
        void Initialize_Configuration();


        /**
         * @brief Build Label
         */
        void Build_Title_Widget();

        /**
         * @brief Build the Toolbar
         */
        void Build_Toolbar();


        /// Class name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// main layout
        QVBoxLayout* m_main_layout;

        /// List of Buttons (Key is Sys-Config Element Name, Value is button reference)
        std::map<std::string,QToolButton*> m_button_list;

};

#endif
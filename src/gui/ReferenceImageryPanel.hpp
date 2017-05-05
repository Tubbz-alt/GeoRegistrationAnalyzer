/**
 * @file    ReferenceImageryPanel.hpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#ifndef REFERENCE_IMAGERY_PANEL_HPP
#define REFERENCE_IMAGERY_PANEL_HPP

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../core/System_Configuration.hpp"

/**
 * @class ReferenceImageryPanel
*/
class ReferenceImageryPanel : public QWidget
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
        */
        ReferenceImageryPanel( System_Configuration::ptr_t system_config,
                               QWidget*                    parent = nullptr );

    protected:

        /**
         * @brief Initialize the GUI
        */
        void Initialize_GUI();

    private:

        /// Class Name
        std::string m_class_name;

        ///  System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Toolbar


}; // End of ReferenceImageryPanel Class

#endif

/**
 * @file    ReferenceToolbar.hpp
 * @author  Marvin Smith
 * @date    5/18/2017
 */
#ifndef GUI_MATCHING_REFERENCE_TOOLBAR_HPP
#define GUI_MATCHING_REFERENCE_TOOLBAR_HPP

// Qt Libraries
#include <QWidget>


// Project Libraries
#include "../../core/System_Configuration.hpp"


/**
 * @class ReferenceToolbar
 */
class ReferenceToolbar : public QWidget
{
    public:

        /**
         * @brief Constructor
         */
        ReferenceToolbar( System_Configuration::ptr_t sys_config,
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


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

};


#endif
/**
 * @file     Matching_Worker.hpp
 * @author   Marvin Smith
 * @date     5/21/2017
 */
#ifndef GUI_MATCHING_WORKER_MATCHING_WORKER_HPP
#define GUI_MATCHING_WORKER_MATCHING_WORKER_HPP

// C++ Libraries
#include <memory>
#include <string>

// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../../core/System_Configuration.hpp"


/**
 * @class Matching_Worker
 */
class Matching_Worker
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         *
         * @param sys_config
         */
        Matching_Worker(System_Configuration::ptr_t sys_config );


    protected:


        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

    private:

        /// Class Name
        std::string m_class_name;
};

#endif
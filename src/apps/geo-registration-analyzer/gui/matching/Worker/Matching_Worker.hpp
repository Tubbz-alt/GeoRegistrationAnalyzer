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
#include "../../../core/Config_Param.hpp"
#include "../../../core/System_Configuration.hpp"
#include "../../../core/Thread_Pool.hpp"


/**
 * @class Matching_Worker
 */
class Matching_Worker : public QObject
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         *
         * @param sys_config
         */
        Matching_Worker(System_Configuration::ptr_t sys_config );


        /**
         * @brief Initialize the Worker
         */
        void Initialize();


        /**
         * @brief Finalize the Matching-Worker
         */
        void Finalize();


        /**
         * @brief Import the project.
         *
         * @param project_info
         */
        void Import_Project( const Config_Param& project_info );


    protected:


        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

    private:

        /// Class Name
        std::string m_class_name;


        /// Active Thread Pool
        Thread_Pool::ptr_t m_thread_pool;
};

#endif
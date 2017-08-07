/**
 * @file     Project_Worker.hpp
 * @author   Marvin Smith
 * @date     8/6/2017
 */
#ifndef GEO_VIEWER_GUI_WORKERS_PROJECT_WORKER_HPP
#define GEO_VIEWER_GUI_WORKERS_PROJECT_WORKER_HPP

// C++ Libraries
#include <memory>
#include <string>

// Qt Libraries
#include <QWidget>

// GeoViewer Libraries
#include <GeoViewer/core/Config_Param.hpp>
#include <GeoViewer/core/System_Configuration.hpp>
#include <GeoViewer/core/Thread_Pool.hpp>


/**
 * @class Project_Worker
 */
class Project_Worker : public QObject
{
    Q_OBJECT

    public:

        /**
         * @brief Constructor
         *
         * @param sys_config
         */
        Project_Worker(System_Configuration::ptr_t sys_config );


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

};  // End of Project_Worker Class

#endif
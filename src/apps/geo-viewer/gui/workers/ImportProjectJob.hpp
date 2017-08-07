/**
 * @file    ImportProjectJob.hpp
 * @author  Marvin Smith
 * @date    8/6/2017
 */
#ifndef GEO_VIEWER_GUI_WORKERS_IMPORT_PROJECT_JOB_HPP
#define GEO_VIEWER_GUI_WORKERS_IMPORT_PROJECT_JOB_HPP

// Project Libraries
#include <GeoViewer/core/Config_Param.hpp>
#include <GeoViewer/core/System_Configuration.hpp>
#include <GeoViewer/core/Thread_Pool.hpp>


/**
 * @class ImportProjectJob
 */
class ImportProjectJob : public Worker_Thread
{
    public:

        /**
         * @brief Constructor
         */
        ImportProjectJob( const Config_Param&          project_info,
                          System_Configuration::ptr_t  sys_config );


        /**
         * @brief Execute the job
         */
        virtual int Execute();


    private:

        /**
         * @brief  Build Image Asset
         */
        void Build_Image_Asset( const std::string& panel_type,
                                const std::string& base_element )const;


        /// Class Name
        std::string m_class_name;

        /// System Configuration
        System_Configuration::ptr_t m_sys_config;

        /// Project Info
        Config_Param m_project_info;

}; // End of ImportProjectJob Class


#endif
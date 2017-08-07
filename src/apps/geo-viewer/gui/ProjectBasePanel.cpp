/**
 * @brief ProjectBasePanel.cpp
 * @author  Marvin Smith
 * @date    8/6/2017
*/
#include "ProjectBasePanel.hpp"

// Qt Libraries
#include <QHBoxLayout>
#include <QVBoxLayout>

// GeoViewer Libraries
#include <GeoViewer/log/System_Logger.hpp>

// Project Libraries
#include "ProjectImageryPanel.hpp"


/********************************/
/*          Constructor         */
/********************************/
ProjectBasePanel::ProjectBasePanel( System_Configuration::ptr_t  sys_config,
                                      QWidget*                     parent )
  : QWidget( parent),
    m_class_name("ProjectBasePanel"),
    m_sys_config(sys_config),
    m_worker(sys_config)
{
    // Initialize the GUI
    Initialize_GUI();

    // Start the worker
    m_worker.Initialize();
}


/*****************************/
/*        Destructor         */
/*****************************/
ProjectBasePanel::~ProjectBasePanel()
{
    // Stop the worker
    m_worker.Finalize();
}


/**************************************/
/*        Import a New Project        */
/**************************************/
void ProjectBasePanel::Import_Project( const Config_Param& project_info )
{
    // Notify the Matching Worker
    m_worker.Import_Project( project_info );

}


/****************************************/
/*          Initialize The GUI          */
/****************************************/
void ProjectBasePanel::Initialize_GUI()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Build the Main Layout
    QHBoxLayout* main_layout = new QHBoxLayout();

    // Build the Splitter
    m_main_splitter = new QSplitter(this);

    // Creating Test Imagery Panel
    LOG_CLASS_TRACE("Creating Imagery Panel");
    m_main_splitter->addWidget( new ProjectImageryPanel( m_sys_config, m_main_splitter));

    // Build the toolbar
    LOG_CLASS_TRACE("Creating Toolbar Panel");
    m_toolbar_widget = new ProjectToolbarWidget( m_sys_config,
                                                  this );
    m_main_splitter->addWidget(m_toolbar_widget);


    // Add to main Layout
    main_layout->addWidget( m_main_splitter );


    // Set layout
    setLayout( main_layout );

    // Log Exit
    LOG_CLASS_EXIT();
}

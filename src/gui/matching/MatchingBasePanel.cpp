/**
 * @brief MatchingBasePanel.cpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#include "MatchingBasePanel.hpp"

// Qt Libraries
#include <QHBoxLayout>
#include <QVBoxLayout>

// Project Libraries
#include "../../log/System_Logger.hpp"


/********************************/
/*          Constructor         */
/********************************/
MatchingBasePanel::MatchingBasePanel( System_Configuration::ptr_t  sys_config,
                                      QWidget*                     parent )
  : ProjectBasePanel( sys_config,
                      parent),
    m_class_name("MatchingBasePanel"),
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
MatchingBasePanel::~MatchingBasePanel()
{
    // Stop the worker
    m_worker.Finalize();
}


/**************************************/
/*        Import a New Project        */
/**************************************/
void MatchingBasePanel::Import_Project( const Config_Param& project_info )
{
    // Notify the Matching Worker
    m_worker.Import_Project( project_info );

}


/****************************************/
/*          Initialize The GUI          */
/****************************************/
void MatchingBasePanel::Initialize_GUI()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Build the Main Layout
    QHBoxLayout* main_layout = new QHBoxLayout();

    // Build the Splitter
    m_main_splitter = new QSplitter(this);

    // Creating the Reference Imagery Panel
    LOG_CLASS_TRACE("Creating Reference Imagery Panel");
    m_main_splitter->addWidget( new ReferenceImageryPanel( m_sys_config, m_main_splitter));

    // Creating the Test Imagery Panel
    LOG_CLASS_TRACE("Creating Test Imagery Panel");
    m_main_splitter->addWidget( new TestImageryPanel( m_sys_config, m_main_splitter));

    // Build the toolbar
    LOG_CLASS_TRACE("Creating Toolbar Panel");
    m_toolbar_widget = new MatchingToolbarWidget( m_sys_config,
                                                  this );
    m_main_splitter->addWidget(m_toolbar_widget);


    // Add to main Layout
    main_layout->addWidget( m_main_splitter );


    // Set layout
    setLayout( main_layout );

    // Log Exit
    LOG_CLASS_EXIT();
}

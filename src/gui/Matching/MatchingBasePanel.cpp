/**
 * @brief MatchingBasePanel.cpp
 * @author  Marvin Smith
 * @date    4/24/2017
*/
#include "MatchingBasePanel.hpp"

// Qt Libraries
#include <QHBoxLayout>
#include <QVBoxLayout>

/********************************/
/*          Constructor         */
/********************************/
MatchingBasePanel::MatchingBasePanel( System_Configuration::ptr_t  sys_config,
                                      QWidget*                     parent )
  : QWidget(parent),
    m_class_name("MatchingBasePanel"),
    m_sys_config(sys_config)
{
    Initialize_GUI();
}


/****************************************/
/*          Initialize The GUI          */
/****************************************/
void MatchingBasePanel::Initialize_GUI()
{
    // Build the Main Layout
    QHBoxLayout* main_layout = new QHBoxLayout();

    // Build the Splitter
    m_main_splitter = new QSplitter(this);

    m_main_splitter->addWidget( new ReferenceImageryPanel( m_sys_config, m_main_splitter));
    m_main_splitter->addWidget( new TestImageryPanel( m_sys_config, m_main_splitter));
    m_toolbar_widget = new MatchingToolbarWidget( m_sys_config,
                                                  this );
    m_main_splitter->addWidget(m_toolbar_widget);


    // Add to main Layout
    main_layout->addWidget( m_main_splitter );


    // Set layout
    setLayout( main_layout );

}

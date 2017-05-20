/**
 * @file     ProjectViewerPanelMatching.cpp
 * @author   Marvin Smith
 * @date     5/20/2017
 */
#include "ProjectViewerPanelMatching.hpp"

// Qt Libraries
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QToolButton>


/*********************************/
/*          Constructor          */
/*********************************/
ProjectViewerPanelMatching::ProjectViewerPanelMatching( const Config_Param&          project_info,
                                                        System_Configuration::ptr_t  sys_config,
                                                        QWidget*                     parent)
        : ProjectViewerPanelBase(project_info,
                                 sys_config,
                                 parent),
          m_class_name("ProjectViewerPanelMatching")
{
    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}


/************************************/
/*          Initialize GUI          */
/************************************/
void ProjectViewerPanelMatching::Initialize_GUI()
{
    // Create the main layout
    m_main_layout = new QVBoxLayout();

    // Create the label
    Build_Title_Widget();

    // Set the layout
    setLayout(m_main_layout);
}


/***********************************************/
/*          Initialize Configuration           */
/***********************************************/
void ProjectViewerPanelMatching::Initialize_Configuration()
{

}

/**************************************/
/*          Build the Label           */
/**************************************/
void ProjectViewerPanelMatching::Build_Title_Widget()
{
    // Create the main widget
    QWidget* widget = new QWidget(this);

    // Build the layout
    QHBoxLayout*  layout = new QHBoxLayout();

    // Set label
    QLabel*  project_label = new QLabel("Project Type: Matching");
    layout->addWidget(project_label);


    // Set the layout
    widget->setLayout(layout);

    // Add to main layout
    m_main_layout->addWidget(widget);
}

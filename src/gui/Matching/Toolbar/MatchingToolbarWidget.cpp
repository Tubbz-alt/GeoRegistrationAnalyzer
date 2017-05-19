/**
 * @brief MatchingToolbarWidget.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "MatchingToolbarWidget.hpp"

/**********************************/
/*          Constructor           */
/**********************************/
MatchingToolbarWidget::MatchingToolbarWidget(System_Configuration::ptr_t sys_config,
                                             QWidget *parent)
  : QWidget(parent),
    m_class_name("MatchingToolbarWidget"),
    m_sys_config(sys_config)
{
    // Initialize the Configuration
    Initialize_Configuration();


    // Initialize the GUI
    Initialize_GUI();
}


/*****************************************/
/*         Set the Primary Panel         */
/*****************************************/
void MatchingToolbarWidget::Change_Panel(int panel_id)
{
    std::cout << "Change_Panel:  Panel-ID: " << panel_id << std::endl;
    m_main_widget->setCurrentIndex(panel_id);
}

/*****************************************/
/*          Initialize the GUI           */
/*****************************************/
void MatchingToolbarWidget::Initialize_GUI()
{
    // Create the main layout
    m_main_layout = new QVBoxLayout();
    m_main_layout->setAlignment(Qt::AlignTop);

    // Create the stack widget
    m_main_widget = new QStackedWidget(this);

    // Build the primary panel
    Build_Primary_Panels();

    // Add to layout
    m_main_layout->addWidget(m_main_widget);

    // Set the layout
    setLayout(m_main_layout);
}


/**********************************************/
/*          Initialize the Configuration      */
/**********************************************/
void MatchingToolbarWidget::Initialize_Configuration()
{
    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.matching.toolbar.default.toolbutton.width",
                                   "60",
                                   "#  Default Width of Toolbar Panel Tool-Button",
                                   false);

    m_sys_config->Add_Config_Param("system.matching.toolbar.default.toolbutton.height",
                                   "100",
                                   "#  Default Height of Toolbar Panel Tool-Button",
                                   false);

    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.matching.toolbar.default.toolbutton.icon_width",
                                   "60",
                                   "#  Default Width of Toolbar Panel Tool-Button Icon",
                                   false);

    m_sys_config->Add_Config_Param("system.matching.toolbar.default.toolbutton.icon_height",
                                   "60",
                                   "#  Default Height of Toolbar Panel Tool-Button Icon",
                                   false);

}

/*******************************************/
/*          Build the Primary Panel        */
/*******************************************/
void MatchingToolbarWidget::Build_Primary_Panels()
{
    // Create the primary panel
    m_primary_panel = new PrimaryMatchingToolbarPane(m_sys_config,
                                                     m_main_widget);

    // Add to stack
    m_main_widget->addWidget(m_primary_panel);


    // Create the project panel
    m_project_panel = new ProjectMatchingToolbarPane(m_sys_config,
                                                     m_main_widget);

    m_main_widget->addWidget(m_project_panel);

    // Connect the panels
    connect(m_primary_panel, SIGNAL(Notify_Change_Panel(int)), this, SLOT(Change_Panel(int)));
    connect(m_project_panel, SIGNAL(Notify_Change_Panel(int)), this, SLOT(Change_Panel(int)));
}

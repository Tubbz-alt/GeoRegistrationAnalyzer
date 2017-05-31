/**
 * @file    PrimaryMatchingToolbarPane
 * @author  Marvin Smith
 * @date    5/19/2017
 */
#include "PrimaryMatchingToolbarPane.hpp"

/****************************************/
/*              Constructor             */
/****************************************/
PrimaryMatchingToolbarPane::PrimaryMatchingToolbarPane( System_Configuration::ptr_t  sys_config,
                                                        QWidget*                     parent)
  : QWidget(parent),
    m_class_name("PrimaryMatchingToolbarPane"),
    m_sys_config(sys_config)
{
    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();
}

/*****************************************/
/*          Initialize the GUI           */
/*****************************************/
void PrimaryMatchingToolbarPane::Initialize_GUI()
{
    // Create the main layout
    m_main_layout = new QGridLayout();
    m_main_layout->setAlignment(Qt::AlignTop);

    // Create the Label Widget
    Build_Title_Widget();

    // Build Tool Buttons
    Build_Tool_Buttons();

    // Set the layout
    setLayout(m_main_layout);
}


/*********************************************/
/*          Pressed Project Button           */
/*********************************************/
void PrimaryMatchingToolbarPane::Project_Button_Pressed()
{
    emit Notify_Change_Panel(1);
}

/**********************************************/
/*          Initialize the Configuration      */
/**********************************************/
void PrimaryMatchingToolbarPane::Initialize_Configuration()
{
    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.matching.toolbar.primary_panel.title",
                                   "Main Toolbar",
                                   "#  Name for the Primary Matching Toolbar Panel",
                                   false);

    m_sys_config->Add_Config_Param("system.matching.toolbar.primary_panel.project_button.text",
                                   "Project\\\nSettings",
                                   "#  Button Text",
                                   false );

    m_sys_config->Add_Config_Param("system.matching.toolbar.primary_panel.project_button.icon",
                                   "gear.png",
                                   "#  Primary Panels's Project Button Path",
                                   false );
}


/*********************************************/
/*           Build the Title Widget          */
/*********************************************/
void PrimaryMatchingToolbarPane::Build_Title_Widget()
{
    // Get the attributes required
    bool match_found;
    std::string title_str = m_sys_config->Query_Config_Param("system.matching.toolbar.primary_panel.title",
                                                             match_found,
                                                             "Primary Toolbar");

    // Create the title widget
    QWidget* title_widget = new QWidget(this);

    // Create the layout
    QHBoxLayout* title_layout = new QHBoxLayout();

    // Create the label
    QLabel* title_label = new QLabel(title_str.c_str(), title_widget);
    title_layout->addWidget(title_label);

    // Set the layout
    title_widget->setLayout(title_layout);

    // Add to main panel
    m_main_layout->addWidget(title_widget, 0, 0, 1, 3);

}


/******************************************/
/*          Build the Tool Buttons        */
/******************************************/
void PrimaryMatchingToolbarPane::Build_Tool_Buttons()
{
    // Get Default Sizes
    bool value_found;
    int def_button_height = m_sys_config->Query_Config_Param_Int32("system.matching.toolbar.default.toolbutton.height", value_found);
    int def_button_width = m_sys_config->Query_Config_Param_Int32("system.matching.toolbar.default.toolbutton.width", value_found);
    int def_icon_height = m_sys_config->Query_Config_Param_Int32("system.matching.toolbar.default.toolbutton.icon_height", value_found);
    int def_icon_width = m_sys_config->Query_Config_Param_Int32("system.matching.toolbar.default.toolbutton.icon_width", value_found);
    std::string button_title, button_icon_path;

    // Icon base path
    std::string icon_base_path = m_sys_config->Get_Icon_Path();

    // Create the button for the project management
    button_title = m_sys_config->Query_Config_Param("system.matching.toolbar.primary_panel.project_button.text", value_found);
    button_icon_path = m_sys_config->Query_Config_Param("system.matching.toolbar.primary_panel.project_button.icon", value_found);
    button_icon_path = icon_base_path + "/" + button_icon_path;
    std::string title_str = "system.matching.toolbar.primary_panel.project_button";
    m_button_list[title_str] = new QToolButton();
    m_button_list[title_str]->setText(button_title.c_str());
    m_button_list[title_str]->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    m_button_list[title_str]->setIcon(QIcon(button_icon_path.c_str()));
    m_button_list[title_str]->setFixedSize(def_button_width, def_button_height);
    m_button_list[title_str]->setIconSize(QSize(def_icon_width, def_icon_height));
    connect(m_button_list[title_str], SIGNAL(clicked()), this, SLOT(Project_Button_Pressed()));

    // Add to widget
    m_main_layout->addWidget(m_button_list[title_str], 1, 0, 1, 1);

}


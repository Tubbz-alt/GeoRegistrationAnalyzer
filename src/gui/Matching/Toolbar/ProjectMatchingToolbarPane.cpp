/**
 * @file    ProjectMatchingToolbarPane
 * @author  Marvin Smith
 * @date    5/19/2017
 */
#include "ProjectMatchingToolbarPane.hpp"

/****************************************/
/*              Constructor             */
/****************************************/
ProjectMatchingToolbarPane::ProjectMatchingToolbarPane( System_Configuration::ptr_t  sys_config,
                                                        QWidget*                     parent)
        : QWidget(parent),
          m_class_name("ProjectMatchingToolbarPane"),
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
void ProjectMatchingToolbarPane::Initialize_GUI()
{
    // Create the main layout
    m_main_layout = new QVBoxLayout();
    m_main_layout->setAlignment(Qt::AlignTop);

    // Create the Label Widget
    Build_Title_Widget();

    // Build Toolbar
    Build_Toolbar();

    // Set the layout
    setLayout(m_main_layout);
}

/**********************************************/
/*        Process User Back Button            */
/**********************************************/
void ProjectMatchingToolbarPane::Back_Button_Pressed()
{
    emit Notify_Change_Panel(0);
}

/**********************************************/
/*          Initialize the Configuration      */
/**********************************************/
void ProjectMatchingToolbarPane::Initialize_Configuration()
{
    // Set Default Configuration Parameters
    m_sys_config->Add_Config_Param("system.matching.toolbar.project_panel.title",
                                   "Project Settings",
                                   "#  Name for the Project Matching Toolbar Panel",
                                   false);

    m_sys_config->Add_Config_Param("system.matching.toolbar.project_panel.back_button.text",
                                   "Back",
                                   "# Project Panel Back Button Text",
                                   false );

    m_sys_config->Add_Config_Param("system.matching.toolbar.project_panel.back_button.icon",
                                   "left_arrow.png",
                                   "# Project Panel Back Button Icon Path",
                                   false );
}


/*********************************************/
/*           Build the Title Widget          */
/*********************************************/
void ProjectMatchingToolbarPane::Build_Title_Widget()
{
    // Get the attributes required
    bool match_found;
    std::string title_str = m_sys_config->Query_Config_Param("system.matching.toolbar.project_panel.title",
                                                             match_found,
                                                             "Project Settings");

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
    m_main_layout->addWidget(title_widget);

}


/******************************************/
/*          Build the Tool Buttons        */
/******************************************/
void ProjectMatchingToolbarPane::Build_Toolbar()
{
    // Create teh toolbar Widget
    QWidget*  toolbar_widget = new QWidget(this);

    // Create the layout
    QHBoxLayout* toolbar_layout = new QHBoxLayout();

    // Get Default Sizes
    bool value_found;
    int def_button_height = m_sys_config->Query_Config_Param_Int32("system.matching.toolbar.default.toolbutton.height", value_found);
    int def_button_width = m_sys_config->Query_Config_Param_Int32("system.matching.toolbar.default.toolbutton.width", value_found);
    int def_icon_height = m_sys_config->Query_Config_Param_Int32("system.matching.toolbar.default.toolbutton.icon_height", value_found);
    int def_icon_width = m_sys_config->Query_Config_Param_Int32("system.matching.toolbar.default.toolbutton.icon_width", value_found);
    std::string button_title, button_icon_path;

    // Icon base path
    std::string icon_base_path = m_sys_config->Get_Icon_Path();

    // Create the back button
    button_title = m_sys_config->Query_Config_Param("system.matching.toolbar.project_panel.back_button.text", value_found);
    button_icon_path = m_sys_config->Query_Config_Param("system.matching.toolbar.project_panel.back_button.icon", value_found);
    button_icon_path = icon_base_path + "/" + button_icon_path;
    std::string title_str = "system.matching.toolbar.primary_panel.project_button";
    std::cout << "Width: " << def_button_width << ", Height: " << def_button_height << std::endl;
    m_button_list[title_str] = new QToolButton();
    m_button_list[title_str]->setText(button_title.c_str());
    m_button_list[title_str]->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonTextUnderIcon);
    m_button_list[title_str]->setIcon(QIcon(button_icon_path.c_str()));
    m_button_list[title_str]->setFixedSize(def_button_width, def_button_height);
    m_button_list[title_str]->setIconSize(QSize(def_icon_width, def_icon_height));
    connect(m_button_list[title_str], SIGNAL(clicked()), this, SLOT(Back_Button_Pressed()));

    // Add to widget
    toolbar_layout->addWidget(m_button_list[title_str]);

    // Set hte layout
    toolbar_widget->setLayout(toolbar_layout);

    // Add to main
    m_main_layout->addWidget(toolbar_widget);

}


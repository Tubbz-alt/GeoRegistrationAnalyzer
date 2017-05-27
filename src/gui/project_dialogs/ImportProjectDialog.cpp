/**
 * @file    ImportProjectDialog.cpp
 * @author  Marvin Smith
 * @date    5/20/2017
 */
#include "ImportProjectDialog.hpp"

// Qt Libraries
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <QToolButton>




/************************************/
/*            Constructor           */
/************************************/
ImportProjectDialog::ImportProjectDialog( System_Configuration::ptr_t sys_config,
                                          QWidget*                    parent)
  : QDialog(parent),
    m_class_name("ImportProjectDialog"),
    m_sys_config(sys_config),
    m_project_loaded(false)
{
    // Initialize Configuration
    Initialize_Configuration();

    // Initialize GUI
    Initialize_GUI();

}


/*****************************************/
/*           Import File Slot            */
/*****************************************/
void ImportProjectDialog::Import_Project_File()
{
    // Create File Chooser
    QString pathname = QFileDialog::getOpenFileName( this,
                                                     tr("Open Project"),
                                                     "~/",
                                                     tr("Project Files (*.cfg)"));

    // If the file exists, open it
    if( QFile(pathname).exists() )
    {
        // Load the file
        bool load_status;
        m_project_info = Config_Param::Load_Key_Value_File(pathname.toStdString(), load_status );


        if( load_status )
        {
            // Set the project panel
            m_project_panel = ProjectViewerPanelFactory::Create(m_project_info,
                                                                m_sys_config,
                                                                this );

            if( m_project_panel == nullptr )
            {
                std::cerr << "Unable to build panel." << std::endl;
                std::exit(-1);
            }

            m_project_layout->replaceWidget(m_stub_panel, m_project_panel);


            // Change the widget
            m_stack_widget->setCurrentIndex(1);
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText(("Error: Unable to process " + pathname.toStdString()).c_str());
            msgBox.exec();
        }
    }

    // Otherwise, popup


}


/************************************************/
/*          Import the Project and Close        */
/************************************************/
void ImportProjectDialog::Import_Project()
{
    // Set the loaded flag
    m_project_loaded = true;

    // Close the widget
    close();
}

/*******************************/
/*      Initialize the GUI     */
/*******************************/
void ImportProjectDialog::Initialize_GUI()
{
    // Query Relevant Parameters
    bool value_found;

    std::string window_title = m_sys_config->Query_Config_Param("system.gui.import_project.title", value_found );

    // Create the main layout
    m_main_layout = new QVBoxLayout();

    m_stack_widget = new QStackedWidget();

    // Build the File Chooser
    Build_File_Chooser();

    // Build the Project Viewer Button
    Build_Project_Viewer();

    m_main_layout->addWidget(m_stack_widget);

    // Set the layout
    setLayout(m_main_layout);

    setWindowTitle(window_title.c_str());
}


/*************************************/
/*      Initialize Configuration     */
/*************************************/
void ImportProjectDialog::Initialize_Configuration()
{
    // Title of Pref Dialog
    m_sys_config->Add_Config_Param("system.gui.import_project.title",
                                   "Import Project",
                                   "#  Title of Dialog",
                                   false );

    // Button Sizes
    m_sys_config->Add_Config_Param("system.gui.import_project.button_width",
                                   "70",
                                   "#  Width of Import Project Button",
                                   false );

    m_sys_config->Add_Config_Param("system.gui.import_project.button_height",
                                   "40",
                                   "#  Height of Import Project Button",
                                   false );
}


/**********************************************/
/*       Build the Project File Chooser       */
/**********************************************/
void ImportProjectDialog::Build_File_Chooser()
{
    bool value_found;
    int button_width  = m_sys_config->Query_Config_Param_Int32("system.gui.import_project.button_width", value_found);
    int button_height = m_sys_config->Query_Config_Param_Int32("system.gui.import_project.button_height", value_found);

    QWidget* widget = new QWidget(this);

    QVBoxLayout* layout = new QVBoxLayout();

    std::string widget_text;
    widget_text += "1.  Click on \"Import File\" Button to Load Project File.\n\n";
    widget_text += "2.  View Project Changes.  Then select the \"Import\" Button.\n\n";
    widget_text += "Note:  At any time, select \"Cancel\" to abort changes.";


    // Create the label
    QLabel* label = new QLabel();
    label->setText(widget_text.c_str());
    layout->addWidget(label);

    // Select Button
    QWidget* toolbar_widget = new QWidget();
    QHBoxLayout* toolbar_layout = new QHBoxLayout();

    // Create Import Button
    QToolButton* import_button = new QToolButton();
    import_button->setText("Import File");
    import_button->setFixedSize( button_width,
                                 button_height);
    toolbar_layout->addWidget(import_button);
    connect(import_button, SIGNAL(clicked()), this, SLOT(Import_Project_File()));

    // Create Cancel Button
    QToolButton* cancel_button = new QToolButton();
    cancel_button->setText("Cancel");
    cancel_button->setFixedSize( button_width,
                                 button_height);
    toolbar_layout->addWidget(cancel_button);
    connect( cancel_button, SIGNAL(clicked()), this, SLOT(close()));


    toolbar_widget->setLayout(toolbar_layout);
    layout->addWidget(toolbar_widget);


    // Select Layout
    widget->setLayout(layout);

    // Add to stack layout
    m_stack_widget->addWidget(widget);
}

/****************************************/
/*       Build the Project Viewer       */
/****************************************/
void ImportProjectDialog::Build_Project_Viewer()
{
    // Query Button Sizes
    bool value_found;
    int button_width  = m_sys_config->Query_Config_Param_Int32("system.gui.import_project.button_width", value_found);
    int button_height = m_sys_config->Query_Config_Param_Int32("system.gui.import_project.button_height", value_found);


    // Build main widget
    QWidget* widget = new QWidget(this);

    // Build main layout
    m_project_layout = new QVBoxLayout();

    /// Create base panel
    m_stub_panel = new QWidget(this);
    m_project_layout->addWidget(m_stub_panel);

    // Toolbar
    QWidget* toolbar_widget = new QWidget();
    QHBoxLayout* toolbar_layout = new QHBoxLayout();

    // Create Import Button
    QToolButton* import_button = new QToolButton();
    import_button->setText("Import");
    import_button->setFixedSize( button_width,
                                 button_height);
    toolbar_layout->addWidget(import_button);
    connect(import_button, SIGNAL(clicked()), this, SLOT(Import_Project()));

    // Create Cancel Button
    QToolButton* cancel_button = new QToolButton();
    cancel_button->setText("Cancel");
    cancel_button->setFixedSize( button_width,
                                 button_height);
    toolbar_layout->addWidget(cancel_button);
    connect( cancel_button, SIGNAL(clicked()), this, SLOT(close()));


    toolbar_widget->setLayout(toolbar_layout);
    m_project_layout->addWidget(toolbar_widget);

    // Select Layout
    widget->setLayout(m_project_layout);

    // Add to stack layout
    m_stack_widget->addWidget(widget);

}

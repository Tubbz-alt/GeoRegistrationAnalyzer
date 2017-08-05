/**
 * @file    ConfigurationSaveDialog.cpp
 * @author  Marvin Smith
 * @date    5/16/2017
 */
#include "ConfigurationSaveDialog.hpp"

// Qt Libraries
#include <QDialog>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>


/***********************************/
/*          Constructor            */
/***********************************/
ConfigurationSaveDialog::ConfigurationSaveDialog(System_Configuration::ptr_t sys_config,
                                                 QWidget*                    parent)
  : m_class_name("ConfigurationSaveDialog"),
    m_save_config(false),
    m_sys_config(sys_config)
{
    // Setup Configuration
    Initialize_Configuration();

    // Initialize GUI
    Initialize_GUI();

}


/*********************************/
/*          Save Action          */
/*********************************/
void ConfigurationSaveDialog::Save_Action()
{
    // Set the flag
    m_save_config = true;

    // Close
    close();
}


/*********************************/
/*         Cancel Action         */
/*********************************/
void ConfigurationSaveDialog::Cancel_Action()
{
    // Set the flag
    m_save_config = false;

    // Close
    close();
}


/************************************/
/*          Update Pathname         */
/************************************/
void ConfigurationSaveDialog::Update_Pathname()
{
    // Set the pathname
    std::string pathname = m_pathname_line_edit->text().toStdString();
}


/********************************************/
/*          Initialize the GUI              */
/********************************************/
void ConfigurationSaveDialog::Initialize_GUI()
{
    // Config File Pathname
    std::string config_pathname = m_sys_config->Get_Configuration_File_Pathname();
    std::cout << "Config Pathname: " << config_pathname << std::endl;

    // Create Main Layout
    QVBoxLayout* main_layout = new QVBoxLayout();

    // Add Title Widget
    QWidget*   title_widget = new QWidget(this);
    QHBoxLayout* title_layout = new QHBoxLayout();
    QLabel*    title_label = new QLabel("Configuration File Not Found.\nDo you wish to create a default configuration file?", this);
    title_layout->addWidget(title_label);
    title_widget->setLayout(title_layout);
    main_layout->addWidget(title_widget);


    // Add Text Dialog
    QWidget*  text_widget = new QWidget(this);
    QHBoxLayout* text_layout = new QHBoxLayout();

    QLabel* text_label = new QLabel("Config Path:");
    text_layout->addWidget(text_label);

    m_pathname_line_edit = new QLineEdit();
    m_pathname_line_edit->setText(config_pathname.c_str());
    text_layout->addWidget(m_pathname_line_edit);

    m_pathname_button = new QToolButton();
    text_layout->addWidget(m_pathname_button);

    text_widget->setLayout(text_layout);
    main_layout->addWidget(text_widget);


    // Add Toolbar
    QWidget* toolbar_widget = new QWidget(this);
    QHBoxLayout* toolbar_layout = new QHBoxLayout();
    QToolButton* toolbar_save_button = new QToolButton(toolbar_widget);
    toolbar_save_button->setText("Save");
    toolbar_layout->addWidget(toolbar_save_button);
    QToolButton* toolbar_cancel_button = new QToolButton(toolbar_widget);
    toolbar_cancel_button->setText("Cancel");
    toolbar_layout->addWidget(toolbar_cancel_button);
    toolbar_widget->setLayout(toolbar_layout);
    main_layout->addWidget(toolbar_widget);


    // Connect Widgets
    connect( toolbar_save_button, SIGNAL(clicked()), this, SLOT(Save_Action()));
    connect( toolbar_cancel_button, SIGNAL(clicked()), this, SLOT(Cancel_Action()));
    connect( m_pathname_line_edit, SIGNAL(textChanged(const QString&)), this, SLOT(Update_Pathname()));

    // Set main layout
    setLayout(main_layout);
}


/********************************************/
/*          Initialize Configuration        */
/********************************************/
void ConfigurationSaveDialog::Initialize_Configuration()
{

}


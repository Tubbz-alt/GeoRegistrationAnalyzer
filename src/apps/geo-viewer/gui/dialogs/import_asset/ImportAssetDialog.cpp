/**
 * @file    ImportAssetDialog.cpp
 * @author  Marvin Smith
 * @date    8/7/2017
 */
#include "ImportAssetDialog.hpp"

// Qt Libraries
#include <QGroupBox>
#include <QHBoxLayout>
#include <QSizePolicy>


// GeoViewer Libraries
#include <GeoViewer/core/assets.hpp>
#include <GeoViewer/log/System_Logger.hpp>
#include <QStandardPaths>


/********************************/
/*          Constructor         */
/********************************/
ImportAssetDialog::ImportAssetDialog(System_Configuration::ptr_t sys_config,
                                     QWidget*                    parent)
  : QDialog(parent),
    m_class_name("ImportAssetDialog"),
    m_sys_config(sys_config)
{
    // Initialize the Configuration
    Initialize_Configuration();

    // Initialize the GUI
    Initialize_GUI();

}


/************************************/
/*          Reset the Dialog        */
/************************************/
void ImportAssetDialog::Reset_Action()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Reset Easy Import WIdget
    m_easy_import_widget->Reset_Action();

    // Set Index
    Set_Panel_Index(0);

    // Log Exit
    LOG_CLASS_EXIT();
}


/************************************/
/*          Import the Asset        */
/************************************/
void ImportAssetDialog::Import_Action()
{
    // Log Entry
    LOG_CLASS_ENTRY();


    // Log Exit
    LOG_CLASS_EXIT();
}


/************************************/
/*          Cancel Action           */
/************************************/
void ImportAssetDialog::Cancel_Action()
{
    // Log Entry
    LOG_CLASS_ENTRY();



    // Close the Dialog
    close();

    // Log Exit
    LOG_CLASS_EXIT();
}


/****************************************/
/*          Set the Panel Index         */
/****************************************/
void ImportAssetDialog::Set_Panel_Index( int index)
{
    // Log Entry
    LOG_TRACE("Start of Method. Index: " + std::to_string(index));

    // Set the Index
    m_import_viewer_stack->setCurrentIndex(index);
}


/****************************************/
/*          Show Easy Import Pane       */
/****************************************/
void ImportAssetDialog::Show_Easy_Import_Pane()
{
    Set_Panel_Index(1);
}




/*********************************************************/
/*         Initialize the Configuration Settings         */
/*********************************************************/
void ImportAssetDialog::Initialize_Configuration()
{

}


/*********************************************************/
/*                 Initialize the GUI                    */
/*********************************************************/
void ImportAssetDialog::Initialize_GUI()
{
    // Create the main layout
    m_main_layout = new QVBoxLayout();

    // Create stack widget
    m_import_viewer_stack = new QStackedWidget(this);
    m_main_layout->addWidget(m_import_viewer_stack);

    // Build Title Layer
    Build_Title_Pane();

    // Build the Easy Import Pane
    Build_Easy_Import_Pane();

    // Build the Advanced Pane
    Build_Advanced_Import_Pane();

    // Build the Toolbar
    Build_Toolbar();

    // Set the layout
    setLayout(m_main_layout);
}


/************************************/
/*          Build the Toolbar       */
/************************************/
void ImportAssetDialog::Build_Toolbar()
{
    // Create the toolbar widget
    QGroupBox*  toolbar_widget = new QGroupBox("Toolbar",this);

    // Create the toolbar layout
    QHBoxLayout* toolbar_layout = new QHBoxLayout();

    // Create Reset Button
    QToolButton* reset_button = new QToolButton(toolbar_widget);
    reset_button->setText("Reset");
    toolbar_layout->addWidget(reset_button);
    connect(reset_button, SIGNAL(clicked()), this, SLOT(Reset_Action()));

    // Create Save Button
    QToolButton* import_button = new QToolButton(toolbar_widget);
    import_button->setText("Import");
    toolbar_layout->addWidget(import_button);
    connect(import_button, SIGNAL(clicked()), this, SLOT(Import_Action()));


    // Create Cancel Button
    QToolButton* cancel_button = new QToolButton(toolbar_widget);
    cancel_button->setText("Cancel");
    toolbar_layout->addWidget(cancel_button);
    connect(cancel_button, SIGNAL(clicked()), this, SLOT(Cancel_Action()));

    // Set toolbar layout
    toolbar_widget->setLayout(toolbar_layout);

    // Add to main layout
    m_main_layout->addWidget(toolbar_widget);
}


/****************************************/
/*          Build the Title Pane        */
/****************************************/
void ImportAssetDialog::Build_Title_Pane()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Build actual widget
    QWidget* title_pane = new QWidget(m_import_viewer_stack);

    // Create Layout
    QVBoxLayout* title_layout = new QVBoxLayout();

    // Create Easy Button
    QToolButton* easy_button = new QToolButton(title_pane);
    easy_button->setText("File Import");
    title_layout->addWidget(easy_button);
    connect(easy_button, SIGNAL(clicked()), this, SLOT(Show_Easy_Import_Pane()));


    // Create Advanced Button
    QToolButton* advanced_button = new QToolButton();
    advanced_button->setText("Advanced Import");
    advanced_button->setToolTip("Not Implemented Yet");
    title_layout->addWidget(advanced_button);

    // Add to widget
    title_pane->setLayout(title_layout);

    // Add to stack widget
    m_import_viewer_stack->addWidget(title_pane);

    // Log Exit
    LOG_CLASS_EXIT();
}


/**********************************************/
/*          Build the Easy Import Pane        */
/**********************************************/
void ImportAssetDialog::Build_Easy_Import_Pane()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Create widget
    m_easy_import_widget = new ImportAssetEasyWidget(m_sys_config, this);


    // Add to stack
    m_import_viewer_stack->addWidget(m_easy_import_widget);

    // Log Exit
    LOG_CLASS_EXIT();
}


/******************************************/
/*      Build the Advanced Import Pane    */
/******************************************/
void ImportAssetDialog::Build_Advanced_Import_Pane()
{

}



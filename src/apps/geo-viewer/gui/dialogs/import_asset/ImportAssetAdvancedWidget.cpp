/**
 * @file    ImportAssetAdvancedWidget.cpp
 * @author  Marvin Smith
 * @date    8/12/2017
 */
#include "ImportAssetAdvancedWidget.hpp"

// GeoViewer Libraries
#include <GeoViewer/core/assets.hpp>
#include <GeoViewer/core/System_Manager.hpp>
#include <GeoViewer/gui/asset_info/Asset_Info_Widget_Factory.hpp>
#include <GeoViewer/log/System_Logger.hpp>

// Qt Libraries
#include <QFileDialog>
#include <QGroupBox>
#include <QToolButton>


/********************************/
/*          Constructor         */
/********************************/
ImportAssetAdvancedWidget::ImportAssetAdvancedWidget(System_Configuration::ptr_t sys_config,
                                                     QWidget*                    parent)
{
    // Initialize the GUI
    Initialize_GUI();
}


/*******************************************/
/*          Get Asset Information          */
/*******************************************/
Config_Param ImportAssetAdvancedWidget::Get_Asset_Info() const
{
    return Config_Param();//((Asset_Info_Widget_Base*)m_info_panel)->Get_Asset_Info();
}


/****************************************/
/*               Reset Action           */
/****************************************/
void ImportAssetAdvancedWidget::Reset_Action()
{

}


/**********************************************/
/*      Notify UI That an Asset is Valid      */
/**********************************************/
void ImportAssetAdvancedWidget::Notify_Asset_Valid()
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Emit Import Signal
    emit Enable_Import_Button();
}

/********************************/
/*          Initialize GUI      */
/********************************/
void ImportAssetAdvancedWidget::Initialize_GUI()
{

    // Create Layout
    m_main_layout = new QGridLayout();
    m_main_layout->setAlignment(Qt::AlignTop);

    // Set the Main Layout
    setLayout(m_main_layout);
}


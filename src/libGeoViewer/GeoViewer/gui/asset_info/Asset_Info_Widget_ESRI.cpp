/**
 * @file    Asset_Info_Widget_ESRI.cpp
 * @author  Marvin Smith
 * @date    8/13/2017
 */
#include "Asset_Info_Widget_ESRI.hpp"

// Qt Libraries
#include <QHeaderView>

// GeoViewer Libraries
#include <GeoViewer/log.hpp>


// C++ Libraries
#include <tuple>
#include <vector>


/********************************/
/*          Constructor         */
/********************************/
Asset_Info_Widget_ESRI::Asset_Info_Widget_ESRI(const Config_Param& asset_info,
                                               QWidget*            parent)
 : Asset_Info_Widget_Base(asset_info,
                          parent),
   m_class_name("Asset_Info_Widget_ESRI")
{
    // Log Entry
    LOG_CLASS_ENTRY();

    Initialize_GUI();

    // Log Exit
    LOG_CLASS_EXIT();
}



/********************************/
/*          Constructor         */
/********************************/
Asset_Info_Widget_ESRI::~Asset_Info_Widget_ESRI()
{
}

/****************************************/
/*          Update Table Data           */
/****************************************/
void Asset_Info_Widget_ESRI::Update_Table_Data()
{
    // Resize the number of rows
    m_info_table->setRowCount(m_asset_info_list.size());

    // Build Table
    int counter = 0;
    for( auto tup : m_asset_info_list ) {
        m_info_table->setItem(counter, 0, new QTableWidgetItem(std::get<0>(tup).c_str()));
        m_info_table->setItem(counter, 1, new QTableWidgetItem(std::get<1>(tup).c_str()));
        counter++;
    }

    m_info_table->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
    m_info_table->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
}


/************************************/
/*        Initialize the GUI        */
/************************************/
void Asset_Info_Widget_ESRI::Initialize_GUI()
{
    // Misc Args
    m_valid_asset = false;
    m_asset_status = "No Data Given";
    bool value_found;

    // Get all entries for asset
    auto conf_list = m_asset_info.Get_Config_List();
    for( auto p : conf_list )
    {
        m_asset_info_list.push_back(std::make_tuple(p.first, p.second));
        LOG_CLASS_TRACE("Adding Key: " + p.first + ", Value: " + p.second);
    }
    if( m_asset_info_list.size() > 0 )
    {
        m_valid_asset = true;
        m_asset_status = "Select Import to Load from Disk.";
    }


    // Create Layout
    m_main_layout = new QVBoxLayout();


    // Build the Table Widget
    Build_Table_Widget();

    // Build the status widget
    Build_Status_Widget();

    // Set layout
    setLayout(m_main_layout);
}


/************************************************/
/*          Build the Table Widget              */
/************************************************/
void Asset_Info_Widget_ESRI::Build_Table_Widget()
{
    // Create group box
    m_info_group = new QGroupBox("Asset Information");
    m_info_group->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Create group layout
    m_info_layout = new QVBoxLayout();

    // Add the table
    m_info_table = new QTableWidget(0, 2, m_info_group);
    QStringList header_labels;
    header_labels.push_back("Key");
    header_labels.push_back("Value");
    m_info_table->setHorizontalHeaderLabels(header_labels);
    m_info_table->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_info_layout->addWidget(m_info_table);


    // Update Columns
    Update_Table_Data();


    // Set the layout
    m_info_group->setLayout(m_info_layout);

    // Add to layout
    m_main_layout->addWidget(m_info_group);
}


/************************************************/
/*          Build the Status Widget             */
/************************************************/
void Asset_Info_Widget_ESRI::Build_Status_Widget()
{
    // Create the primary widget
    m_status_group = new QGroupBox("Asset Status", this );

    // Create Grid
    m_status_layout = new QGridLayout();

    // Create Status Widget
    std::string asset_status = "Valid";
    if( !m_valid_asset ){
        asset_status = "Invalid";
    }
    m_status_label = new QLabel(asset_status.c_str(), m_status_group);
    m_status_label->setFixedHeight(30);
    m_status_label->setFixedWidth(100);
    if( m_valid_asset ){
        m_status_label->setStyleSheet("QLabel { color : green; }");
    }
    else{
        m_status_label->setStyleSheet("QLabel { color : red; }");
    }
    m_status_layout->addWidget(m_status_label, 0, 0, 1, 1);

    // Create Edit
    m_status_details = new QTextEdit(m_status_group);
    m_status_details->setFixedHeight(30);
    m_status_details->setText(m_asset_status.c_str());
    m_status_details->setReadOnly(true);
    m_status_details->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_status_layout->addWidget(m_status_details, 0, 1, 1, 1);

    // Set layout
    m_status_group->setLayout(m_status_layout);

    // Add to Main Layout
    m_main_layout->addWidget(m_status_group);
}

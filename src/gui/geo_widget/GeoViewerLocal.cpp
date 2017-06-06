/**
 * @file GeoViewerLocal.cpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#include "GeoViewerLocal.hpp"

// Qt Libraries
#include <QGraphicsPixmapItem>
#include <QVBoxLayout>


// Project Libraries
#include "../../core/assets/Asset_Image_Local.hpp"
#include "../../log/System_Logger.hpp"


/*********************************/
/*          Constructor          */
/*********************************/
GeoViewerLocal::GeoViewerLocal( const std::string&          base_config_profile,
                                System_Configuration::ptr_t sys_config,
                                QWidget *parent)
 : GeoViewerBase( base_config_profile,
                  sys_config,
                  parent),
   m_class_name("GeoViewerLocal")
{
    // Update the config object
    Update_Configuration();

    // Initialize the Scene
    Initialize_Scene();

    // Build the GUI
    Initialize_GUI();

}

/****************************************/
/*          Initialize the GUI          */
/****************************************/
void GeoViewerLocal::Initialize_GUI()
{
    // Create Layout
    QVBoxLayout* main_layout = new QVBoxLayout();

    // Build View
    m_view = new QGraphicsView(&m_scene, this);
    main_layout->addWidget(m_view);
    main_layout->setContentsMargins(0,0,0,0);

    // Set layout
    setLayout(main_layout);

}


/*********************************/
/*        Update the Asset       */
/*********************************/
void GeoViewerLocal::Update_Asset(const Asset_Image_Base::ptr_t new_asset)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Cast Asset
    Asset_Image_Local::ptr_t asset_local = std::dynamic_pointer_cast<Asset_Image_Local>(new_asset);

    // Grab the pixel data
    cv::Mat image = asset_local->Get_Image();

    // Compute Image Midpoint
    int midX = image.cols/2;
    int midY = image.rows/2;

    m_transform.translate( midX, midY);

    // Load the pixel data
    QImage qt_image( image.data,
                     image.cols, image.rows,
                     static_cast<int>(image.step),
                     QImage::Format_RGB888 );

    m_view->translate(midX, midY);

    // Push to scene
    QGraphicsPixmapItem* new_pixmap = new QGraphicsPixmapItem(QPixmap::fromImage(qt_image));
    m_scene.addItem(new_pixmap);



    // Log Exit
    LOG_CLASS_EXIT();
}


/*************************************************/
/*          Update the Configuration Object      */
/*************************************************/
void GeoViewerLocal::Update_Configuration()
{

}


/*******************************************/
/*          Initialize the Scene           */
/*******************************************/
void GeoViewerLocal::Initialize_Scene()
{
    //m_scene.setSceneRect(QRectF(QPoint(-1, 1), QSizeF(2, 2)));
    m_scene.addText("No Dataset Loaded.");
}
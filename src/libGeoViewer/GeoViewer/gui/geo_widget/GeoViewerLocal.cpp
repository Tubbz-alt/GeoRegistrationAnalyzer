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
#include "../../core/assets/Asset_Manager.hpp"
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
void GeoViewerLocal::Import_Asset( int asset_id )
{
    // Log Entry
    LOG_CLASS_ENTRY();

    Asset_Base::ptr_t new_asset = Asset_Manager::Query_Asset(asset_id);

    // Cast Asset
    Asset_Image_Local::ptr_t asset_local = std::dynamic_pointer_cast<Asset_Image_Local>(new_asset);

    // Grab the pixel data
    cv::Mat image = asset_local->Get_Image();

    // Compute Image Midpoint
    int midX = image.cols/2;
    int midY = image.rows/2;

    m_image_transform.translate( -midX, -midY);

    // Load the pixel data
    QImage qt_image( image.data,
                     image.cols, image.rows,
                     static_cast<int>(image.step),
                     QImage::Format_RGB888 );


    // Push to scene
    QGraphicsPixmapItem* new_pixmap = new QGraphicsPixmapItem(QPixmap::fromImage(qt_image));
    new_pixmap->setTransform(m_image_transform);
    m_scene.addItem(new_pixmap);

    // If everything is okay, then remove the text
    m_scene.removeItem(m_warning_text);

    // Print the Location of the viewport
    std::stringstream sin;
    sin << "Viewport BBox: " << m_view->sceneRect().x() << ", " << m_view->sceneRect().y();
    sin << " : Size: " << m_view->sceneRect().size().width() << " x " << m_view->sceneRect().size().height() << std::endl;
    sin << "Scene BBox: " << m_scene.sceneRect().x() << ", " << m_scene.sceneRect().y();
    sin << " : Size: " << m_scene.sceneRect().size().width() << " x " << m_scene.sceneRect().size().height() << std::endl;
    LOG_CLASS_INFO(sin.str());

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
    m_warning_text = m_scene.addText("No Dataset Loaded.");
}
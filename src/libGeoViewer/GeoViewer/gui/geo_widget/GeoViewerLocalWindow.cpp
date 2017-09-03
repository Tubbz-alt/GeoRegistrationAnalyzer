/**
 * @file    GeoViewerLocalWindow.cpp
 * @author  Marvin Smith
 * @date    9/2/2017
 */
#include "GeoViewerLocalWindow.hpp"

// Project Libraries
#include "../../log.hpp"


/********************************/
/*          Constructor         */
/********************************/
GeoViewerLocalWindow::GeoViewerLocalWindow( const std::string&          base_config_profile,
                                            System_Configuration::ptr_t sys_config,
                                            QWidget*                    parent)
  : QFrame(parent),
    m_class_name("GeoViewerLocalWindow"),
    m_sys_config(sys_config),
    m_base_config_profile(base_config_profile)
{

    // Initialize the Frame
    Initialize_Frame();

}


/********************************************/
/*          Overridden Paint Event          */
/********************************************/
void GeoViewerLocalWindow::paintEvent(QPaintEvent *event)
{
    // Log Entry
    LOG_CLASS_ENTRY();

    // Create a painter
    QPainter painter(this);

    // Set the background color
    painter.setBackground(QBrush(QColor::fromRgb(0,255,0)));

    painter.drawText(rect(), Qt::AlignCenter, "No Layers Imported");

    // Log Exit
    LOG_CLASS_EXIT();
}


/****************************************************/
/*          Initialize QFrame Components            */
/****************************************************/
void GeoViewerLocalWindow::Initialize_Frame()
{
    setAutoFillBackground(true);
    setFocusPolicy( Qt::StrongFocus );
}
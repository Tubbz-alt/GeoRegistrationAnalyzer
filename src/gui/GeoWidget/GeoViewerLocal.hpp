/**
 * @file    GeoViewerLocal.hpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#ifndef GEOVIEWER_GEOVIEWER_LOCAL_HPP
#define GEOVIEWER_GEOVIEWER_LOCAL_HPP


// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "GeoViewerBase.hpp"


/**
 * @class GeoViewerLocal
 */
class GeoViewerLocal : public GeoViewerBase
{

public:

    /**
     * @brief Constructor for Local API viewer class
     *
     * @param sys_config
     * @param parent
     */
    GeoViewerLocal( System_Configuration::ptr_t sys_config,
                    QWidget*                    parent = nullptr );



private:

    /// Class Name
    std::string m_class_name;

};

#endif
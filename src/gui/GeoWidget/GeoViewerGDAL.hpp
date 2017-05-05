/**
 * @file    GeoViewerGDAL.hpp
 * @author  Marvin Smith
 * @date    5/5/2017
 */
#ifndef GEOVIEWER_GEOVIEWER_GDAL_HPP
#define GEOVIEWER_GEOVIEWER_GDAL_HPP


// Qt Libraries
#include <QWidget>

// Project Libraries
#include "../../core/System_Configuration.hpp"
#include "GeoViewerBase.hpp"


/**
 * @class GeoViewerGDAL
 */
class GeoViewerGDAL : public GeoViewerBase
{

public:

    /**
     * @brief Constructor for GDAL API viewer class
     *
     * @param sys_config
     * @param parent
     */
    GeoViewerGDAL( System_Configuration::ptr_t sys_config,
                     QWidget*                    parent = nullptr );



private:

    /// Class Name
    std::string m_class_name;

};

#endif
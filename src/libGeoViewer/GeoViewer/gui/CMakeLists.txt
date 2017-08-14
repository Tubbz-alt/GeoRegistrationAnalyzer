#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    6/3/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_GUI_SOURCES
        asset_info/Asset_Info_Widget_Base.cpp
        asset_info/Asset_Info_Widget_ESRI.cpp
        asset_info/Asset_Info_Widget_Factory.cpp
        geo_widget/GeoViewerBase.cpp
        geo_widget/GeoViewerEsri.cpp
        geo_widget/GeoViewerFactory.cpp
        geo_widget/GeoViewerGoogle.cpp
        geo_widget/GeoViewerLocal.cpp
        geo_widget/GeoWidget.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_GUI_HEADERS
        asset_info/Asset_Info_Widget_Base.hpp
        asset_info/Asset_Info_Widget_ESRI.hpp
        asset_info/Asset_Info_Widget_Factory.hpp
        geo_widget/GeoViewerBase.hpp
        geo_widget/GeoViewerEsri.hpp
        geo_widget/GeoViewerFactory.hpp
        geo_widget/GeoViewerGoogle.hpp
        geo_widget/GeoViewerLocal.hpp
        geo_widget/GeoWidget.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_GUI_OBJ OBJECT
        ${LIB_GEO_GUI_SOURCES}
        ${LIB_GEO_GUI_HEADERS} )


#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_VIEWER_SOURCES
        ${LIB_GEO_VIEWER_SOURCES}
        GeoViewer/gui/asset_info/Asset_Info_Widget_Base.cpp
        GeoViewer/gui/asset_info/Asset_Info_Widget_ESRI.cpp
        GeoViewer/gui/asset_info/Asset_Info_Widget_Factory.cpp
        GeoViewer/gui/geo_widget/GeoViewerBase.cpp
        GeoViewer/gui/geo_widget/GeoViewerEsri.cpp
        GeoViewer/gui/geo_widget/GeoViewerGoogle.cpp
        GeoViewer/gui/geo_widget/GeoViewerLocal.cpp
        GeoViewer/gui/geo_widget/GeoViewerLocalWindow.cpp
        GeoViewer/gui/geo_widget/GeoWidget.cpp
        PARENT_SCOPE )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_VIEWER_HEADERS
        ${LIB_GEO_VIEWER_HEADERS}
        GeoViewer.hpp
        GeoViewer/gui/asset_info/Asset_Info_Widget_Base.hpp
        GeoViewer/gui/asset_info/Asset_Info_Widget_ESRI.hpp
        GeoViewer/gui/asset_info/Asset_Info_Widget_Factory.hpp
        GeoViewer/gui/geo_widget/GeoViewerBase.hpp
        GeoViewer/gui/geo_widget/GeoViewerEsri.hpp
        GeoViewer/gui/geo_widget/GeoViewerGoogle.hpp
        GeoViewer/gui/geo_widget/GeoViewerLocal.hpp
        GeoViewer/gui/geo_widget/GeoViewerLocalWindow.hpp
        GeoViewer/gui/geo_widget/GeoWidget.hpp
        PARENT_SCOPE )

#  Add Each Sub-Project
add_subdirectory(assets)
add_subdirectory(comm)
add_subdirectory(core)
add_subdirectory(io)
add_subdirectory(gui)
add_subdirectory(log)
add_subdirectory(utility)

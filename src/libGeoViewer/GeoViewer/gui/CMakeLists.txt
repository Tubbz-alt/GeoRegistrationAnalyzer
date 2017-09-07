#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    6/3/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_GUI_SOURCES
        geo_widget/GeoViewerFactory.cpp
        geo_widget/local/RenderWorker.cpp
        geo_widget/local/Scene_Context.cpp
)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_GUI_HEADERS
        geo_widget/GeoViewerFactory.hpp
        geo_widget/local/RenderWorker.hpp
        geo_widget/local/Scene_Context.hpp
)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_GUI_OBJ OBJECT
        ${LIB_GEO_GUI_SOURCES}
        ${LIB_GEO_GUI_HEADERS} )



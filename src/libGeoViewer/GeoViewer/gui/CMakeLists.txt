#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    6/3/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_GUI_SOURCES
        geo_widget/GeoViewerFactory.cpp
)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_GUI_HEADERS
        geo_widget/GeoViewerFactory.hpp
)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_GUI_OBJ OBJECT
        ${LIB_GEO_GUI_SOURCES}
        ${LIB_GEO_GUI_HEADERS} )



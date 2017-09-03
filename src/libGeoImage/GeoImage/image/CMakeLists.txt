#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/2/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_IMAGE_IMAGE_SOURCES
        GeoImage.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_IMAGE_IMAGE_HEADERS
        GeoImage.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_IMAGE_IMAGE_OBJ OBJECT
        ${LIB_GEO_IMAGE_IMAGE_SOURCES}
        ${LIB_GEO_IMAGE_IMAGE_HEADERS} )


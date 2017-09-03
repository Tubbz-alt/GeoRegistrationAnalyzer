#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/3/2017
#



#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_IMAGE_COORD_SOURCES
        CoordinateBase.cpp
        CoordinateGeographic.cpp
        CoordinateProjectedBase.cpp
        CoordinateUTM.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_IMAGE_COORD_HEADERS
        CoordinateBase.hpp
        CoordinateGeographic.hpp
        CoordinateProjectedBase.hpp
        CoordinateUTM.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_IMAGE_COORD_OBJ OBJECT
        ${LIB_GEO_IMAGE_COORD_SOURCES}
        ${LIB_GEO_IMAGE_COORD_HEADERS} )
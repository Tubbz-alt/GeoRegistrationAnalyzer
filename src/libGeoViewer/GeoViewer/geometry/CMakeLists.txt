#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/3/2017
#



#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_GEOM_SOURCES
        SceneViewBase.cpp
        SceneViewUTM.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_GEOM_HEADERS
        SceneViewBase.hpp
        SceneViewUTM.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_GEOM_OBJ OBJECT
        ${LIB_GEO_GEOM_SOURCES}
        ${LIB_GEO_GEOM_HEADERS} )
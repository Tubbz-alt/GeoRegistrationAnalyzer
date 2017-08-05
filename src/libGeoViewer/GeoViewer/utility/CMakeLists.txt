#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/30/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_UTIL_SOURCES
        String_Utilities.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_UTIL_HEADERS
        String_Utilities.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_UTIL_OBJ OBJECT
        ${LIB_GEO_UTIL_SOURCES}
        ${LIB_GEO_UTIL_HEADERS} )

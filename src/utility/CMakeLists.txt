#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/30/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_UTIL_SOURCES
        Init_Utilities.cpp
        String_Utilities.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_UTIL_HEADERS
        Init_Utilities.hpp
        String_Utilities.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( GEO_UTIL_OBJ OBJECT
        ${GEO_UTIL_SOURCES}
        ${GEO_UTIL_HEADERS} )

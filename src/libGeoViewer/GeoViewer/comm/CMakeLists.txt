#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    6/3/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_COMM_SOURCES
        MessageService.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_COMM_HEADERS
        MessageService.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_COMM_OBJ OBJECT
        ${LIB_GEO_COMM_SOURCES}
        ${LIB_GEO_COMM_HEADERS} )


#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    6/3/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_COMM_SOURCES
        MessageService.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_COMM_HEADERS
        MessageService.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( GEO_COMM_OBJ OBJECT
        ${GEO_COMM_SOURCES}
        ${GEO_COMM_HEADERS} )

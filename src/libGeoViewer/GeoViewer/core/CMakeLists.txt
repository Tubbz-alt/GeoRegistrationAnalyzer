#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_CORE_SOURCES
        Enumerations.cpp
        GeoViewer_Initialization.cpp
        System_Configuration.cpp
        System_Manager.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_CORE_HEADERS
        ../core.hpp
        Enumerations.hpp
        GeoViewer_Initialization.hpp
        System_Configuration.hpp
        System_Manager.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_CORE_OBJ OBJECT
        ${LIB_GEO_CORE_SOURCES}
        ${LIB_GEO_CORE_HEADERS} )


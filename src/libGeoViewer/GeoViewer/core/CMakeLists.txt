#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_CORE_SOURCES
        Config_Param.cpp
        Enumerations.cpp
        GeoViewer_Initialization.cpp
        Signal_Handlers.cpp
        Status.cpp
        StatusReason.cpp
        System_Configuration.cpp
        System_Manager.cpp
        Thread_Pool.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_CORE_HEADERS
        ../core.hpp
        BlockingQueue.hpp
        Config_Param.hpp
        Enumerations.hpp
        GeoViewer_Initialization.hpp
        Signal_Handlers.hpp
        Status.hpp
        StatusReason.hpp
        System_Configuration.hpp
        System_Manager.hpp
        Thread_Pool.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_CORE_OBJ OBJECT
        ${LIB_GEO_CORE_SOURCES}
        ${LIB_GEO_CORE_HEADERS} )


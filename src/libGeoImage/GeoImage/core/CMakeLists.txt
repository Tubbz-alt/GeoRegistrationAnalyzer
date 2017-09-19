#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/17/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_IMAGE_CORE_SOURCES
        Config_Param.cpp
        Signal_Handlers.cpp
        Status.cpp
        StatusReason.cpp
        Thread_Pool.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_IMAGE_CORE_HEADERS
        ../core.hpp
        BlockingQueue.hpp
        Config_Param.hpp
        Signal_Handlers.hpp
        Status.hpp
        StatusReason.hpp
        Thread_Pool.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_IMAGE_CORE_OBJ OBJECT
        ${LIB_GEO_IMAGE_CORE_SOURCES}
        ${LIB_GEO_IMAGE_CORE_HEADERS} )


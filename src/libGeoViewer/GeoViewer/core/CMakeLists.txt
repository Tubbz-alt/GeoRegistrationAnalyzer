#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_CORE_SOURCES
        assets/Asset_Base.cpp
        assets/Asset_Generator_Base.cpp
        assets/Asset_Generator_ESRI.cpp
        assets/Asset_Image_Base.cpp
        assets/Asset_Image_Google.cpp
        assets/Asset_Image_Local.cpp
        assets/Asset_Loader.cpp
        assets/Asset_Manager.cpp
        assets/Image_Asset_Builder.cpp
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
        assets.hpp
        assets/Asset_Base.hpp
        assets/Asset_Generator_Base.hpp
        assets/Asset_Generator_ESRI.hpp
        assets/Asset_Image_Base.hpp
        assets/Asset_Image_Google.hpp
        assets/Asset_Image_Local.hpp
        assets/Asset_Loader.hpp
        assets/Asset_Manager.hpp
        assets/Image_Asset_Builder.hpp
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


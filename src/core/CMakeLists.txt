#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/25/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_CORE_SOURCES
        Config_Param.cpp
        Enumerations.cpp
        System_Config_Utils.cpp
        System_Configuration.cpp
        System_Manager.cpp
        Thread_Pool.cpp
        assets/Asset_Manager.cpp
        assets/Asset_Base.cpp
        assets/Asset_Image_Base.cpp
        assets/Asset_Image_Local.cpp
        assets/Asset_Image_Google.cpp
        assets/Image_Asset_Builder.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_CORE_HEADERS
        BlockingQueue.hpp
        Config_Param.hpp
        Enumerations.hpp
        System_Config_Utils.hpp
        System_Configuration.hpp
        System_Manager.hpp
        Thread_Pool.hpp
        assets/Asset_Manager.hpp
        assets/Asset_Base.hpp
        assets/Asset_Image_Base.hpp
        assets/Asset_Image_Local.hpp
        assets/Asset_Image_Google.hpp
        assets/Image_Asset_Builder.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( GEO_CORE_OBJ OBJECT
                ${GEO_CORE_SOURCES}
                ${GEO_CORE_HEADERS} )

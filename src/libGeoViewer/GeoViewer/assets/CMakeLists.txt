#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/1/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_ASSETS_SOURCES
        Asset_Base.cpp
        Asset_Generator_Base.cpp
        Asset_Generator_ESRI.cpp
        Asset_Image_Base.cpp
        Asset_Image_ESRI.cpp
        Asset_Image_Google.cpp
        Asset_Image_Local.cpp
        Asset_Loader.cpp
        Asset_Manager.cpp
        Image_Asset_Builder.cpp
    )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_ASSETS_HEADERS
        ../assets.hpp
        Asset_Base.hpp
        Asset_Generator_Base.hpp
        Asset_Generator_ESRI.hpp
        Asset_Image_Base.hpp
        Asset_Image_ESRI.hpp
        Asset_Image_Google.hpp
        Asset_Image_Local.hpp
        Asset_Loader.hpp
        Asset_Manager.hpp
        Image_Asset_Builder.hpp
    )

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_ASSETS_OBJ OBJECT
        ${LIB_GEO_ASSETS_SOURCES}
        ${LIB_GEO_ASSETS_HEADERS} )


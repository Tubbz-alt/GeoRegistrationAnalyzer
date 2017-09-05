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
        Asset_Image_Base.cpp
        Asset_Loader.cpp
        Asset_Manager.cpp
        Image_Asset_Builder.cpp
        esri/Asset_Generator_ESRI.cpp
        esri/Asset_Image_ESRI.cpp
        googlemaps/Asset_Image_Google.cpp
        local/Asset_Generator_Local.cpp
        local/Asset_Local_Base.cpp
        local/Asset_Local_Image.cpp
    )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_ASSETS_HEADERS
        ../assets.hpp
        Asset_Base.hpp
        Asset_Generator_Base.hpp
        Asset_Image_Base.hpp
        Asset_Loader.hpp
        Asset_Manager.hpp
        Image_Asset_Builder.hpp
        esri/Asset_Image_ESRI.hpp
        esri/Asset_Generator_ESRI.hpp
        googlemaps/Asset_Image_Google.hpp
        local/Asset_Generator_Local.hpp
        local/Asset_Local_Base.cpp
        local/Asset_Local_Image.hpp
    )

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_ASSETS_OBJ OBJECT
        ${LIB_GEO_ASSETS_SOURCES}
        ${LIB_GEO_ASSETS_HEADERS} )


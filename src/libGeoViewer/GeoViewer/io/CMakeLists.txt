#    File:   CMakeLists.txt
#    Author: Marvin Smith
#    Date:   6/2/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_IO_SOURCES
        GDAL_Image_Loader.cpp
        GDAL_Utilities.cpp
        OpenCV_Utilities.cpp)

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_IO_HEADERS
        GDAL_Image_Loader.hpp
        GDAL_Utilities.hpp
        OpenCV_Utilities.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( LIB_GEO_IO_OBJ OBJECT
        ${LIB_GEO_IO_SOURCES}
        ${LIB_GEO_IO_HEADERS} )

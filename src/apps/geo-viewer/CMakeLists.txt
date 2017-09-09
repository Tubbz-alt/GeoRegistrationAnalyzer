#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#
#    Purpose:  Construct the Geo-Viewer Application
#

#---------------------------------#
#-      Define the Project       -#
#---------------------------------#
project(geo-viewer)

#---------------------------------#
#-     Change the Output Path    -#
#---------------------------------#
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../bin )
SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../../lib )


#-----------------------------------------#
#-       Add Required Dependencies       -#
#-----------------------------------------#
set( GeoViewer_LIBRARY ${LIBRARY_OUTPUT_PATH})
message("libGeoViewer: ${GeoViewer_LIBRARY}")


#----------------------------#
#-      Configure GDAL      -#
#----------------------------#
find_package( GDAL REQUIRED )
include_directories(${GDAL_INCLUDE_DIR})
message("-- ${Blue}GDAL Includes:${Green}${GDAL_INCLUDE_DIR}${ColorReset}")


#---------------------------#
#-      Configure Qt5      -#
#---------------------------#
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


# Find the QtWidgets library
find_package(Qt5WebEngine REQUIRED)
find_package(Qt5WebEngineWidgets REQUIRED)
find_package(Qt5WebSockets REQUIRED )
find_package(Qt5Widgets REQUIRED)


# Add the include path
#  Note:  the find does this during the add_library, but causes issues when I try building
#         objects.
include_directories(${Qt5WebEngine_INCLUDE_DIRS})
include_directories(${Qt5WebEngineWidgets_INCLUDE_DIRS})
include_directories(${Qt5WebSockets_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})

#----------------------------------#
#-      Configure ArcGIS SDK      -#
#----------------------------------#
#find_package( ArcGIS_SDK REQUIRED )

#if( ARCGIS_SDK_FOUND )
#    message("ArcGIS SDK Found")
#    message("  - Includes: ${ARCGIS_SDK_INCLUDES}")
#    message("  - Libraries: ${ARCGIS_SDK_LIBRARIES}")
#else()
#    message( FATAL_ERROR "Could Not Find ArcGIS SDK")
#endif()
#include_directories(${ARCGIS_SDK_INCLUDES})


#------------------------------------------#
#-         Define the Main Driver         -#
#------------------------------------------#
set( GEO_VIEWER_MAIN 
     geo-viewer.cpp 
)

#  Include libGeoViewer
include_directories( ../../libGeoImage
                     ../../libGeoViewer)


#  Add sub-projects
add_subdirectory(core)
add_subdirectory(gui)
add_subdirectory(utility)


#-------------------------------------------#
#-      Construct and Link Geo-Viewer      -#
#-------------------------------------------#
add_executable( geo-viewer
                ${GEO_VIEWER_MAIN}
                ${GEO_VIEWER_SOURCES}
                ${GEO_VIEWER_HEADERS}
)

#   Link the libraries
target_link_libraries( geo-viewer
                       GeoViewer
                       GeoImage
                       Qt5::WebEngine
                       Qt5::WebEngineWidgets
                       Qt5::WebSockets
                       Qt5::Widgets
)


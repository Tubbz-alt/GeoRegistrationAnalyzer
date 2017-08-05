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


#------------------------------------------#
#-         Define the Main Driver         -#
#------------------------------------------#
set( GEO_VIEWER_MAIN 
     geo-viewer.cpp 
)

#  Include libGeoViewer
include_directories(../../libGeoViewer)


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
                       Qt5::WebEngine
                       Qt5::WebEngineWidgets
                       Qt5::WebSockets
                       Qt5::Widgets
)


#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/17/2017
#
#    Purpose:  Application-Level CMake Build Script.
#


#  Set Required CMake Version
cmake_minimum_required( VERSION 3.0 )

#  Name Project
project(geo-registration-analyzer)


#  Use C++11
set (CMAKE_CXX_STANDARD 14)


#-----------------------------#
#-      Configure Boost      -#
#-----------------------------#
find_package( Boost
                COMPONENTS
                    filesystem
              REQUIRED )
include_directories(${Boost_INCLUDE_DIRS})


#----------------------------#
#-      Configure GDAL      -#
#----------------------------#
find_package( GDAL REQUIRED )
include_directories(${GDAL_INCLUDE_DIR})


#------------------------------#
#-      Configure OpenCV      -#
#------------------------------#
find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

#---------------------------#
#-      Configure Qt5      -#
#---------------------------#

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)
find_package(Qt5WebEngine REQUIRED)
find_package(Qt5WebEngineWidgets REQUIRED)
find_package(Qt5WebSockets REQUIRED )

list( APPEND GEO_REGISTRATION_LIBRARIES
        Qt5::WebEngine
        Qt5::WebEngineWidgets
        Qt5::WebSockets
        Qt5::Widgets)


#  Add Each Sub-Project
add_subdirectory(core)
add_subdirectory(io)
add_subdirectory(log)
add_subdirectory(utility)

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( GEO_REGISTRATION_SOURCES
        geo-registration-analyzer.cpp
        comm/MessageService.cpp
        gui/ConfigurationSaveDialog.cpp
        gui/LogViewerPanel.cpp
        gui/Main_Window.cpp
        gui/PreferenceDialog.cpp
        gui/ProjectBasePanel.cpp
        gui/ProjectViewerPanelBase.cpp
        gui/ProjectViewerPanelFactory.cpp
        gui/analysis/AnalysisBasePanel.cpp
        gui/matching/MatchingBasePanel.cpp
        gui/matching/NewProjectPanelMatching.cpp
        gui/matching/ProjectViewerPanelMatching.cpp
        gui/matching/ReferenceImageryPanel.cpp
        gui/matching/ReferenceToolbar.cpp
        gui/matching/TestImageryPanel.cpp
        gui/matching/TestToolbar.cpp
        gui/matching/Toolbar/MatchingToolbarWidget.cpp
        gui/matching/Toolbar/PrimaryMatchingToolbarPane.cpp
        gui/matching/Toolbar/ProjectMatchingToolbarPane.cpp
        gui/matching/Worker/Matching_Worker.cpp
        gui/matching/Worker/MatchingImportProjectJob.cpp
        gui/geo_widget/GeoViewerBase.cpp
        gui/geo_widget/GeoViewerFactory.cpp
        gui/geo_widget/GeoViewerLocal.cpp
        gui/geo_widget/GeoViewerGoogle.cpp
        gui/geo_widget/GeoWidget.cpp
        gui/project_dialogs/ImportProjectDialog.cpp
        gui/project_dialogs/NewProjectDialog.cpp
        gui/project_dialogs/NewProjectPanelBase.cpp
        gui/project_dialogs/NewProjectPanelFactory.cpp
 )


set( GEO_REGISTRATION_HEADERS
        comm/MessageService.hpp
        gui/ConfigurationSaveDialog.hpp
        gui/LogViewerPanel.hpp
        gui/Main_Window.hpp
        gui/PreferenceDialog.hpp
        gui/ProjectBasePanel.hpp
        gui/ProjectViewerPanelBase.hpp
        gui/ProjectViewerPanelFactory.hpp
        gui/analysis/AnalysisBasePanel.hpp
        gui/matching/MatchingBasePanel.hpp
        gui/matching/NewProjectPanelMatching.hpp
        gui/matching/ProjectViewerPanelMatching.hpp
        gui/matching/ReferenceImageryPanel.hpp
        gui/matching/ReferenceToolbar.hpp
        gui/matching/TestImageryPanel.hpp
        gui/matching/TestToolbar.hpp
        gui/matching/Toolbar/MatchingToolbarWidget.hpp
        gui/matching/Toolbar/PrimaryMatchingToolbarPane.hpp
        gui/matching/Toolbar/ProjectMatchingToolbarPane.hpp
        gui/matching/Worker/Matching_Worker.hpp
        gui/matching/Worker/MatchingImportProjectJob.hpp
        gui/geo_widget/GeoViewerBase.hpp
        gui/geo_widget/GeoViewerFactory.hpp
        gui/geo_widget/GeoViewerLocal.hpp
        gui/geo_widget/GeoViewerGoogle.hpp
        gui/geo_widget/GeoWidget.hpp
        gui/project_dialogs/NewProjectDialog.hpp
        gui/project_dialogs/ImportProjectDialog.hpp
        gui/project_dialogs/NewProjectPanelBase.hpp
        gui/project_dialogs/NewProjectPanelFactory.hpp
)

#------------------------------#
#-      Build Executable      -#
#------------------------------#
add_executable( geo-registration-analyzer
                ${GEO_REGISTRATION_SOURCES}
                ${GEO_REGISTRATION_HEADERS}
                $<TARGET_OBJECTS:GEO_CORE_OBJ>
                $<TARGET_OBJECTS:GEO_IO_OBJ>
                $<TARGET_OBJECTS:GEO_LOG_OBJ>
                $<TARGET_OBJECTS:GEO_UTIL_OBJ>)

target_link_libraries( geo-registration-analyzer
                       ${GEO_REGISTRATION_LIBRARIES}
                       pthread
                       ${GDAL_LIBRARY}
                       ${Boost_LIBRARIES}
                       ${OpenCV_LIBS} )


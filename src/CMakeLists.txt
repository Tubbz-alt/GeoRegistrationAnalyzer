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

#-------------------------------#
#-      Define our Sources     -#
#-------------------------------#
set( GEO_REGISTRATION_SOURCES
        geo-registration-analyzer.cpp
        core/Config_Param.cpp
        core/Enumerations.cpp
        core/MessageService.cpp
        core/System_Config_Utils.cpp
        core/System_Configuration.cpp
        core/System_Manager.cpp
        gui/ConfigurationSaveDialog.cpp
        gui/ImportProjectDialog.cpp
        gui/Main_Window.cpp
        gui/PreferenceDialog.cpp
        gui/ProjectViewerPanelBase.cpp
        gui/ProjectViewerPanelFactory.cpp
        gui/Analysis/AnalysisBasePanel.cpp
        gui/Matching/MatchingBasePanel.cpp
        gui/Matching/ProjectViewerPanelMatching.cpp
        gui/Matching/ReferenceImageryPanel.cpp
        gui/Matching/ReferenceToolbar.cpp
        gui/Matching/TestImageryPanel.cpp
        gui/Matching/TestToolbar.cpp
        gui/Matching/Toolbar/MatchingToolbarWidget.cpp
        gui/Matching/Toolbar/PrimaryMatchingToolbarPane.cpp
        gui/Matching/Toolbar/ProjectMatchingToolbarPane.cpp
        gui/GeoWidget/GeoViewerBase.cpp
        gui/GeoWidget/GeoViewerFactory.cpp
        gui/GeoWidget/GeoViewerLocal.cpp
        gui/GeoWidget/GeoViewerGoogle.cpp
        gui/GeoWidget/GeoWidget.cpp
        utility/String_Utilities.cpp
 )


set( GEO_REGISTRATION_HEADERS
        core/BlockingQueue.hpp
        core/Config_Param.hpp
        core/Enumerations.hpp
        core/MessageService.hpp
        core/System_Config_Utils.hpp
        core/System_Configuration.hpp
        core/System_Manager.hpp
        gui/ConfigurationSaveDialog.hpp
        gui/ImportProjectDialog.hpp
        gui/Main_Window.hpp
        gui/PreferenceDialog.hpp
        gui/ProjectViewerPanelBase.hpp
        gui/ProjectViewerPanelFactory.hpp
        gui/Analysis/AnalysisBasePanel.hpp
        gui/Matching/MatchingBasePanel.hpp
        gui/Matching/ProjectViewerPanelMatching.hpp
        gui/Matching/ReferenceImageryPanel.hpp
        gui/Matching/ReferenceToolbar.hpp
        gui/Matching/TestImageryPanel.hpp
        gui/Matching/TestToolbar.hpp
        gui/Matching/Toolbar/MatchingToolbarWidget.hpp
        gui/Matching/Toolbar/PrimaryMatchingToolbarPane.hpp
        gui/Matching/Toolbar/ProjectMatchingToolbarPane.hpp
        gui/GeoWidget/GeoViewerBase.hpp
        gui/GeoWidget/GeoViewerFactory.hpp
        gui/GeoWidget/GeoViewerLocal.hpp
        gui/GeoWidget/GeoViewerGoogle.hpp
        gui/GeoWidget/GeoWidget.hpp
        utility/String_Utilities.hpp
)

#------------------------------#
#-      Build Executable      -#
#------------------------------#
add_executable( geo-registration-analyzer
                ${GEO_REGISTRATION_SOURCES}
                ${GEO_REGISTRATION_HEADERS} )

target_link_libraries( geo-registration-analyzer
                       ${GEO_REGISTRATION_LIBRARIES}
                       pthread
                       ${Boost_LIBRARIES} )

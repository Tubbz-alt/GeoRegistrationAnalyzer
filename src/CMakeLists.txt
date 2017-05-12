#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/17/2017
#
#    Purpose:  Application-Level CMake Build Script.
#

#  Name Project
project(geo-registration-analyzer)


#  Use C++11
set (CMAKE_CXX_STANDARD 11)


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
        core/Enumerations.cpp
        core/MessageService.cpp
        core/System_Configuration.cpp
        core/System_Manager.cpp
        gui/Main_Window.cpp
        gui/AnalysisBasePanel.cpp
        gui/MatchingBasePanel.cpp
        gui/ReferenceImageryPanel.cpp
        gui/TestImageryPanel.cpp
        gui/GeoWidget/GeoViewerBase.cpp
        gui/GeoWidget/GeoViewerGDAL.cpp
        gui/GeoWidget/GeoViewerGoogle.cpp
        gui/Toolbar/ToolbarWidget.cpp
 )


set( GEO_REGISTRATION_HEADERS
        core/BlockingQueue.hpp
        core/Enumerations.hpp
        core/MessageService.hpp
        core/System_Configuration.hpp
        core/System_Manager.hpp
        gui/Main_Window.hpp
        gui/AnalysisBasePanel.hpp
        gui/MatchingBasePanel.hpp
        gui/ReferenceImageryPanel.hpp
        gui/TestImageryPanel.hpp
        gui/GeoWidget/GeoViewerBase.hpp
        gui/GeoWidget/GeoViewerGDAL.hpp
        gui/GeoWidget/GeoViewerGoogle.hpp
        gui/Toolbar/ToolbarWidget.hpp
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

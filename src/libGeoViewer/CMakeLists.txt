#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/17/2017
#
#    Purpose:  Application-Level CMake Build Script.
#


#  Set Required CMake Version
cmake_minimum_required( VERSION 3.0 )

#  Name Project
project(lib-geo-viewer)


#  Use C++11
set (CMAKE_CXX_STANDARD 14)

#---------------------------------#
#-     Change the Output Path    -#
#---------------------------------#
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../bin )
SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../lib )


#  Create Optional Library List
set( EXTRA_LIBRARIES "" )


#-----------------------------------#
#-     Add OS-Specific Features    -#
#-----------------------------------#
if(UNIX)
	set( EXTRA_LIBRARIES
			${EXTRA_LIBRARIES}
			"pthread")

	#  Set FPIC
	set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC" )
endif()


#-----------------------------#
#-      Configure Boost      -#
#-----------------------------#
find_package( Boost
                COMPONENTS
                    filesystem
              REQUIRED )
include_directories(${Boost_INCLUDE_DIRS})

if(Boost_FOUND)
    message("${Green}Boost Found${ColorReset}")
    message("   ${Blue}Include Paths: ${Boost_INCLUDE_DIRS}${ColorReset}")
    message("   ${Blue}Library Paths: ${Boost_LIBRARIES}${ColorReset}")
endif()


#----------------------------#
#-      Configure GDAL      -#
#----------------------------#
find_package( GDAL REQUIRED )
include_directories(${GDAL_INCLUDE_DIR})
message("-- ${Blue}GDAL Includes:${Green}${GDAL_INCLUDE_DIR}${ColorReset}")

#------------------------------#
#-      Configure OpenCV      -#
#------------------------------#
find_package( OpenCV REQUIRED core highgui imgcodecs imgproc )
include_directories(${OpenCV_INCLUDE_DIRS})


#----------------------------------#
#-      Configure ArcGIS SDK      -#
#----------------------------------#
if( USE_ArcGIS_SDK )
    find_package( ArcGIS_SDK REQUIRED )

    if( ARCGIS_SDK_FOUND )
        message("ArcGIS SDK Found")
        message("  - Includes: ${ARCGIS_SDK_INCLUDES}")
	    message("  - Libraries: ${ARCGIS_SDK_LIBRARIES}")
	else()
	    message( FATAL_ERROR "Could Not Find ArcGIS SDK")
	endif()
	include_directories(${ARCGIS_SDK_INCLUDES})

	set( EXTRA_LIBRARIES 
	          ${EXTRA_LIBRARIES}
			  "${ARCGIS_SDK_LIBRARIES}")
endif()

#---------------------------#
#-      Configure Qt5      -#
#---------------------------#
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)


# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)


# Find the QtWidgets library
find_package(Qt5Core        REQUIRED)
find_package(Qt5WebEngine REQUIRED)
find_package(Qt5WebEngineWidgets REQUIRED)
find_package(Qt5WebSockets REQUIRED )
find_package(Qt5Widgets REQUIRED)


# Add the include path
#  Note:  the find does this during the add_library, but causes issues when I try building
#         objects.
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5WebEngine_INCLUDE_DIRS})
include_directories(${Qt5WebEngineWidgets_INCLUDE_DIRS})
include_directories(${Qt5WebSockets_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})

#  Add GeoImage Includes
include_directories(../libGeoImage)

#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_VIEWER_SOURCES )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_VIEWER_HEADERS )

#  Add Sources
add_subdirectory(GeoViewer)



#------------------------------#
#-       Build Library        -#
#------------------------------#
add_library( GeoViewer SHARED
                $<TARGET_OBJECTS:LIB_GEO_ASSETS_OBJ>
                $<TARGET_OBJECTS:LIB_GEO_COMM_OBJ>
                $<TARGET_OBJECTS:LIB_GEO_CORE_OBJ>
                $<TARGET_OBJECTS:LIB_GEO_GEOM_OBJ>
                $<TARGET_OBJECTS:LIB_GEO_GUI_OBJ>
                $<TARGET_OBJECTS:LIB_GEO_IO_OBJ>
                $<TARGET_OBJECTS:LIB_GEO_LOG_OBJ>
                ${LIB_GEO_VIEWER_SOURCES}
                ${LIB_GEO_VIEWER_HEADERS}
)


target_link_libraries( GeoViewer
                       GeoImage
					   ${EXTRA_LIBRARIES}
                       ${Boost_LIBRARIES}
                       ${GDAL_LIBRARY}
                       ${OpenCV_LIBS}
                       Qt5::Core
                       Qt5::WebEngine
                       Qt5::WebEngineWidgets
                       Qt5::WebSockets
                       Qt5::Widgets
)


#-------------------------------#
#-      Build Unit-Tests      --#
#-------------------------------#
if( NOT SKIP_UNIT_TESTS )	
	include_directories("${PROJECT_SOURCE_DIR}/../../thirdparty/googletest/googletest/include")
	include_directories(.)

	#  Add Unit-Test Code
	add_subdirectory(unit-tests)

	#--------------------------------------#
	#-      Build Unit-Test Executable    -#
	#--------------------------------------#
	add_executable(lib-geo-viewer-unit-tests
		              unit-tests/lib-geo-viewer-unit-tests.cpp
			          $<TARGET_OBJECTS:LIB_GEO_CORE_TEST_OBJ>
					  $<TARGET_OBJECTS:LIB_GEO_IO_TEST_OBJ>
					  $<TARGET_OBJECTS:LIB_GEO_UTEST_OBJ>)

	target_link_libraries(lib-geo-viewer-unit-tests
		                    GeoViewer
			                GeoImage
				            ${CMAKE_BINARY_DIR}/thirdparty/googletest/googlemock/libgmock.a )
endif()
#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/2/2017
#


#  Set Required CMake Version
cmake_minimum_required( VERSION 3.0 )

#  Name Project
project(lib-geo-image)


#  Use C++11
set (CMAKE_CXX_STANDARD 14)

#---------------------------------#
#-     Change the Output Path    -#
#---------------------------------#
SET( EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../bin )
SET( LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../../lib )


#  Set FPIC
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC" )


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
find_package( OpenCV REQUIRED core highgui imgproc )
include_directories(${OpenCV_INCLUDE_DIRS})




#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( LIB_GEO_VIEWER_SOURCES )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( LIB_GEO_VIEWER_HEADERS )


#  Add Sources
add_subdirectory(GeoImage)

message("OUTPUT SOURCES: ${LIB_GEO_IMAGE_SOURCES}")
message("OUTPUT HEADERS: ${LIB_GEO_IMAGE_HEADERS}")

#------------------------------#
#-       Build Library        -#
#------------------------------#
add_library( GeoImage SHARED
        ${LIB_GEO_IMAGE_SOURCES}
        ${LIB_GEO_IMAGE_HEADERS}
        $<TARGET_OBJECTS:LIB_GEO_IMAGE_COORD_OBJ>
        $<TARGET_OBJECTS:LIB_GEO_IMAGE_GEOM_OBJ>
        $<TARGET_OBJECTS:LIB_GEO_IMAGE_COORD_OBJ>
        )


target_link_libraries( GeoImage
        pthread
        ${Boost_LIBRARIES}
        ${GDAL_LIBRARY}
        ${OpenCV_LIBS}
   )


#-------------------------------#
#-      Build Unit-Tests      --#
#-------------------------------#
include_directories("${PROJECT_SOURCE_DIR}/../../thirdparty/googletest/googletest/include")
include_directories(.)

#  Add Unit-Test Code
add_subdirectory(unit-tests)

#--------------------------------------#
#-      Build Unit-Test Executable    -#
#--------------------------------------#
add_executable(lib-geo-image-unit-tests
        unit-tests/lib-geo-image-unit-tests.cpp
        $<TARGET_OBJECTS:LIB_GEO_IMAGE_COORD_TEST_OBJ> )

target_link_libraries(lib-geo-image-unit-tests
        GeoImage
        ${CMAKE_BINARY_DIR}/thirdparty/googletest/googlemock/libgmock.a )

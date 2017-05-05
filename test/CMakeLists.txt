#  File:    CMakeLists.txt
#  Author:  Marvin Smith
#  Date:    5/5/2017
#


#  Add Google Test
include(ExternalProject)
ExternalProject_Add(googletest
        GIT_REPOSITORY    https://github.com/google/googletest.git
        GIT_TAG           master
        SOURCE_DIR        "${CMAKE_BINARY_DIR}/googletest-src"
        BINARY_DIR        "${CMAKE_BINARY_DIR}/googletest-build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND     ""
        INSTALL_COMMAND   ""
        TEST_COMMAND      ""
        )

include_directories("${CMAKE_BINARY_DIR}/googletest-src/googletest/include")
include_directories("../src")


#   Define our Source Files
set( UNIT_TEST_SOURCES
        core/TEST_System_Configuration.cpp)

set( PROJECT_SOURCES
        ${CMAKE_SOURCE_DIR}/src/core/System_Configuration.hpp
        ${CMAKE_SOURCE_DIR}/src/core/System_Configuration.cpp )

add_executable( geo-registration-tests
                    ${UNIT_TEST_SOURCES}
                    ${PROJECT_SOURCES} )

target_link_libraries( geo-registration-tests
                        ${CMAKE_BINARY_DIR}/test/googletest/googlemock/libgmock_main.a)
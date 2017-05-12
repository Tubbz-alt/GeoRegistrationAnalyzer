#  File:    CMakeLists.txt
#  Author:  Marvin Smith
#  Date:    5/5/2017
#



#   Add GoogleTest Binaries
include_directories("${CMAKE_BINARY_DIR}/googletest-src/googletest/include")
include_directories("../src")

#-----------------------------#
#-      Configure Boost      -#
#-----------------------------#
find_package( Boost
        COMPONENTS
        filesystem
        REQUIRED )
include_directories(${Boost_INCLUDE_DIRS})



#   Define our Source Files
set( UNIT_TEST_SOURCES
        core/TEST_Config_Param.cpp
        core/TEST_System_Configuration.cpp)

set( PROJECT_SOURCES
        ${CMAKE_SOURCE_DIR}/src/core/Config_Param.hpp
        ${CMAKE_SOURCE_DIR}/src/core/Config_Param.cpp
        ${CMAKE_SOURCE_DIR}/src/core/System_Config_Utils.hpp
        ${CMAKE_SOURCE_DIR}/src/core/System_Config_Utils.cpp
        ${CMAKE_SOURCE_DIR}/src/core/System_Configuration.hpp
        ${CMAKE_SOURCE_DIR}/src/core/System_Configuration.cpp
        ${CMAKE_SOURCE_DIR}/src/utility/String_Utilities.hpp
        ${CMAKE_SOURCE_DIR}/src/utility/String_Utilities.cpp)

add_executable( geo-registration-tests
                    ${UNIT_TEST_SOURCES}
                    ${PROJECT_SOURCES} )

target_link_libraries( geo-registration-tests
                        ${CMAKE_BINARY_DIR}/googletest-build/googlemock/libgmock_main.a
                        pthread
                        ${Boost_LIBRARIES} )
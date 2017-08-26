#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/17/2017
#
#    Purpose:  Base-Level CMake Build Script.
#

#  Set Required CMake Version
cmake_minimum_required( VERSION 3.0 )

#  Use C++11
set (CMAKE_CXX_STANDARD 14)


#------------------------------#
#-        Name Project        -#
#------------------------------#
project(GeoRegistrationAnalyzer)


#------------------------------#
#-     Setup Color Output     -#
#------------------------------#
if(NOT WIN32)
    string(ASCII 27 Esc)
    set(ColorReset  "${Esc}[m")
    set(ColorBold   "${Esc}[1m")
    set(Red         "${Esc}[31m")
    set(Green       "${Esc}[32m")
    set(Yellow      "${Esc}[33m")
    set(Blue        "${Esc}[34m")
    set(Magenta     "${Esc}[35m")
    set(Cyan        "${Esc}[36m")
    set(White       "${Esc}[37m")
    set(BoldRed     "${Esc}[1;31m")
    set(BoldGreen   "${Esc}[1;32m")
    set(BoldYellow  "${Esc}[1;33m")
    set(BoldBlue    "${Esc}[1;34m")
    set(BoldMagenta "${Esc}[1;35m")
    set(BoldCyan    "${Esc}[1;36m")
    set(BoldWhite   "${Esc}[1;37m")
endif()


#-------------------------------------#
#-     Add Manual CMake Scripts      -#
#-------------------------------------#
LIST( APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")


#-------------------------------------#
#-    Add ThirdParty Dependencies    -#
#-------------------------------------#
add_subdirectory(thirdparty)


#-------------------------------------#
#-      Add Project Dependencies     -#
#-------------------------------------#
add_subdirectory(src)


#-------------------------------------#
#-       Add Test Dependencies       -#
#-------------------------------------#
#add_subdirectory(test)


#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    4/17/2017
#
#    Purpose:  Base-Level CMake Build Script.
#

#  Set Required CMake Version
cmake_minimum_required( VERSION 3.0 )

#  Name Project
project(GeoRegistrationAnalyzer)

#  Add Project Dependencies
add_subdirectory(src)

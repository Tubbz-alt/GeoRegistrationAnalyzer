#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/15/2017
#

#---------------------------------------#
#-     Build the Unit-Test Module      -#
#---------------------------------------#
SET( LIB_GEO_UTEST_SOURCES
        Test_Options.cpp
        Test_Options.hpp
        )



#--------------------------------------#
#-      Create the Target Object      -#
#--------------------------------------#
add_library( LIB_GEO_UTEST_OBJ
        OBJECT
        ${LIB_GEO_UTEST_SOURCES}
        )

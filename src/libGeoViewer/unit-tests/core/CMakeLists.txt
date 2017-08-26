#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/25/2017
#

#----------------------------------#
#-     Build the Core Module      -#
#----------------------------------#
SET( LIB_GEO_CORE_TESTS
    TEST_Config_Param.cpp
)



#--------------------------------------#
#-      Create the Target Object      -#
#--------------------------------------#
add_library( LIB_GEO_CORE_TEST_OBJ
                OBJECT
                ${LIB_GEO_CORE_TESTS}
)

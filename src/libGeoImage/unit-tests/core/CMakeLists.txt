#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/17/2017
#

#----------------------------------------#
#-     Build the Coordinate Module      -#
#----------------------------------------#
SET( LIB_GEO_IMAGE_CORE_TESTS
        TEST_Config_Param.cpp
        )



#--------------------------------------#
#-      Create the Target Object      -#
#--------------------------------------#
add_library( LIB_GEO_IMAGE_CORE_TEST_OBJ
        OBJECT
        ${LIB_GEO_IMAGE_CORE_TESTS}
        )

#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/3/2017
#

#----------------------------------------#
#-     Build the Coordinate Module      -#
#----------------------------------------#
SET( LIB_GEO_IMAGE_COORD_TESTS
        TEST_CoordinateGeographic.cpp
        )



#--------------------------------------#
#-      Create the Target Object      -#
#--------------------------------------#
add_library( LIB_GEO_IMAGE_COORD_TEST_OBJ
        OBJECT
        ${LIB_GEO_IMAGE_COORD_TESTS}
        )

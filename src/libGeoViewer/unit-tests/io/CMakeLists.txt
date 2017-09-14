#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    9/13/2017
#

#----------------------------------#
#-     Build the Core Module      -#
#----------------------------------#
SET( LIB_GEO_IO_TESTS
        TEST_GDAL_Image_Loader.cpp
)



#--------------------------------------#
#-      Create the Target Object      -#
#--------------------------------------#
add_library( LIB_GEO_IO_TEST_OBJ
        OBJECT
        ${LIB_GEO_IO_TESTS}
)

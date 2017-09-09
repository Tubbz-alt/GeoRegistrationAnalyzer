#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/25/2017
#

#-----------------------------------#
#-      Link against GoogleTest    -#
#-----------------------------------#
if( NOT SKIP_UNIT_TESTS )
	add_subdirectory(googletest)
endif()
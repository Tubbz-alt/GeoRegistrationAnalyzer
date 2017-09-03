#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#
#    Purpose:  Construct Geo-Viewer Dependencies
#


#----------------------------------------#
#-      Add the LibGeoImage Library     -#
#----------------------------------------#
add_subdirectory(libGeoImage)

#---------------------------------#
#-      Add the LibGeoViewer     -#
#---------------------------------#
add_subdirectory(libGeoViewer)

#-----------------------------------------#
#-      Add Applications Directories     -#
#-----------------------------------------#
add_subdirectory(apps)


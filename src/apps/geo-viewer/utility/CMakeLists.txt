#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_VIEWER_SOURCES
        ${GEO_VIEWER_SOURCES}
        utility/Init_Utilities.cpp
        PARENT_SCOPE )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_VIEWER_HEADERS
        ${GEO_VIEWER_HEADERS}
        utility/Init_Utilities.hpp
        PARENT_SCOPE )


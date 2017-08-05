#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_VIEWER_SOURCES
        ${GEO_VIEWER_SOURCES}
        gui/Main_Window.cpp
        PARENT_SCOPE )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_VIEWER_HEADERS
        ${GEO_VIEWER_HEADERS}
        gui/Main_Window.hpp
        PARENT_SCOPE )


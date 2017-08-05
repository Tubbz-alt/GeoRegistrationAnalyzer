#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_REGISTRATION_ANALYZER_SOURCES
        ${GEO_REGISTRATION_ANALYZER_SOURCES}
        core/System_Config_Utils.cpp
        PARENT_SCOPE )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_REGISTRATION_ANALYZER_HEADERS
        ${GEO_REGISTRATION_ANALYZER_HEADERS}
        core/System_Config_Utils.hpp
        PARENT_SCOPE )



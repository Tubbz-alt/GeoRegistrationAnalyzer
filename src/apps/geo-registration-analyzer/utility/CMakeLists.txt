#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_REGISTRATION_ANALYZER_SOURCES
        ${GEO_REGISTRATION_ANALYZER_SOURCES}
        utility/Init_Utilities.cpp
        PARENT_SCOPE )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_REGISTRATION_ANALYZER_HEADERS
        ${GEO_REGISTRATION_ANALYZER_HEADERS}
        utility/Init_Utilities.hpp
        PARENT_SCOPE )


#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    5/30/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_LOG_SOURCES
        Log_Handler_Base.cpp
        Log_Handler_Console.cpp
        Log_Handler_Factory.cpp
        Log_Handler_File.cpp
        Log_Handler_Qt.cpp
        Log_Severity.cpp
        System_Logger.cpp )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_LOG_HEADERS
        Log_Handler_Base.hpp
        Log_Handler_Console.hpp
        Log_Handler_Factory.hpp
        Log_Handler_File.hpp
        Log_Handler_Qt.hpp
        Log_Severity.hpp
        System_Logger.hpp)

#------------------------------------#
#-     Build the Target Library     -#
#------------------------------------#
add_library( GEO_LOG_OBJ OBJECT
        ${GEO_LOG_SOURCES}
        ${GEO_LOG_HEADERS} )

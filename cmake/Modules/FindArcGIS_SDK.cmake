#    File:     FindArcGIS_SDK.cmake
#    Author:   Marvin Smith
#    Date:     8/3/2017
#
#    Purpose: Enable discovery of the installed ArcGIS SDK 
#
#   User-Defined Variables (Inputs)
#   ArcGIS_SDK_ROOT  : Defines base path to look for
#
#   Variables Set By Script:
#
#   ARCGIS_SDK_FOUND
#   ARCGIS_SDK_INCLUDES
#   ARCGIS_SDK_LIBRARIES
#


#---------------------------------------------#
#-      Find the ArcGIS Base Directory       -#
#---------------------------------------------#
SET( ARCGIS_BASE_PATH
     ${ArcGIS_SDK_ROOT}
     $ENV{ArcGIS_SDK_ROOT}
)

#----------------------------------------#
#-      Set Package Default Options     -#
#----------------------------------------#
set( USE_RUNTIME_CORE_LIB TRUE )

if(APPLE)
    SET( ARCGIS_LIB_SUFFIXES macOS/x64/lib )
    SET( ARCGIS_BASE_PATH
            ${ARCGIS_BASE_PATH}
            "${ARCGIS_BASE_PATH}/macOS/x64/lib" )

    #  Do not look for Runtime Core Library
    set(USE_RUNTIME_CORE_LIB FALSE)
elseif(WIN32)
    set( ARCGIS_LIB_SUFFIXES win32/x64/lib )
elseif(UNIX)
    set( ARCGIS_LIB_SUFFIXES linux/x64/lib )

    if( NOT ARCGIS_BASE_PATH )
        set( ARCGIS_BASE_PATH
                /opt/software/arcgis/runtime_sdk/qt100.1/sdk )
    endif()
else()

endif()



#---------------------------------#
#-      Configure ArcGIS SDK     -#
#---------------------------------#

#   ArcGIS Runtime QT Library
find_library( ARCGIS_RT_QT_LIB
                EsriRuntimeQt
                PATHS
                 ${ARCGIS_BASE_PATH}
                PATH_SUFFIXES
                    ${ARCGIS_LIB_SUFFIXES}
)
if( ARCGIS_RT_QT_LIB )
    set( ARCGIS_SDK_LIBRARIES
            ${ARCGIS_SDK_LIBRARIES}
            ${ARCGIS_RT_QT_LIB})
endif()


#  ArcGIS Runtime Core Library
if( USE_RUNTIME_CORE_LIB )
    find_library( ARCGIS_RT_CORE_LIB
                    runtimecore
                    PATHS
                     ${ARCGIS_BASE_PATH}
                    PATH_SUFFIXES
                        ${ARCGIS_LIB_SUFFIXES}
    )
    if( ARCGIS_RT_CORE_LIB )
        set( ARCGIS_SDK_LIBRARIES
                ${ARCGIS_SDK_LIBRARIES}
                ${ARCGIS_RT_CORE_LIB})
    endif()

endif()


#  ArcGIS Runtime QT Library
find_library( ARCGIS_RT_QT_COMMON_LIB
                EsriCommonQt
                PATHS
                    ${ARCGIS_BASE_PATH}
                PATH_SUFFIXES
                    ${ARCGIS_LIB_SUFFIXES}
)
if( ARCGIS_RT_QT_COMMON_LIB )
    set( ARCGIS_SDK_LIBRARIES
            ${ARCGIS_SDK_LIBRARIES}
            ${ARCGIS_RT_QT_COMMON_LIB})
endif()



FIND_PATH( ARCGIS_SDK_INCLUDES
                ArcGISRuntimeEnvironment.h
             PATHS
                ${ARCGIS_BASE_PATH}
             PATH_SUFFIXES
                include
)

#  Set the found flag
if( ARCGIS_SDK_LIBRARIES AND ARCGIS_SDK_INCLUDES )
    set( ARCGIS_SDK_FOUND TRUE )
endif()


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
SET( ARCGIS_LIB_SUFFIXES linux/x64/lib )
if(APPLE)
elseif(WIN32)
elseif(LINUX)
else()

endif()



#---------------------------------#
#-      Configure ArcGIS SDK     -#
#---------------------------------#
find_library( ARCGIS_RT_QT_LIB
                EsriRuntimeQt
                PATHS
                 ${ARCGIS_BASE_PATH}
                PATH_SUFFIXES
                    ${ARCGIS_LIB_SUFFIXES}
)
find_library( ARCGIS_RT_CORE_LIB
                runtimecore
                PATHS
                 ${ARCGIS_BASE_PATH}
                PATH_SUFFIXES
                    ${ARCGIS_LIB_SUFFIXES}
)
find_library( ARCGIS_RT_QT_COMMON_LIB
                libEsriCommonQt.so
                PATHS
                    ${ARCGIS_BASE_PATH}
                PATH_SUFFIXES
                    ${ARCGIS_LIB_SUFFIXES}
)


FIND_PATH( ARCGIS_SDK_INCLUDES
                ArcGISRuntimeEnvironment.h
             PATHS
                ${ARCGIS_BASE_PATH}
             PATH_SUFFIXES
                include
)

set(ARCGIS_SDK_LIBRARIES
        ${ARCGIS_RT_QT_LIB}
        ${ARCGIS_RT_CORE_LIB}
        ${ARCGIS_RT_QT_COMMON_LIB}
)

#  Set the found flag
if( ARCGIS_SDK_LIBRARIES AND ARCGIS_SDK_INCLUDES )
    set( ARCGIS_SDK_FOUND TRUE )
endif()


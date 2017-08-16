#!/usr/bin/env bash
#
#    File:    geo-viewer.bash
#    Author:  Marvin Smith
#    Date:    8/4/2017
#
#    Purpose:  Run the Geo-Viewer Utility
#

#  Set Environment Variables
export GEO_VIEWER_BASE=__GEO_VIEWER_BASE_PATH__

#  Pre-Command Arguments
export PRE_CMD=__PRE_CMD_ARGS__

export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${GEO_VIEWER_BASE}/lib
export DYLD_LIBRARY_PATH=${DYLD_LIBRARY_PATH}:${GEO_VIEWER_BASE}/lib

ARGLIST=''

#  Parse Command-Line Arguments
for ARG in "$@"; do
    case $ARG in
    
        #  Check if valgrind
        '--valgrind')
            PRE_CMD="valgrind --show-leak-kinds=all ${PRE_CMD}"
            ;;

        #  Check if GDB
        '--gdb')
            PRE_CMD="gdb --args ${PRE_CMD}"
            ;;

        #  Otherwise, ignore
        *)
            ARGLIST="${ARGLIST} $ARG"
            ;;
    esac
done


#  Run the application
echo "Running Application"
${PRE_CMD} ${GEO_VIEWER_BASE}/bin/geo-viewer $ARGLIST


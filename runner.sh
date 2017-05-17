#!/usr/bin/env bash
#
#    File:    runner.sh
#    Author:  Marvin Smith
#    Date:    5/16/2017
#
#    Purpose:  Complete build and install application
#


#-------------------------------#
#-      Build the Software     -#
#-------------------------------#
Build_Software()
{
    #  Log Entry
    echo '->  Building Software'

    #  Create build dir
    mkdir -p $BUILD_TYPE

    #  Enter directory
    pushd ${BUILD_TYPE}

    #  Run CMake
    cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} ..
    ORES="$?"
    if [ ! "$ORES" == '0' ]; then
        echo "CMake Failed to Build.  Code: $ORES"
        exit 1
    fi


    #  Run Make
    make -j${NUM_THREADS}
    ORES="$?"
    if [ ! "$ORES" == '0' ]; then
        echo "Make failed.  Code: $ORES"
        exit 1
    fi

    #  Exit Directory
    popd

    #  Run the release builder
    ./scripts/release-builder.py --build-dir=${BUILD_TYPE}

    #  Make run script executable
    chmod +x ./releases/geo-registration-analyzer/scripts/geo-registration-analyzer.sh


}


#-------------------------------#
#-     Install the Software    -#
#-------------------------------#
Install_Software()
{
    # Log Entry
    echo '-> Installing Software'

    #  Copy to /opt
    sudo cp -r releases/geo-registration-analyzer /opt/

    sudo ln -snf /opt/geo-registration-analyzer/scripts/geo-registration-analyzer.sh /usr/local/bin/geo-registration-analyzer


}


#--------------------------------#
#-       Main Application       -#
#--------------------------------#

#  Baseline Flags
BUILD_TYPE='release'
RUN_MAKE=0
RUN_INSTALL=0
THREAD_FLAG=0
NUM_THREADS=1


#  Iterate over command-line argument
for ARG in "$@"; do

    case $ARG in

        #  Build Software
        '-m'|'--make')
            RUN_MAKE=1
            ;;

        #  Install Software
        '-i'|'--install')
            RUN_INSTALL=1
            ;;

        #  Do Everything
        '-f'|'--full')
            RUN_MAKE=1
            RUN_INSTALL=1
            ;;

        #  Setup the debug mode
        '-d'|'--debug')
            BUILD_TYPE='debug'
            ;;

        #  Setup the release mode
        '-r'|'--release')
            BUILD_TYPE='release'
            ;;

        #  Set thread flag
        '-j')
            THREAD_FLAG=1
            ;;

        *)
            if [ "$THREAD_FLAG" = '1' ]; then
                THREAD_FLAG=0
                NUM_THREADS=$ARG
            else
                echo "error: Unsupported flag ($ARG)"
            fi
            ;;
    esac
done

#   Run Make
if [ "$RUN_MAKE" = '1' ]; then
    Build_Software
fi

if [ "$RUN_INSTALL" = '1' ]; then
    Install_Software
fi
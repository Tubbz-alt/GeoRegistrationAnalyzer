#!/usr/bin/env bash
#
#    File:    runner.sh
#    Author:  Marvin Smith
#    Date:    5/16/2017
#
#    Purpose:  Complete build and install application
#


#-------------------------------#
#-      Clean the Software     -#
#-------------------------------#
Clean_Software()
{
    #  Log Entry
    echo '->  Cleaning the Project'

    #  Check if the build directory exists
    if [ -e "$BUILD_TYPE" ] && [ ! "$BUILD_TYPE" = "" ]; then
        echo "    -> Deleting $BUILD_TYPE"
        rm -rf $BUILD_TYPE
    fi

    #  Clear releases
    if [ -e "./releases" ]; then
        echo "    -> Deleting releases"
        rm -rf releases
    fi
}

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


#-----------------------------------#
#-     Build the Documentation     -#
#-----------------------------------#
Build_Documentation()
{
    #  Run Doxygen
    doxygen docs/Doxyfile
}


#--------------------------------#
#-      Usage Instructions      -# 
#--------------------------------#
Usage()
{
    echo "usage: $0 <task> [options]" 
    echo ""
    echo "  -c | --clean : Clean the project" 
    echo "  -m | --make  <build-args>: Build the project"
    echo ''
    echo '      Optional Arguments:'
    echo '      -j<number-threads> : Number of compile threads'
    echo '  -i | --install : Install software'
    echo '  -D | --docs    : Build Documentation'
    echo '  -f | --full    : Build, then Install Software'

}


#--------------------------------#
#-       Main Application       -#
#--------------------------------#

#  Baseline Flags
BUILD_TYPE='release'
RUN_MAKE=0
RUN_INSTALL=0
RUN_CLEAN=0
RUN_DOCS=0
NUM_THREADS=1
FLAG_SET=0


#  Iterate over command-line argument
for ARG in "$@"; do

    case $ARG in

        #  Show help
        '-h'|'--help'|'usage')
            Usage
            exit 0
            ;;

        #  Clean Project
        '-c'|'--clean')
            RUN_CLEAN=1
            FLAG_SET=1
            ;;

        #  Build Software
        '-m'|'--make')
            RUN_MAKE=1
            FLAG_SET=1
            ;;

        #  Install Software
        '-i'|'--install')
            RUN_INSTALL=1
            FLAG_SET=1
            ;;

        #  Do Everything
        '-f'|'--full')
            RUN_MAKE=1
            RUN_INSTALL=1
            FLAG_SET=1
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
        (-j*)
            NUM_THREADS=`echo ${ARG} | sed 's/-j//'`
            ;;

        #  Build Documentation
        '-D'|'--docs')
            RUN_DOCS=1
            FLAG_SET=1
            ;;

        *)
            echo "error: Unsupported flag ($ARG)"
            ;;
    esac
done

#  Check if flags provided
if [ "$FLAG_SET" = '0' ]; then
    echo "error: No flags provided."
    Usage
fi

#  Run Clean
if [ "$RUN_CLEAN" = '1' ]; then
    Clean_Software
fi

#   Run Make
if [ "$RUN_MAKE" = '1' ]; then
    Build_Software
fi

if [ "$RUN_INSTALL" = '1' ]; then
    Install_Software
fi

if [ "$RUN_DOCS" = '1' ]; then
    Build_Documentation
fi

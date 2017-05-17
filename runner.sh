#!/usr/bin/env bash
#
#    File:    runner.sh
#    Author:  Marvin Smith
#    Date:    5/16/2017
#
#    Purpose:  Complete build and install application
#



#--------------------------------#
#-       Main Application       -#
#--------------------------------#

#  Iterate over command-line argument
for ARG in "$@"; do

    case $ARG in

        '-m'|'--make')
            Build_Software
            exit 0
            ;;

        '-i'|'--install')
            Install_Software
            exit 0
            ;;

        '-f'|'--full')
            Build_Software
            Install_Software
            exit 0
            ;;
        *)
            echo "error: Unsupported flag ($ARG)"
            ;;
    esac
done


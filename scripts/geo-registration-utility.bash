#!/usr/bin/env bash
#
#    File:    geo-registration-utility.bash
#    Author:  Marvin Smith
#    Date:    5/16/2017
#
#    Purpose:  Run the Geo-Registration Utility
#

#  Set Environment Variables
export GEO_REGISTRATION_BASE=__GEO_REGISTRATION_BASE_PATH__

#  Add to path
export PATH=$PATH:$GEO_REGISTRATION_BASE/bin

#  Run the application
geo-registration-utility $@


#!/usr/bin/env python3

import argparse, shutil, os


#---------------------------------------#
#-      Parse Command-Line Options     -#
#---------------------------------------#
def Parse_Command_Line():

    #  Create output
    parser = argparse.ArgumentParser(description='Geo-Registration Utility Builder.')

    parser.add_argument('-i','--install-base-path',
                        dest='install_base_path',
                        default='releases/geo-registration-utility',
                        help='Installation Directory')


    return parser.parse_args()


#---------------------------#
#-      Do a Big Copy      -#
#---------------------------#
def Big_Copy( src_dir, dst_dir ):

    for root, dirs, files in os.walk( src_dir ):

        #  For each file
        for f in files:
            shutil.copy(src_dir + '/' + f, dst_dir + '/' + f)


#-------------------------------------------#
#-       Build the Release Structure       -#
#-------------------------------------------#
def Build_Release_Structure( options ):

    #  Create release directory
    try:
        os.makedirs('releases/geo-registration-utility/bin')
    except:
        pass

    try:
        os.makedirs('releases/geo-registration-utility/html')
    except:
        pass

    try:
        os.makedirs('releases/geo-registration-utility/icons')
    except:
        pass

    try:
        os.makedirs('releases/geo-registration-utility/scripts')
    except:
        pass

    #  Copy Icons and HTML Files
    Big_Copy( 'src/icons', 'releases/geo-registration-utility/icons/')
    Big_Copy( 'src/html', 'releases/geo-registration-utility/html/')

#-----------------------------------#
#-       Build the Run Script      -#
#-----------------------------------#
def Build_Run_Script( options ):

    #  Load Builder Script
    script_data = ''
    with open('scripts/geo-registration-utility.bash', 'r') as fin:
        script_data = fin.read()


    #  Start applying replaces
    script_data = script_data.replace('__GEO_REGISTRATION_BASE_PATH__', options.install_base_path)

    #  Write new file
    with open('releases/geo-registration-utility/scripts/geo-registration-utility.sh', 'w') as fout:
        fout.write(script_data)



#--------------------------#
#-      Main Function     -#
#--------------------------#
def Main():

    #  Parse Command-Line
    options = Parse_Command_Line()


    #  Build Release Structure
    Build_Release_Structure( options )

    #  Build the Run Script
    Build_Run_Script( options )



if __name__ == '__main__':
    Main()

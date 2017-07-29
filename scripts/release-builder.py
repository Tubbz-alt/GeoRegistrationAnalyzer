#!/usr/bin/env python3

import argparse, shutil, os


#---------------------------------------#
#-      Parse Command-Line Options     -#
#---------------------------------------#
def Parse_Command_Line():

    #  Create output
    parser = argparse.ArgumentParser(description='Geo-Registration Utility Builder.')

    parser.add_argument('-p','--prefix',
                        dest='prefix',
                        default='/opt/geo-registration-analyzer',
                        help='Destination on filesystem.')

    #   Installation Base Path
    parser.add_argument('-i','--install-base-path',
                        dest='install_base_path',
                        default='releases/geo-registration-analyzer',
                        help='Installation Directory')

    #   Build Directory
    parser.add_argument('--build-dir','-b',
                        dest='build_dir',
                        default='release',
                        help='Build Directory')


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

    #  Build Directory List
    dirlist = ['releases/geo-registration-analyzer/bin',
               'releases/geo-registration-analyzer/html',
               'releases/geo-registration-analyzer/icons',
               'releases/geo-registration-analyzer/scripts',
               'releases/geo-registration-analyzer/share',
               'releases/geo-registration-analyzer/images']

    #  Create release directories
    for dname in dirlist:
        try:
            os.makedirs(dname)
        except:
            pass

    #  Copy Icons and HTML Files
    Big_Copy( 'src/icons', 'releases/geo-registration-analyzer/icons/')
    Big_Copy( 'src/html', 'releases/geo-registration-analyzer/html/')
    Big_Copy( 'src/icons', 'releases/geo-registration-analyzer/images/')

    #  Copy Executable
    shutil.copy(options.build_dir + '/src/geo-registration-analyzer',
                options.install_base_path + '/bin/geo-registration-analyzer')


#-----------------------------------#
#-       Build the Run Script      -#
#-----------------------------------#
def Build_Run_Script( options ):

    #  Load Builder Script
    script_data = ''
    with open('scripts/geo-registration-analyzer.bash', 'r') as fin:
        script_data = fin.read()


    #  Start applying replaces
    script_data = script_data.replace('__GEO_REGISTRATION_BASE_PATH__', options.prefix )

    #  Write new file
    with open('releases/geo-registration-analyzer/scripts/geo-registration-analyzer.sh', 'w') as fout:
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

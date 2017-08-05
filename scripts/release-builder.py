#!/usr/bin/env python3

import argparse, shutil, os


#---------------------------------------#
#-      Parse Command-Line Options     -#
#---------------------------------------#
def Parse_Command_Line():

    #  Create output
    parser = argparse.ArgumentParser(description='Geo-Viewer Release Builder.')

    parser.add_argument('-p','--prefix',
                        dest='prefix',
                        default='/opt/geo-viewer',
                        help='Destination on filesystem.')

    #  Pre-Command Arguments
    parser.add_argument('--pre-cmd-args',
                        dest='pre_cmd_args',
                        default='',
                        help='Args to append to actual method call.')


    #   Installation Base Path
    parser.add_argument('-i','--install-base-path',
                        dest='install_base_path',
                        default='releases/geo-viewer',
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
def Build_Release_Structure( options, app_name ):

    #  Build Directory List
    dirlist = ['releases/geo-viewer/bin',
               'releases/geo-viewer/html',
               'releases/geo-viewer/icons',
               'releases/geo-viewer/scripts',
               'releases/geo-viewer/share']

    #  Create release directories
    for dname in dirlist:
        try:
            os.makedirs(dname)
        except:
            pass

    #  Copy Icons and HTML Files
    Big_Copy( 'src/apps/' + app_name + '/icons', 'releases/geo-viewer/icons/')
    Big_Copy( 'src/apps/' + app_name + '/html',  'releases/geo-viewer/html/')

    #  Copy Executable
    shutil.copy(options.build_dir + '/src/geo-viewer',
                options.install_base_path + '/bin/geo-viewer')


#-----------------------------------#
#-       Build the Run Script      -#
#-----------------------------------#
def Build_Run_Script( options, app_name ):

    #  Load Builder Script
    script_data = ''
    with open('scripts/' + app_name + '.bash', 'r') as fin:
        script_data = fin.read()


    #  Start applying replaces
    script_data = script_data.replace('__GEO_VIEWER_BASE_PATH__', options.prefix )
    script_data = script_data.replace('__PRE_CMD_ARGS__', options.pre_cmd_args )

    #  Write new file
    with open('releases/geo-viewer/scripts/' + app_name + '.sh', 'w') as fout:
        fout.write(script_data)



#--------------------------#
#-      Main Function     -#
#--------------------------#
def Main():

    #  Parse Command-Line
    options = Parse_Command_Line()


    #  Build Release Structure
    Build_Release_Structure( options, 'geo-viewer' )
    Build_Release_Structure( options, 'geo-registration-analyzer')

    #  Build the Run Script
    Build_Run_Script( options, 'geo-viewer' )
    Build_Run_Script( options, 'geo-registration-analyzer' )



if __name__ == '__main__':
    Main()

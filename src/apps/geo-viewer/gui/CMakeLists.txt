#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_VIEWER_SOURCES
        ${GEO_VIEWER_SOURCES}
        gui/Main_Window.cpp
        gui/ProjectBasePanel.cpp
        gui/ProjectImageryPanel.cpp
        gui/ProjectImageryToolbar.cpp
        gui/ProjectViewer.cpp
        gui/dialogs/import_asset/ImportAssetDialog.cpp
        gui/toolbar/PrimaryToolbarPane.cpp
        gui/toolbar/ProjectToolbarWidget.cpp
        gui/widgets/Asset_Manager_Widget.cpp
        gui/workers/ImportProjectJob.cpp
        gui/workers/Project_Worker.cpp
        PARENT_SCOPE )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_VIEWER_HEADERS
        ${GEO_VIEWER_HEADERS}
        gui/Main_Window.hpp
        gui/ProjectBasePanel.hpp
        gui/ProjectImageryPanel.hpp
        gui/ProjectImageryToolbar.hpp
        gui/ProjectViewer.hpp
        gui/dialogs/import_asset/ImportAssetDialog.hpp
        gui/toolbar/PrimaryToolbarPane.hpp 
        gui/toolbar/ProjectToolbarWidget.hpp
        gui/widgets/Asset_Manager_Widget.hpp
        gui/workers/ImportProjectJob.hpp
        gui/workers/Project_Worker.hpp
        PARENT_SCOPE )


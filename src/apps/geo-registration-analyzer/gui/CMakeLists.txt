#    File:    CMakeLists.txt
#    Author:  Marvin Smith
#    Date:    8/4/2017
#


#---------------------------------#
#-      Define our Sources       -#
#---------------------------------#
set( GEO_REGISTRATION_ANALYZER_SOURCES
        ${GEO_REGISTRATION_ANALYZER_SOURCES}
        gui/ConfigurationSaveDialog.cpp
        gui/LogViewerPanel.cpp
        gui/Main_Window.cpp
        gui/PreferenceDialog.cpp
        gui/ProjectBasePanel.cpp
        gui/ProjectViewerPanelBase.cpp
        gui/ProjectViewerPanelFactory.cpp
        gui/analysis/AnalysisBasePanel.cpp
        gui/matching/MatchingBasePanel.cpp
        gui/matching/NewProjectPanelMatching.cpp
        gui/matching/ProjectViewerPanelMatching.cpp
        gui/matching/ReferenceImageryPanel.cpp
        gui/matching/ReferenceToolbar.cpp
        gui/matching/TestImageryPanel.cpp
        gui/matching/TestToolbar.cpp
        gui/matching/Toolbar/MatchingToolbarWidget.cpp
        gui/matching/Toolbar/PrimaryMatchingToolbarPane.cpp
        gui/matching/Toolbar/ProjectMatchingToolbarPane.cpp
        gui/matching/Worker/Matching_Worker.cpp
        gui/matching/Worker/MatchingImportProjectJob.cpp
        gui/project_dialogs/ImportProjectDialog.cpp
        gui/project_dialogs/NewProjectDialog.cpp
        gui/project_dialogs/NewProjectPanelBase.cpp
        gui/project_dialogs/NewProjectPanelFactory.cpp
        PARENT_SCOPE )

#-----------------------------#
#-     Define our Headers    -#
#-----------------------------#
set( GEO_REGISTRATION_ANALYZER_HEADERS
        ${GEO_REGISTRATION_ANALYZER_HEADERS}
        gui/ConfigurationSaveDialog.hpp
        gui/LogViewerPanel.hpp
        gui/Main_Window.hpp
        gui/PreferenceDialog.hpp
        gui/ProjectBasePanel.hpp
        gui/ProjectViewerPanelBase.hpp
        gui/ProjectViewerPanelFactory.hpp
        gui/analysis/AnalysisBasePanel.hpp
        gui/matching/MatchingBasePanel.hpp
        gui/matching/NewProjectPanelMatching.hpp
        gui/matching/ProjectViewerPanelMatching.hpp
        gui/matching/ReferenceImageryPanel.hpp
        gui/matching/ReferenceToolbar.hpp
        gui/matching/TestImageryPanel.hpp
        gui/matching/TestToolbar.hpp
        gui/matching/Toolbar/MatchingToolbarWidget.hpp
        gui/matching/Toolbar/PrimaryMatchingToolbarPane.hpp
        gui/matching/Toolbar/ProjectMatchingToolbarPane.hpp
        gui/matching/Worker/Matching_Worker.hpp
        gui/matching/Worker/MatchingImportProjectJob.hpp
        gui/project_dialogs/ImportProjectDialog.hpp
        gui/project_dialogs/NewProjectDialog.hpp
        gui/project_dialogs/NewProjectPanelBase.hpp
        gui/project_dialogs/NewProjectPanelFactory.hpp
        PARENT_SCOPE )


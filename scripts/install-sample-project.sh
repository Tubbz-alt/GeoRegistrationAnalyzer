#!/usr/bin/env bash

#  Create Project Subdir
PROJECT_SUBDIR=~/.geo-viewer/projects/my_test_project
mkdir -p ${PROJECT_SUBDIR}

#  Copy project file
cp data/unit-test-data/sample-project-matching-01.cfg ${PROJECT_SUBDIR}/
cp data/unit-test-data/sample-project-matching-01-file-list.txt ${PROJECT_SUBDIR}/file-list.csv

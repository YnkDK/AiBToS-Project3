cmake_minimum_required(VERSION 2.8)
project(AiBToS_Project3)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "lib/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib/")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin/")


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -std=c++0x -march=native")



set(SOURCE_FILES
        src/FoldingAlgorithm.h
        src/HartIstrail.cpp
        src/HilbertCurve.cpp
        src/Progam.cpp)

add_executable(AiBToS_Project3 ${SOURCE_FILES})
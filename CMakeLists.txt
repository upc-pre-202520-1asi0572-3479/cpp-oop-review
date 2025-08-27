#[[
@file CMakeLists.txt
@brief CMake configuration file for the cpp_oop_review project.
@author IoT Solution Development Staff
@date 2025-08-27
@version 1.0
@license MIT License

This files configures the build for cpp_oop_review project, a C++ console application designed to illustrate
object-oriented programming concepts using a process simulation.
]]
# Minimum CMake version required for compatibility
cmake_minimum_required(VERSION 3.30)

# Project name
project(cpp_oop_review)

# Set C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# Include the directories containing the header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
        main.cpp
        src/Resource.cpp)
# Define the executable target
add_executable(cpp_oop_review ${SOURCES})

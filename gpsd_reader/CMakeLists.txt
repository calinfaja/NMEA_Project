# This script sets up the project configuration for a CMake build system.
# It defines the project name, version, and required CMake version.
# It also includes the necessary directories and dependencies for the project.
# Additionally, it configures the build options and compiler settings.
cmake_minimum_required(VERSION 3.10)
project(gpsd_reader)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure proper compiler flags for MinGW
if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()

# Add source files
add_executable(gpsd_reader
    src/main.cpp
    src/nmea_parser.cpp
)

# Include directories
target_include_directories(gpsd_reader PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(gpsd_reader VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gpsd_reader
    src/main.cpp
)

target_include_directories(gpsd_reader PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)
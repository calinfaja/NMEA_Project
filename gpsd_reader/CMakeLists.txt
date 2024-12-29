cmake_minimum_required(VERSION 3.10)
project(gpsd_reader)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags based on platform
if(MINGW)
    # Windows-specific flags for MinGW
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
elseif(UNIX)
    # Linux/WSL2 flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
    
    # Optional: Add debug symbols for development
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
    
    # Optional: Optimization flags for release builds
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
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

# Install configuration (Linux only)
if(UNIX)
    install(TARGETS gpsd_reader
            RUNTIME DESTINATION bin)
endif()
# GPS NMEA Parser

[![Windows Build](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/yourusername/gps-parser)
[![C++](https://img.shields.io/badge/C%2B%2B-14-blue.svg)](https://github.com/yourusername/gps-parser)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/yourusername/gps-parser)

A lightweight C++ application that parses NMEA GPS data and generates Google Maps routes from GPS coordinates. This version is specifically configured for Windows environments.

## 🚀 Features

- Parse NMEA GPS data files (GPGGA and GPRMC sentences)
- Extract coordinates, speed, and satellite information
- Combine matching GPS points from different NMEA sentences
- Generate Google Maps URLs for visualization
- Windows-optimized build system

## 📋 Prerequisites

- Windows 10/11
- CMake (version 3.10 or higher)
- MinGW-w64 with G++ compiler
- Git (optional, for version control)

## 🔧 Installation

1. Install MinGW-w64:
   ```bash
   # Download MinGW-w64 from: https://sourceforge.net/projects/mingw-w64/
   # Add MinGW-w64 bin directory to your system PATH

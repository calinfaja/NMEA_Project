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

- Linux WSL - Ubuntu
- CMake (version 3.10 or higher)
- MinGW-w64 with G++ compiler
- Git (optional, for version control)

## 🔧 How to run it?

After build, in build folder there will be the gpsd_reader.exe
To run the program:
./gpsd_reader <file>.nmea

**Example:**
NMEA File:


    $GPGGA,184818.050,5231.208,N,01323.313,E,1,12,1.0,0.0,M,0.0,M,,*6A
    $GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30
    $GPRMC,184818.050,A,5231.208,N,01323.313,E,2836.1,079.4,291224,000.0,W*44
    $GPGGA,184819.050,5231.352,N,01324.585,E,1,12,1.0,0.0,M,0.0,M,,*6B
    $GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30
    $GPRMC,184819.050,A,5231.352,N,01324.585,E,2723.9,161.6,291224,000.0,W*4C
    $GPGGA,184820.050,5230.635,N,01324.977,E,1,12,1.0,0.0,M,0.0,M,,*65
    $GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30
    $GPRMC,184820.050,A,5230.635,N,01324.977,E,3477.7,269.6,291224,000.0,W*44
    $GPGGA,184821.050,5230.629,N,01323.391,E,1,12,1.0,0.0,M,0.0,M,,*6C
    $GPGSA,A,3,01,02,03,04,05,06,07,08,09,10,11,12,1.0,1.0,1.0*30
    $GPRMC,184821.050,A,5230.629,N,01323.391,E,3477.7,269.6,291224,000.0,W*4D


**Output:**
>  Found 4 GPS data points:
>     ========================
>     Latitude: 52.510483°
>     Longitude: 13.389850°
>     Satellites: 12
>     Speed: 6440.700400 km/h
>     ------------------------
>     Latitude: 52.510583°
>     Longitude: 13.416283°
>     Satellites: 12
>     Speed: 6440.700400 km/h
>     ------------------------
>     Latitude: 52.520133°
>     Longitude: 13.388550°
>     Satellites: 12
>     Speed: 5252.457200 km/h
>     ------------------------
>     Latitude: 52.522533°
>     Longitude: 13.409750°
>     Satellites: 12
>     Speed: 5044.662800 km/h
>     ------------------------
>     
>     Google Maps Route URL:
>     https://www.google.com/maps/dir/52.510483,13.389850/52.510583,13.416283/52.520133,13.388550/52.522533,13.409750


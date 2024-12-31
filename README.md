# GPS NMEA Parser

[![Windows Build](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/yourusername/gps-parser)
[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg?style=flat&logo=c%2B%2B)](https://github.com/yourusername/gps-parser)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/yourusername/gps-parser)

A lightweight C++ application that parses NMEA GPS data and generates Google Maps routes from GPS coordinates. This version is specifically configured for Windows environments.

## 🚀 Features

- Parse NMEA GPS data files (GPGGA and GPRMC sentences)
- Extract coordinates, speed, and satellite information
- Combine matching GPS points from different NMEA sentences
- Generate Google Maps URLs for visualization
- Windows-optimized build system

## 📋 Prerequisites

- CMake (version 3.10 or higher)
- MinGW-w64 with G++ compiler
- Git (optional, for version control)

## 🔧 How to run it ON WINDOWS?
Build the program
After build, in build folder there will be the gpsd_reader.exe
To run the program in shell:
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
    Found 4 GPS data points:
    
    Latitude: 52.510483°
    Longitude: 13.389850°
    Satellites: 12
    Speed: 6440.700400 km/h
    
    Latitude: 52.510583°
    Longitude: 13.416283°
    Satellites: 12
    Speed: 6440.700400 km/h
    
    Latitude: 52.520133°
    Longitude: 13.388550°
    Satellites: 12
    Speed: 5252.457200 km/h
    
    Latitude: 52.522533°
    Longitude: 13.409750°
    Satellites: 12
    Speed: 5044.662800 km/h

>     Google Maps Route URL:
>     https://www.google.com/maps/dir/52.510483,13.389850/52.510583,13.416283/52.520133,13.388550/52.522533,13.409750




## Future Improvements

**If the NMEA text is not correct, for example:**

    $GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47
    $GPGGA,123520,9100.000,S,01131.000,W,1,08,0.9,545.4,M,46.9,M,,*55  # Invalid latitude > 90°
    $GPRMC,invalid,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A  # Invalid time field
    $GPGLL,4916.45,N,12311.12,W,225444,A*1D
    $GPXXX,4916.45,N,12311.12,W,225444,A*7E  # Unsupported sentence type
    $GPRMC,225446,A,4916.45,N,12311.12,W,0.0,054.7,191194,020.3,E*6D
    $GPGGA,091213,,,,,0,00,,,M,,M,,*7A  # Missing critical fields
    $GPRMC,130000,A,0,N,0,E,0.0,0.0,290220,0.0,E*5C  # Equator and Prime Meridian
    $GPGGA,135748,4723.845,N,00527.850,E,1,12,1.0,-10.2,M,48.0,M,,*76  # Negative altitude
    $GPGSV,2,1,08,01,40,083,41,02,17,308,43,03,25,150,37,04,27,312,39*75  # Satellite info
    $GPGSV,2,2,08,05,12,058,42,06,23,220,38,07,32,180,36,08,50,320,40*71
    $GPGGA,235959,8900.000,N,18000.000,E,1,08,0.9,0.0,M,0.0,M,,*59  # Boundary values for lat/lon
    $GPGGA,235959,12345.678,N,54321.987,E,1,08,0.9,0.0,M,0.0,M,,*73  # Invalid lat/lon formatting
 **The result is:**

> Found 8 GPS data points:
> 
> Latitude: -91.000000° Longitude: -11.516667° Satellites: 8 Speed:
> 99.990000 km/h
> 
> Latitude: 0.000000° Longitude: 0.000000° Satellites: 99 Speed:
> 0.000000 km/h
> 
> Latitude: 47.397417° Longitude: 5.464167° Satellites: 12 Speed:
> 99.990000 km/h
> 
> Latitude: 48.117300° Longitude: 11.516667° Satellites: 8 Speed:
> 99.990000 km/h
> 
> Latitude: 49.274167° Longitude: -123.185333° Satellites: 99 Speed:
> 0.000000 km/h
> 
> Latitude: 89.000000° Longitude: 180.000000° Satellites: 8 Speed:
> 99.990000 km/h
> 
> Latitude: 99.990000° Longitude: 99.990000° Satellites: 0 Speed:
> 99.990000 km/h
> 
> Latitude: 123.761300° Longitude: 543.366450° Satellites: 8 Speed:
> 99.990000 km/h
> 
> Google Maps Route URL:
> https://www.google.com/maps/dir/-91.000000,-11.516667/0.000000,0.000000/47.397417,5.464167/48.117300,11.516667/49.274167,-123.185333/89.000000,180.000000/99.990000,99.990000/123.761300,543.366450

## Improvements to be done:


1.  **Checksum Verification**:
    
- Checksum Verification  (malformed $GPXXX)  
- Latitude validation  (±90°) 
-   Longitude validation  (±180°)  -
-  Handle unsupported sentences 
-  Test boundary coordinates
2.  **Data Validation**:
- Check talker ID validity  (GP, GL, GA, GN)  
- Validate message types  (RMC, GGA, GSV, etc.)   
- Verify field count per message type 
- Check field data type correctness 
- Handle UTF-8 and special characters
- Handle latitude values exceeding ±90° or longitude exceeding ±180°.
- Deal with missing fields or nonsensical data (`12345.678,N`).
  
3.  ***Time and Date Validation*:**
- UTC time format validation (HHMMSS.sss)
- Date format validation (DDMMYY)
- Leap year handling
- Time zone considerations
4.  **Signal Quality**:
    
-  Test sentences near extreme geographic coordinates, e.g., North/South Pole, International Date Line.
- Speed sanity checks  (max realistic speed)  
- Position jump detection - 
- Course/bearing validation  (0-359.99)  
- Magnetic variation checks 
- Altitude reasonable limits

6.  **Memory Safety**:
- Maximum sentence length  (82 chars per standard)  
- Field buffer overflow protection 
- String termination verification 

7.  **Logging and Debugging**:
- Detailed error logging - 
- Performance metrics 
- Debug mode capabilities

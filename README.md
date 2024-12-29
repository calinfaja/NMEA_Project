GPS NMEA Parser
![Windows Build][]![C++][]![License][]

A lightweight C++ application that parses NMEA GPS data and generates Google Maps routes from GPS coordinates. This version is specifically configured for Windows environments.

🚀 Features
Parse NMEA GPS data files (GPGGA and GPRMC sentences)
Extract coordinates, speed, and satellite information
Combine matching GPS points from different NMEA sentences
Generate Google Maps URLs for visualization
Windows-optimized build system
📋 Prerequisites
Windows 10/11
CMake (version 3.10 or higher)
MinGW-w64 with G++ compiler
Git (optional, for version control)
🔧 Installation
Install MinGW-w64: ```bash
Download MinGW-w64 from: https://sourceforge.net/projects/mingw-w64/
Add MinGW-w64 bin directory to your system PATH ```
Install CMake: ```bash
Download CMake from: https://cmake.org/download/
During installation, select "Add CMake to system PATH"

Copy
Clone the repository: bash git clone https://github.com/yourusername/gps-parser.git   cd gps-parser git checkout windows-build   
🛠️ Build Instructions
Create and navigate to the build directory: ```bash
mkdir build
cd build

Copy
Generate MinGW Makefiles: bash cmake -G "MinGW Makefiles" ..   
Build the project: ```bash
cmake --build .

Copy
🎮 Usage
Run the application with your NMEA file: ```bash
./gpsd_reader.exe ../test/test_central_europe.nmea

Copy
Example output:
found

Copy
Point 1:
Latitude: 52.519500°
Longitude: 13.389667°   Satellites: 62
Speed: 16.000 km/h
------------------------
Point 2:   Latitude: 48.208833°   Longitude: 16.372333°   Satellites: 58
Speed: 23.000 km/h
------------------------
Point 3:   Latitude: 47.502833°   Longitude: 19.085833°   Satellites: 55
Speed: 28.000 km/h
------------------------
Point 4:   Latitude: 44.426167°   Longitude: 26.103833°   Satellites: 51
Speed: 35.000 km/h
------------------------

Google Maps Route URL:
https://www.google.com/maps/dir/52.519500,13.389667/48.208833,16.372333/47.502833,19.085833/44.426167,26.103833   ```
📁 Project Structure```
gps-parser/
├── include/
│ ├── gpsd.h # GPS data structures
│ └── nmea_parser.h # Parser class declaration
├── src/
│ ├── main.cpp # Application entry point
│ └── nmea_parser.cpp # Parser implementation
├── test/
│ └── test_central_europe.nmea # Sample NMEA data
├── CMakeLists.txt # Build configuration
└── README.md

apache

Copy

## 📊 Sample Data Format

The application expects NMEA sentences in the following format:```nmea
$GPGGA,120000.00,5231.1700,N,01323.3800,E,1,62,1.0,100.0,M,0.0,M,,*76
$GPRMC,120000.00,A,5231.1700,N,01323.3800,E,8.64,180.0,010224,000.0,W*76
Our test file (test_central_europe.nmea) contains a route through:

Berlin, Germany (52°31.17'N, 13°23.38'E) - Speed: 16 km/h
Satellites: 62
Vienna/Wien, Austria (48°12.53'N, 16°22.34'E)
Speed: 23 km/h
Satellites: 58
Budapest, Hungary (47°30.17'N, 19°05.15'E)
Speed: 28 km/h
Satellites: 55
Bucharest, Romania (44°25.57'N, 26°06.23'E)
Speed: 35 km/h
Satellites: 51
🔍 Testing
The repository includes sample NMEA files in the test directory:

test_central_europe.nmea: Route through Central European capitals
Each point contains matching GPGGA and GPRMC sentences
All coordinates are real-world locations
Speed and satellite data are realistic for urban environments
🛑 Known Limitations
Processes only GPGGA and GPRMC sentences
Requires exact coordinate matches between sentences
Windows-specific build configuration
No support for real-time GPS data
🔄 Future Improvements
 Add coordinate matching tolerance
 Include more NMEA sentence types
 Implement data validation
 Add unit tests
 Create automated build scripts
 Add real-time GPS data support
 Implement elevation data processing
 Add data logging capabilities
🤝 Contributing
Fork the repository
Create your feature branch (git checkout -b feature/AmazingFeature)
Commit your changes (git commit -m 'Add some AmazingFeature')
Push to the branch (git push origin feature/AmazingFeature)
Open a Pull Request
📝 License
This project is licensed under the MIT License - see the LICENSE file for details.

👥 Authors
Your Name - Initial work - YourGithub
🙏 Acknowledgments
NMEA format documentation
Google Maps URL format reference
GPS coordinate conversion formulas
🛠️ Troubleshooting
Common issues and solutions:

CMake not found - Ensure CMake is properly installed
Verify system PATH includes CMake
MinGW compilation errors
Check MinGW-w64 installation
Verify g++ is available in PATH
Run g++ --version to confirm installation
File not found errors
Check file paths are correct
Ensure NMEA file exists in specified location
Build errors
Delete build directory and retry
Ensure all dependencies are installed - Check CMake version compatibility
For additional support, please open an issue on the GitHub repository.

/**
 * @file main.cpp
 * @brief Main entry point for the GPS data reader application.
 * 
 * This file contains the main function which initializes the NMEA parser,
 * reads GPS data from a specified NMEA file, and prints the parsed GPS data
 * to the standard output. It also generates a Google Maps URL for the route
 * based on the parsed GPS data.
 * 
 * The application expects a single command-line argument specifying the path
 * to the NMEA file to be parsed. If the argument is not provided, the program
 * prints a usage message and exits.
 * 
 * The GPS data is printed with a fixed precision of 6 decimal places for
 * latitude and longitude. The number of satellites and speed are also displayed.
 * 
 * The Google Maps URL generated at the end of the program can be used to visualize
 * the route on Google Maps.
 * 
 * Usage:
 * @code
 * ./gpsd_reader <nmea_file>
 * @endcode
 * 
 * Dependencies:
 * - nmea_parser.h: Header file for the NMEAParser class and gps_data_t structure.
 * - iostream: For standard input and output operations.
 * - iomanip: For setting output format precision.
 */
#include "nmea_parser.h"
#include <iostream>
#include <iomanip>

/**
 * @brief Prints the GPS data to the standard output.
 * 
 * This function takes a gps_data_t structure as input and prints the latitude,
 * longitude, number of satellites, and speed in a formatted manner. The output
 * is displayed with a fixed precision of 6 decimal places for latitude and longitude.
 * 
 * @param data A constant reference to a gps_data_t structure containing the GPS data.
 */
void printGPSData(const gps_data_t& data) {
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Latitude: " << data.latitude << "°\n";
    std::cout << "Longitude: " << data.longitude << "°\n";
    std::cout << "Satellites: " << data.satellite_count << "\n";
    std::cout << "Speed: " << data.speed << " km/h\n";
    std::cout << "------------------------\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <nmea_file>\n";
        return 1;
    }

    NMEAParser parser(argv[1]);
    auto gps_data = parser.parseFile();

    std::cout << "Found " << gps_data.size() << " GPS data points:\n";
    std::cout << "========================\n";

    for (const auto& data : gps_data) {
        printGPSData(data);
    }

    // Generate and display Google Maps URL
    std::cout << "\nGoogle Maps Route URL:\n";
    std::cout << NMEAParser::generateGoogleMapsURL(gps_data) << "\n";

    return 0;
}
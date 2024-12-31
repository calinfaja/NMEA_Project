/**
 * @file nmea_parser.cpp
 * @brief Implementation of the NMEAParser class for parsing NMEA sentences from a file.
 * 
 * This file contains the implementation of the NMEAParser class, which is responsible for
 * reading NMEA sentences from a file, parsing them, and extracting GPS data. The extracted
 * data includes latitude, longitude, satellite count, and speed, which are stored in a 
 * gps_data_t structure. The class also provides functionality to generate a Google Maps URL
 * from the parsed GPS points.
 * 
 * The main functionalities provided by this class include:
 * - Splitting a string by a delimiter.
 * - Converting NMEA coordinate format to decimal degrees.
 * - Processing NMEA sentences and extracting relevant GPS data.
 * - Generating a Google Maps URL from the parsed GPS points.
 * - Parsing an entire file containing NMEA sentences.
 * 
 * The class uses a map to store GPS points, with the coordinates as the key and the gps_data_t
 * structure as the value. This allows for efficient updating and retrieval of GPS data.
 * 
 * The following NMEA sentence types are supported:
 * - $GPGGA: Provides latitude, longitude, and satellite count.
 * - $GPRMC: Provides latitude, longitude, and speed.
 * 
 * @note The conversion from knots to km/h is performed for speed values extracted from $GPRMC sentences.
 * 
 * @see nmea_parser.h
 */
#include "nmea_parser.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>

NMEAParser::NMEAParser(const std::string& filename) : filename_(filename) {}

std::vector<std::string> NMEAParser::splitString(const std::string& str, char delim) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}

double NMEAParser::convertToDecimalDegrees(const std::string& value, const std::string& direction) {
    if (value.empty()) return 99.99;
    
    double coordinate = std::stod(value);
    int degrees = static_cast<int>(coordinate / 100);
    double minutes = coordinate - (degrees * 100);
    double decimal = degrees + (minutes / 60);
    
    if (direction == "S" || direction == "W") {
        decimal = -decimal;
    }
    return decimal;
}

void NMEAParser::processNMEASentence(const std::vector<std::string>& tokens, 
                                   std::map<std::pair<double, double>, gps_data_t>& gps_points) {
    if (tokens.empty()) return;

    double lat = 99.99, lon = 99.99;

    if (tokens[0] == "$GPGGA" && tokens.size() >= 15) {
        // Extract coordinates from GPGGA
        lat = convertToDecimalDegrees(tokens[2], tokens[3]);
        lon = convertToDecimalDegrees(tokens[4], tokens[5]);

        // Create or update the point
        std::pair<double, double> coord_key(lat, lon);
        gps_data_t& point = gps_points[coord_key];
        
        // Always update coordinates and satellite count from GPGGA
        point.latitude = lat;
        point.longitude = lon;
        point.satellite_count = std::stoi(tokens[7]);
    }
    else if (tokens[0] == "$GPRMC" && tokens.size() >= 12) {
        // Extract coordinates from GPRMC
        lat = convertToDecimalDegrees(tokens[3], tokens[4]);
        lon = convertToDecimalDegrees(tokens[5], tokens[6]);

        // Look for matching coordinates
        std::pair<double, double> coord_key(lat, lon);
        
        // Update or create point
        gps_data_t& point = gps_points[coord_key];
        point.latitude = lat;
        point.longitude = lon;
        point.speed = std::stod(tokens[7]) * 1.852; // Convert knots to km/h
    }
}

std::string NMEAParser::generateGoogleMapsURL(const std::vector<gps_data_t>& gps_points) {
    std::stringstream url;
    url << "https://www.google.com/maps/dir/";
    
    bool first = true;
    for (const auto& point : gps_points) {
        if (!first) {
            url << "/";
        }
        url << std::fixed << std::setprecision(6);
        url << point.latitude << "," << point.longitude;
        first = false;
    }
    
    return url.str();
}

std::vector<gps_data_t> NMEAParser::parseFile() {
    std::map<std::pair<double, double>, gps_data_t> gps_points;
    std::ifstream file(filename_);
    
    std::string line;
    while (std::getline(file, line)) {
        auto tokens = splitString(line, ',');
        processNMEASentence(tokens, gps_points);
    }

    // Convert map to vector
    std::vector<gps_data_t> results;
    for (const auto& pair : gps_points) {
        results.push_back(pair.second);
    }

    return results;
}
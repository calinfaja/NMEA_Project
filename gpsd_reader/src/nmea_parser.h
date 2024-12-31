/**
 * @file nmea_parser.h
 * @brief Header file for the NMEAParser class, which is responsible for parsing NMEA sentences from a file and converting them into GPS data.
 * 
 * This file contains the declaration of the NMEAParser class and its member functions. The class provides functionality to:
 * - Parse NMEA sentences from a specified file.
 * - Convert parsed data into a format suitable for generating Google Maps URLs.
 * - Split strings based on a delimiter.
 * - Process individual NMEA sentences and convert them into GPS data.
 * - Convert NMEA coordinate values into decimal degrees.
 * 
 * Dependencies:
 * - <string>
 * - <vector>
 * - <map>
 * - "gpsd.h"
 * 
 * @note Ensure that the "gpsd.h" header file is available in the include path.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 * @author
 * Calin
 */
#ifndef NMEA_PARSER_H
#define NMEA_PARSER_H

#include <string>
#include <vector>
#include <map>
#include "gpsd.h"

class NMEAParser {
public:
    explicit NMEAParser(const std::string& filename);
    std::vector<gps_data_t> parseFile();
    static std::string generateGoogleMapsURL(const std::vector<gps_data_t>& gps_points);

private:
    std::string filename_;
    std::vector<std::string> splitString(const std::string& str, char delim);
    void processNMEASentence(const std::vector<std::string>& tokens, std::map<std::pair<double, double>, gps_data_t>& gps_points);
    double convertToDecimalDegrees(const std::string& value, const std::string& direction);
};

#endif // NMEA_PARSER_H
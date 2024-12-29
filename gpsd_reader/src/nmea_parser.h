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
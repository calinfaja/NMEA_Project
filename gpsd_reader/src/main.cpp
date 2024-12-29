#include "nmea_parser.h"
#include <iostream>
#include <iomanip>

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
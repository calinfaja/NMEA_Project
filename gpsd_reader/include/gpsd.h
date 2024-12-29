// gpsd.h
#ifndef GPSD_H
#define GPSD_H

struct gps_data_t {
    double latitude = 99.99;      // Initialize with defaults
    double longitude = 99.99;
    int satellite_count = 99;    // Changed from satellites to satellite_count
    double speed = 99.99;         // Speed in km/h
};

#endif // GPSD_H
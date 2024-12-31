/**
 * @file gpsd.h
 * @brief Header file for GPS data structure.
 *
 * This file contains the definition of the gps_data_t structure, which is used
 * to store GPS-related data such as latitude, longitude, satellite count, and speed.
 */

/**
 * @struct gps_data_t
 * @brief Structure to hold GPS data.
 *
 * This structure contains fields to store the latitude, longitude, number of
 * satellites in view, and speed of a GPS device. Default values are provided
 * for each field.
 *
 * @var gps_data_t::latitude
 * Member 'latitude' stores the latitude value in degrees.
 * Default value is 99.99.
 *
 * @var gps_data_t::longitude
 * Member 'longitude' stores the longitude value in degrees.
 * Default value is 99.99.
 *
 * @var gps_data_t::satellite_count
 * Member 'satellite_count' stores the number of satellites in view.
 * Default value is 99.
 *
 * @var gps_data_t::speed
 * Member 'speed' stores the speed in kilometers per hour.
 * Default value is 99.99.
 */
#ifndef GPSD_H
#define GPSD_H

struct gps_data_t {
    double latitude = 99.99;      // Initialize with defaults
    double longitude = 99.99;
    int satellite_count = 99;    // Number of satellites in view
    double speed = 99.99;         // Speed in km/h
};

#endif // GPSD_H
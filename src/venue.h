#ifndef VENUE_H
#define VENUE_H

#include <string>

class Venue {
private:
    std::string city;
    std::string pincode;
    std::string address;
    std::string timings;
    std::string openingTime;
    std::string closingTime;

public:
    Venue(const std::string& city, const std::string& pincode, const std::string& address, const std::string& timings, const std::string& opening, const std::string& closing);

    void displayVenueDetails() const; // Add this function declaration
    // Other necessary methods for venue
};

#endif // VENUE_H

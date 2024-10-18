#include "venue.h"
#include <iostream>

// Constructor
Venue::Venue(const std::string& city, const std::string& pincode, const std::string& address, const std::string& timings, const std::string& opening, const std::string& closing)
    : city(city), pincode(pincode), address(address), timings(timings), openingTime(opening), closingTime(closing) {}

// Display venue details
void Venue::displayVenueDetails() const {
    std::cout << "City: " << city << std::endl;
    std::cout << "Pincode: " << pincode << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Timings: " << timings << std::endl;
    std::cout << "Opening Time: " << openingTime << std::endl;
    std::cout << "Closing Time: " << closingTime << std::endl;
}

#include <iostream>
#include "venue.h"
#include "field.h"
#include "sports.h"
#include "booking.h"
#include "customer.h"
#include "extras.h"


int main() {
    // Create a Customer object
    Customer customer("John Doe", "1234567890", "Vegetarian meal", "123 Main St");

    // Create a Venue object
    Venue venue("New York", "10001", "456 Park Ave", "10 AM - 6 PM", "10:00", "18:00");

    // Create a Schedule object
    Schedule schedule("Morning", "10:00", "12:00", 2, false);

    // Create a Booking object
    Booking booking(1, 5, "Front row seats", 101, "10:00 AM - 12:00 PM", venue, schedule, "TX123456");

    // Display the booking details
    booking.displayBookingDetails();

    // Create an Extras object
    Extras extras("Pizza", "Cola", "T-shirt");

    // Display the extras
    extras.displayExtras();

 


    return 0;
}




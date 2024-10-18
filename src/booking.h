#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "venue.h" // Assuming Venue will be used in Booking
#include "schedule.h" // Assuming Schedule will be used in Booking
using namespace std;

class Booking {
private:
    int bookingID;
    int noOfSeats;
    string specialRequest;
    int fieldNumber;
    string timings;
    Venue venue; // Booking is associated with a venue
    Schedule schedule; // Booking is associated with a schedule
    string transactionID;

public:
    Booking(int id, int seats, const string& request, int field, const string& time, const Venue& venue, const Schedule& sched, const string& transID);

    void displayBookingDetails() const;
    int getBookingID() const;
    // Other necessary methods for managing bookings
};

#endif // BOOKING_H

#include "booking.h"
#include <iostream>
using namespace std;

// Constructor
Booking::Booking(int id, int seats, const string& request, int field, const string& time, const Venue& venue, const Schedule& sched, const string& transID)
    : bookingID(id), noOfSeats(seats), specialRequest(request), fieldNumber(field), timings(time), venue(venue), schedule(sched), transactionID(transID) {}

// Display booking details
void Booking::displayBookingDetails() const {
    cout << "Booking ID: " << bookingID << endl;
    cout << "Number of Seats: " << noOfSeats << endl;
    cout << "Special Request: " << specialRequest << endl;
    cout << "Field Number: " << fieldNumber << endl;
    cout << "Timings: " << timings << endl;
    cout << "Venue: "; venue.displayVenueDetails(); // Assuming Venue has a display function
    cout << "Schedule: "; schedule.displayScheduleDetails(); // Assuming Schedule has a display function
    cout << "Transaction ID: " << transactionID << endl;
}

// Return booking ID
int Booking::getBookingID() const {
    return bookingID;
}

// Add more methods as required

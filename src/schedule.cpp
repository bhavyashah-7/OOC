#include "schedule.h"
#include <iostream>
using namespace std;

// Constructor
Schedule::Schedule(const string& time, const string& start, const string& end, int games, bool status)
    : timing(time), startTime(start), endTime(end), noOfGames(games), bookingStatus(status) {}

// Display schedule details
void Schedule::displayScheduleDetails() const {
    cout << "Timing: " << timing << endl;
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Number of Games: " << noOfGames << endl;
    cout << "Booking Status: " << (bookingStatus ? "Booked" : "Available") << endl;
}

// Check if the schedule is available
bool Schedule::isAvailable() const {
    return !bookingStatus;
}

// Set the booking status
void Schedule::setBookingStatus(bool status) {
    bookingStatus = status;
}

// Add more methods as required

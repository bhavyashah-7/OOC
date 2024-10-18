#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
using namespace std;

class Schedule {
private:
    string timing;
    string startTime;
    string endTime;
    int noOfGames;
    bool bookingStatus;

public:
    Schedule(const string& time, const string& start, const string& end, int games, bool status);

    void displayScheduleDetails() const;
    bool isAvailable() const;
    void setBookingStatus(bool status);
    // Add other methods as needed
};

#endif // SCHEDULE_H

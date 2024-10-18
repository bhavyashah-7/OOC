#ifndef EXTRAS_H
#define EXTRAS_H

#include <string>
using namespace std;

class Extras {
private:
    string food;
    string beverage;
    string merchandise;

public:
    Extras(const string& food, const string& beverage, const string& merchandise);

    void displayExtras() const;
    // Add other methods as required to manage extras
};

#endif // EXTRAS_H

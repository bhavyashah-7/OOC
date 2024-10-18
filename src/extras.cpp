#include "extras.h"
#include <iostream>
using namespace std;

// Constructor
Extras::Extras(const string& food, const string& beverage, const string& merchandise)
    : food(food), beverage(beverage), merchandise(merchandise) {}

// Display extras details
void Extras::displayExtras() const {
    cout << "Food: " << food << endl;
    cout << "Beverage: " << beverage << endl;
    cout << "Merchandise: " << merchandise << endl;
}

// Add more methods as required

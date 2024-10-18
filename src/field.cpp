#include "field.h"
#include <iostream>
using namespace std;

Field::Field(string fieldName, string sportName, int numOfPlayers)
    : fieldName(fieldName), sportName(sportName), numOfPlayers(numOfPlayers) {}

void Field::display() {
    cout << "Field: " << fieldName << endl;
    cout << "Sport: " << sportName << endl;
    cout << "Players: " << numOfPlayers << endl;
}

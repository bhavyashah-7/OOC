#include "sports.h"
#include <iostream>
using namespace std;

Sports::Sports(string name, string description, int playTime) // constructor of class Sports
    : name(name), description(description), playTime(playTime) {} // constructor of class Sports that initializes the member variables , {} is empty as there is no code to be executed 

void Sports::display() {
    cout << "Sport: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Play Time: " << playTime << " minutes" << endl;
}

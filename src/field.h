#ifndef FIELD_H
#define FIELD_H

#include <string>
using namespace std;

class Field {
public:
    string fieldName;
    string sportName;
    int numOfPlayers;

    Field(string fieldName, string sportName, int numOfPlayers);
    void display();
};

#endif

#ifndef SPORTS_H //- this is a header guard. It prevents the header from being included more than once in the same file.
#define SPORTS_H //- the purpose of this is to prevent errors that can occur if the same header is included more than once.
using namespace std; 

#include <string>

class Sports { //- this class will be used to create objects that represent sports.
public:
    string name;
    string description;
    int playTime;

    Sports(string name, string description, int playTime);
    void display();
};

#endif //- this is end of header file. It is a good practice to include this in header files.
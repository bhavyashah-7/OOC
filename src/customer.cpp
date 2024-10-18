#include "customer.h"
#include <iostream>
using namespace std;

// Constructor
Customer::Customer(const string& name, const string& phone, const string& request, const string& addr)
    : name(name), phoneNumber(phone), specialRequest(request), address(addr) {}

// Display customer details
void Customer::displayCustomerDetails() const {
    cout << "Customer Name: " << name << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Special Request: " << specialRequest << endl;
    cout << "Address: " << address << endl;
}

// Getter for name
string Customer::getName() const {
    return name;
}

// Getter for phone number
string Customer::getPhoneNumber() const {
    return phoneNumber;
}

// Add more methods as required

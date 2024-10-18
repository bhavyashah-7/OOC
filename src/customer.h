#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
private:
    string name;
    string phoneNumber;
    string specialRequest;
    string address;

public:
    Customer(const string& name, const string& phone, const string& request, const string& addr);

    void displayCustomerDetails() const;
    string getName() const;
    string getPhoneNumber() const;
    // Add other methods for managing customer data
};

#endif // CUSTOMER_H

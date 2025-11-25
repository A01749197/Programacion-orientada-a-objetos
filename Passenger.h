#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
using namespace std;

class Passenger
{
private:
    string name;
    string phone;

public:
    Passenger();

    void setname(string name);
    void setphone(string phone);

    string getname();
    string getphone();
};

#endif

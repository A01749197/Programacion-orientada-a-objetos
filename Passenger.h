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

    void setname(string n);
    void setphone(string p);

    string getname();
    string getphone();
};

#endif

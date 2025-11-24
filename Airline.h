#pragma once
#include <iostream>
#include <string>
#include "Flight.h"

using namespace std;

constexpr int MAXFLIGHT = 10;

class Airline
{
private:
    Flight flight[MAXFLIGHT];
    string boardingcity;
    double income;
    string shortname;
    bool Agendado; 

public:
    Airline();
    void setboardingcity(string boardingcity);
    string getboardingcity();
    void setflight(int index, Flight f);
    Flight* getflight();
    void setincomes(double income);
    double getincomes();
    void setshortname(string shortname);
    string getshortname();
    void updateairline();
    void scheduleflight();
    double currentincome();
    void closeoperation();
};


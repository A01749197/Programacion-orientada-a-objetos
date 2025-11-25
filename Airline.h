#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include "Flight.h"

using namespace std;

constexpr int NUM_FLIGHTS = 5;

class Airline
{
private:
    Flight flights[NUM_FLIGHTS];
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

#endif

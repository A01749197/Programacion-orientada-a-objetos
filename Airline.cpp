#ifndef AIRLINE_H
#define AIRLINE_H

#include <iostream>
#include <string>
#include "Flight.h"

using namespace std;

constexpr int MAXFLIGHT = 10;

class Airline
{
private:
    Flight flights[MAXFLIGHT];
    string boardingCity;
    double income;
    string shortName;
    bool booked; 

public:
    Airline();
    
    void setBoardingCity(string boardingCity);
    string getBoardingCity();
    
    void setFlight(int index, Flight f);
    Flight* getFlights();
    
    void setIncomes(double income);
    double getIncomes();
    
    void setShortName(string shortName);
    string getShortName();
    
    void updateAirline();
    void scheduleFlight();
    double currentIncome();
    void closeOperation();
};

#endif

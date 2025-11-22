#ifndef FLIGHT_HPP
#define FLIGHT_HPP

#include <iostream>
#include <string>
#include "Passenger.hpp"

using namespace std;

const int ROWS = 30;
const int COLS = 4;

class Flight {
private:
    Passenger seats[ROWS][COLS];
    string date;
    string hour;
    string airplaneModel;
    string fromTo;
    string crew;
    double price;
    double distance;
    double fuel;

public:
    Flight();
    ~Flight();

    void setDate(string nDate);
    string getDate();
    void setHour(string nHour);
    string getHour();
    void setAirplaneModel(string nAirplaneModel);
    string getAirplaneModel();
    void setFromTo(string nFromTo);
    string getFromTo();
    void setCrew(string nCrew);
    string getCrew();

    void setPrice(double nPrice);
    double getPrice();
    void setDistance(double nDistance);
    double getDistance();
    
    void setFuel(double nFuel);
    double getFuel();

    void calculateFuel();
    bool assignSeat(int row, int col, Passenger p);
    void showSeats();
};

#endif
#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include "Passenger.h"

using namespace std;

constexpr int ROWS = 30;
constexpr int COLS = 4;

class Flight
{
private:
    Passenger seats[ROWS][COLS];
    string date;
    string crew;
    string fromTo;
    float distance;
    float price;
    string airplanemodel;
    string hour;

public:
    Flight();

    void setdate(string d);
    string getdate();
    
    void setseat(int row, int col, Passenger p);
    bool assignSeat(int row, int col, Passenger p);
    void showSeats();

    void setcrew(string c);
    string getcrew();
    
    void setfromto(string ft);
    string getfromto();
    
    void setdistance(float d);
    float getdistance();
    
    void setprice(float p);
    float getprice();
    
    void setairplanemodel(string am);
    string getairplanemodel();
    
    void sethour(string h);
    string gethour();
};

#endif

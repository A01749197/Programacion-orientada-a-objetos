#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include "Passenger.h"

using namespace std;

const int ROWS = 30;
const int COLS = 4;

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

    void setdate(string date);
    string getdate();
    
    void setseat(int row, int col, Passenger p);
    bool assignSeat(int row, int col, Passenger p);
    void showSeats();

    void setcrew(string crew);
    string getcrew();
    
    void setfromto(string fromTo);
    string getfromto();
    
    void setdistance(float distance);
    float getdistance();
    
    void setprice(float price);
    float getprice();
    
    void setairplanemodel(string airplanemodel);
    string getairplanemodel();
    
    void sethour(string hour);
    string gethour();
};

#endif

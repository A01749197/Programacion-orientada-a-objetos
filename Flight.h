#pragma once
#include <iostream>
#include <string>
#include "Passenger.h"

using namespace std;

constexpr int ROWS = 30;
constexpr int COLS = 4;

class Flight
{
private:
    Passenger seats[30][4];
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
    void setseat(int row, int col, Passenger p);
    string getdate();
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
	string gethour();
	void sethour(string hour);
};

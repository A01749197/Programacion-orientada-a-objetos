#ifndef AIRPORT_H
#define AIRPORT_H

#include <iostream>
#include "Airline.h"
using namespace std;

constexpr int NUM_AIRLINES = 3;

class Airport
{
private:
	Airline airlines[NUM_AIRLINES];
	string name;
	string currentdate;
	string city;
	string country;
	int totaltransactions;
	double totaldailyincome;

public:
	Airport();
	
	void setairlines(int index, Airline a);
	Airline* getairlines();
	
	void setname(string name);
	string getname();
	
	void setcurrentdate(string currentdate);
	string getcurrentdate();
	
	void setcity(string city);
	string getcity();
	
	void setcountry(string country);
	string getcountry();
	
	void settotaltransactions(int totaltransactions);
	int gettotaltransactions();
	
	void settotaldailyincome(double totaldailyincome);
	double gettotaldailyincome();
	
	void startoperations(string currentdate);
	void closeoperations();
	void printallflights();
};

#endif

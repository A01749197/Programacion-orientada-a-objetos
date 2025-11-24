#include "Airport.h"
#include <iostream>
using namespace std;
Airport::Airport()
{
	cout << "Ingrese la fecha actual (DD/MM/AAAA): ";
	cin >> this->currentdate;
	for (int i = 0; i < MAXAIRLINE; i++) 
	{
		airlines[i] = Airline();   
	}
	for (int i = 0; i < MAXFLIGHT; i++) 
	{
		allFlights[i] = Flight();  
	}
	startoperations(currentdate);
}
void Airport::setairlines(int index, Airline a)
{
	this->airlines[index] = a;
}
Airline* Airport::getairlines()
{
	return airlines;
}
void Airport::setname(string name)
{
	this->name = name;
}
string Airport::getname()
{
	return name;
}
void Airport::setcurrentdate(string currentdate)
{
	this->currentdate = currentdate;
}
string Airport::getcurrentdate()
{
	return currentdate;
}
void Airport::setcity(string city)
{
	this->city = city;
}
string Airport::getcity()
{
	return city;
}
void Airport::setcountry(string country)
{
	this->country = country;
}
string Airport::getcountry()
{
	return country;
}
void Airport::settotaltransactions(int totaltransactions)
{
	this->totaltransactions = totaltransactions;
}
int Airport::gettotaltransactions()
{
	return totaltransactions;
}
void Airport::settotaldailyincome(double totaldailyincome)
{
	this->totaldailyincome = totaldailyincome;
}
double Airport::gettotaldailyincome()
{
	return totaldailyincome;
}
void Airport::startoperations(string currentdate)
{
	cout << "Codigo identificador del aeropuerto: " << endl;
	cin >> this->name;
	cout << "Ciudad del aeropuerto: " << endl;
	cin >> this->city;
	cout << "Pais del aeropuerto: " << endl;
	cin >> this->country;

	for (int i = 0; i < MAXAIRLINE; i++)
	{
		airlines[i].setboardingcity(this->city);
		for (int j = 0; j < MAXFLIGHT; j++)
		{
			airlines[i].getflight()[j].setdate(currentdate);
		}
	}
}
void Airport::closeoperations()
{
	for (int i = 0; i < MAXAIRLINE; i++)
	{
		if (airlines[i].getincomes() > 0)
		{
			totaltransactions++;
			totaldailyincome += airlines[i].getincomes();
		}
	}

	cout << "Cerrando operaciones\n" << endl;
	cout << "Total de transacciones del dia: " << totaltransactions << endl;
	cout << "Ingreso total del dia: $" << totaldailyincome << endl;
}

void Airport::printallflights()
{
	cout << "\nLos vuelos programados para el día " << this->currentdate << " son:\n\n";

	for (int i = 0; i < MAXAIRLINE; i++)
	{
		Airline& A = airlines[i];
		cout << "Aerolínea: " << A.getshortname()
			<< "  (Ciudad base: " << A.getboardingcity() << ")\n";

		Flight* vuelos = A.getflight();

		for (int j = 0; j < MAXFLIGHT; j++)
		{
			if (vuelos[j].getdate() == "")
				continue;

			cout << "   Vuelo " << j
				<< "  Ruta: " << vuelos[j].getfromto()
				<< "  Hora: " << vuelos[j].gethour()
				<< "  Modelo: " << vuelos[j].getairplanemodel()
				<< "\n";
		}

		cout << "---------------------------------------\n";
	}
}

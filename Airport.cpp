#include "Airport.h"

Airport::Airport()
{
    totaltransactions = 0;
    totaldailyincome = 0;
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
    // Solo asignamos la fecha y propagamos la ciudad a las aerolineas
    // Se asume que el profesor uso setcity() antes de llamar esto
    this->currentdate = currentdate;

	for (int i = 0; i < MAXAIRLINE; i++)
	{
		airlines[i].setboardingcity(this->city);
		
        Flight* vuelos = airlines[i].getflight();
        for (int j = 0; j < MAXFLIGHT; j++)
		{
			vuelos[j].setdate(currentdate);
		}
	}
}

void Airport::closeoperations()
{
    totaltransactions = 0;
    totaldailyincome = 0;

	for (int i = 0; i < MAXAIRLINE; i++)
	{
		if (airlines[i].getincomes() > 0)
		{
			totaltransactions++;
			totaldailyincome += airlines[i].getincomes();
		}
	}

	cout << "\nCerrando operaciones" << endl;
	cout << "Total de transacciones: " << totaltransactions << endl;
	cout << "Ingreso total: $" << totaldailyincome << endl;
}

void Airport::printallflights()
{
	cout << "\nVuelos programados para el dia " << this->currentdate << ":\n\n";

	for (int i = 0; i < MAXAIRLINE; i++)
	{
		Airline& A = airlines[i];
        
        if(A.getshortname() == "") continue;

		cout << "Aerolinea: " << A.getshortname() << "\n";

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
		cout << endl; 
	}
}

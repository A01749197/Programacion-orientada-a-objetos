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
    this->currentdate = currentdate;

	cout << "Identificador del aeropuerto: ";
	cin >> this->name;
	cout << "Ciudad de operacion: ";
	cin >> this->city;
	cout << "Pais: ";
	cin >> this->country;

	for (int i = 0; i < NUM_AIRLINES; i++)
	{
		airlines[i].setboardingcity(this->city);
		
        Flight* vuelos = airlines[i].getflight();
        for (int j = 0; j < NUM_FLIGHTS; j++) 
			vuelos[j].setdate(currentdate);
		}
	}
}

void Airport::closeoperations()
{

    
    totaltransactions = 0;
    totaldailyincome = 0;

	for (int i = 0; i < NUM_AIRLINES; i++)
	{
        // Sumamos el ingreso de cada aerolinea al total del dia
        if (airlines[i].getincomes() > 0)
        {
            totaldailyincome += airlines[i].getincomes();
        }

        Flight* f = airlines[i].getflight();
        for(int j = 0; j < NUM_FLIGHTS; j++)
        {
            if(f[j].getairplanemodel() != "")
            {
                totaltransactions++;
            }
        }
	}

	cout << "\nCerrando operaciones" << endl;
	cout << "Total de transacciones: " << totaltransactions << endl;
	cout << "Ingreso total: $" << totaldailyincome << endl;
}

void Airport::printallflights()
{
	cout << "Los vuelos programados para " << this->currentdate << " son :\n\n";

	for (int i = 0; i < NUM_AIRLINES; i++)
	{
		Airline& A = airlines[i];
        
        if(A.getshortname() == "") continue;

		cout << "Aerolinea: " << A.getshortname() << "\n";

		Flight* vuelos = A.getflight();

		for (int j = 0; j < NUM_FLIGHTS; j++)
		{
			if (vuelos[j].getdate() == "" || vuelos[j].getairplanemodel() == "")
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

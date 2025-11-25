#include "Airline.h"

Airline::Airline() : income(0), Agendado(false)
{
}

void Airline::setboardingcity(string boardingcity)
{
    this->boardingcity = boardingcity;
}

string Airline::getboardingcity()
{
    return boardingcity;    
}

void Airline::setflight(int index, Flight f)
{
    flight[index] = f;
}

Flight* Airline::getflight()
{
    return flight;
}

void Airline::setincomes(double income)
{
	this->income = income;
}

double Airline::getincomes()
{
    return income;
}

void Airline::setshortname(string shortname)
{
	this->shortname = shortname;
}

string Airline::getshortname()
{
	return shortname;
}

void Airline::updateairline()
{
	string aerolinea;
    string shortname;
	cout << "Ingrese el shortname: (ej. Aeromexico - AM) ";
    cin >> shortname;
	setshortname(shortname);    
    
    cout << "Ingrese el nombre de la aerolinea: ";
    cin >> aerolinea;
}

void Airline::scheduleflight()
{
    int v;
    cout << "Ingrese número de vuelo: ";
    cin >> v;

    Flight& f = flight[v]; 

    cout << "Modelo de avión: " << f.getairplanemodel() << endl;
    cout << "Tripulación: " << f.getcrew() << endl;
    cout << "Hora: " << f.gethour() << endl;
    cout << "Precio: " << f.getprice() << endl;
    cout << "Distancia: " << f.getdistance() << endl;

    char continuar = 's';

    while (continuar == 's')
    {
        f.showSeats();

        int row, col;
        cout << "\nFila (1-30): ";
        cin >> row;
        cout << "Columna (1-4): ";
        cin >> col;

        Passenger p;
        string name, phone;

        cout << "Nombre pasajero: ";
        cin >> name;
        p.setname(name); 

        cout << "Telefono pasajero: ";
        cin >> phone;
        p.setphone(phone);ne

        if (f.assignSeat(row - 1, col - 1, p))
        {
            cout << "Asiento asignado!" << endl;
            Agendado = true;
            income += f.getprice();
        }
        else
            cout << "Asiento ocupado o inválido." << endl;

        cout << "\n¿Asignar otro asiento? (s/n): ";
        cin >> continuar;
    }
}

double Airline::currentincome()
{
	cout << "Ingreso actual de la aerolínea: $" << income << endl;
	return income;
}

void Airline::closeoperation()
{
    cout << "\nCerrando operaciones de la aerolínea por hoy..." << endl;
	cout << "Ingreso total del día: $" << income << endl;
}

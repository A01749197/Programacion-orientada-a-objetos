#include "Airline.h"

Airline::Airline() : income(0), Agendado(false)
{
}

void Airline::setboardingcity(string boardingcity) { this->boardingcity = boardingcity; }
string Airline::getboardingcity() { return boardingcity; }

void Airline::setflight(int index, Flight f) { flights[index] = f; }
Flight* Airline::getflight() { return flights; }

void Airline::setincomes(double income) { this->income = income; }
double Airline::getincomes() { return income; }

void Airline::setshortname(string shortname) { this->shortname = shortname; }
string Airline::getshortname() { return shortname; }

void Airline::updateairline()
{
	string aerolinea;
    string shortname;
	cout << "Ingrese clave aerolinea (ej. AM): ";
    cin >> shortname;
	setshortname(shortname);    
    
    cout << "Ingrese nombre aerolinea: ";
    cin >> aerolinea;
}

void Airline::scheduleflight()
{
    int v = -1;
    for(int i=0; i < NUM_FLIGHTS; i++) {
        if(flights[i].getairplanemodel() == "") {
            v = i;
            break;
        }
    }

    if (v == -1) {
        cout << "Vuelos de la linea aerea saturados, imposible programar." << endl;
        return;
    }

    Flight& f = flights[v]; 
    
    string model, destination, crew, hour;
    float distance, price;

    cout << "Programando Vuelo " << v << "..." << endl;
    cout << "Modelo del avion: ";
    cin >> model;
    f.setairplanemodel(model);

    cout << "Ciudad Destino: ";
    cin >> destination;
    f.setfromto(this->boardingcity + " - " + destination);

    cout << "Distancia (km): ";
    cin >> distance;
    f.setdistance(distance);
    
    f.calculateFuel();

    cout << "Tripulacion: ";
    cin >> crew;
    f.setcrew(crew);

    cout << "Horario (ej 12:00): ";
    cin >> hour;
    f.sethour(hour);

    cout << "Precio boleto: ";
    cin >> price;
    f.setprice(price);

    char continuar = 's';
    while (continuar == 's')
    {
        f.showSeats();

        int row, col, cantidad;
        cout << "Cuantos asientos desea reservar? ";
        cin >> cantidad;

        for(int k=0; k<cantidad; k++) {
            cout << "\nAsiento " << k+1 << " de " << cantidad << endl;
            cout << "Fila (1-30): ";
            cin >> row;
            cout << "Columna (1-4): ";
            cin >> col;

            Passenger p;
            string name, phone;

            cout << "Nombre pasajero: ";
            cin >> name;
            p.setname(name);

            cout << "Telefono: ";
            cin >> phone;
            p.setphone(phone);

            if (f.assignSeat(row - 1, col - 1, p))
            {
                cout << "Asiento asignado!" << endl;
                Agendado = true;
                income += f.getprice();
            }
            else {
                cout << "Asiento ocupado o invalido." << endl;
                k--; 
            }
        }

        cout << "\nDesea registrar otro pasajero/grupo? (s/n): ";
        cin >> continuar;
    }
}

double Airline::currentincome()
{
	cout << "Ingreso actual aerolinea: $" << income << endl;
	return income;
}

void Airline::closeoperation()
{
	cout << "Ingreso total del dia (Aerolinea " << shortname << "): $" << income << endl;
}

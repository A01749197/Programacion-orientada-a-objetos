#include "Flight.h"

Flight::Flight() : fuel(0), distance(0), price(0)
{
}

void Flight::setdate(string date) 
{ 
    this->date = date; 
}
string Flight::getdate() 
{ return date; 
}

void Flight::setseat(int row, int col, Passenger p) 
{ 
    seats[row][col] = p; 
}

bool Flight::assignSeat(int row, int col, Passenger p)
{
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) return false;
    if (seats[row][col].getname() != "") return false;

    seats[row][col] = p;
    return true;
}

void Flight::showSeats()
{
    cout << "\nMapa de asientos (O = ocupado, L = libre):\n";
    for (int r = 0; r < ROWS; r++) {
        cout << "Fila " << r + 1 << ": ";
        for (int c = 0; c < COLS; c++) {
            if (seats[r][c].getname() == "") cout << "[L] ";
            else cout << "[O] ";
        }
        cout << endl;
    }
}

void Flight::setcrew(string crew) 
{ 
    this->crew = crew; 
}
string Flight::getcrew() 
{ 
    return crew; 
}

void Flight::setfromto(string fromTo) 
{ 
    this->fromTo = fromTo; 
}
string Flight::getfromto() 
{ 
    return fromTo; 
}

void Flight::setdistance(float distance) 
{ 
    this->distance = distance; 
}
float Flight::getdistance() 
{ 
    return distance; 
}

void Flight::setprice(float price) 
{ 
    this->price = price; 
}
float Flight::getprice() 
{ 
    return price; 
}

void Flight::setairplanemodel(string airplanemodel) 
{
    this->airplanemodel = airplanemodel; 
}
string Flight::getairplanemodel() 
{
    return airplanemodel; 
}

void Flight::sethour(string hour) 
{
    this->hour = hour; 
}
string Flight::gethour() 
{
    return hour; 
}

void Flight::calculateFuel()
{
    this->fuel = (this->distance / 100.0) * 1200.0;
    cout << "El combustible requerido para viajar es de " << this->fuel << " litros." << endl;
}

float Flight::getfuel() { return fuel; }

#include "Flight.hpp"
#include <iostream>

using namespace std;

Flight::Flight() {
    price = 0.0;
    distance = 0.0;
    fuel = 0.0;
}

Flight::~Flight() {
}

void Flight::setDate(string nDate) {
    date = nDate;
}

string Flight::getDate() {
    return date;
}

void Flight::setHour(string nHour) {
    hour = nHour;
}

string Flight::getHour() {
    return hour;
}

void Flight::setAirplaneModel(string nAirplaneModel) {
    airplaneModel = nAirplaneModel;
}

string Flight::getAirplaneModel() {
    return airplaneModel;
}

void Flight::setFromTo(string nFromTo) {
    fromTo = nFromTo;
}

string Flight::getFromTo() {
    return fromTo;
}

void Flight::setCrew(string nCrew) {
    crew = nCrew;
}

string Flight::getCrew() {
    return crew;
}

void Flight::setPrice(double nPrice) {
    price = nPrice;
}

double Flight::getPrice() {
    return price;
}

void Flight::setDistance(double nDistance) {
    distance = nDistance;
}

double Flight::getDistance() {
    return distance;
}

void Flight::setFuel(double nFuel) {
    fuel = nFuel;
}

double Flight::getFuel() {
    return fuel;
}

void Flight::calculateFuel() {
    fuel = (distance * 1200.0) / 100.0;
}

bool Flight::assignSeat(int row, int col, Passenger p) {
    if (row < 0 ||   row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }

    if (seats[row][col].getName() != "") {
        return false;
    }

    seats[row][col] = p;
    return true;
}

void Flight::showSeats() {
    cout << "   A  B  C  D" << endl;
    for (int r = 0; r < ROWS; r++) {
        if (r + 1 < 10) cout << "0" << r + 1 << " ";
        else cout << r + 1 << " ";

        for (int c = 0; c < COLS; c++) {
            if (seats[r][c].getName() == "")
                cout << "[L] ";
            else
                cout << "[X] ";
        }
        cout << endl;
    }
}

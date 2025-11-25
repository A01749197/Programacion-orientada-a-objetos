#include "Passenger.h"

Passenger::Passenger() {
}

void Passenger::setname(string name) {
    this->name = name;
}

void Passenger::setphone(string phone) {
    this->phone = phone;
}

string Passenger::getname() {
    return name;
}

string Passenger::getphone() {
    return phone;
}

#include "Passenger.h"

Passenger::Passenger() {
}

void Passenger::setname(string n) {
    name = n;
}

void Passenger::setphone(string p) {
    phone = p;
}

string Passenger::getname() {
    return name;
}

string Passenger::getphone() {
    return phone;
}

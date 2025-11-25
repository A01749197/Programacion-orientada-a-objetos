#include "Passenger.h"

Passenger::Passenger() {
}

void Passenger::setname(string nName) {
    name = nName;
}

void Passenger::setphone(string nPhone) {
    phone = nPhone;
}

string Passenger::getname() {
    return name;
}

string Passenger::getphone() {
    return phone;
}

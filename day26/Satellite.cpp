#include <iostream>
#include "Satellite.h"

Satellite::Satellite(string n, double b) {
    name = n;
    battery = b;
}

bool Satellite::is_low() const {return battery < 20;}
double Satellite::get_battery() const {return battery; }
void Satellite::charge(double amount) {
    battery += amount;
    if (battery >= 100) {
        battery = 100;
    }
}

void Satellite::print_status() const {
    cout << name << " Battery: " << battery << "\n";
}



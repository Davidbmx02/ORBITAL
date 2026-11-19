#include <iostream>
#include "Satellite.h"
#include <fstream>

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

void Satellite::run_command(string cmd) {
    int space = cmd.find(' ');
    string word = cmd.substr(0, space);
    double amount = stod(cmd.substr(space + 1));

    if (word == "CHARGE") {
        charge(amount);
    } else if (word == "DRAIN") {
        battery = battery - amount;
    } else {
        cout << "Unknown command" << endl;
    }
}

void Satellite::save_log(string filename) const {
    ofstream log(filename, ios::app);
    log << name << ": " << battery << endl;
    log.close();
}

void Satellite::run_file(string filename) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        run_command(line);
    }
    file.close();

}


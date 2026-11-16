#pragma once
#include <string>
using namespace std;

class Satellite {
private:
    double battery;
public:
    string name;
    Satellite(string n, double b);
    bool is_low() const;
    double get_battery() const;
    void charge(double amount);
    void print_status() const;

};

// Mission 2: ORBITAL Class
#include <iostream>
#include <string>
using namespace std;

// 1) Write the class Satellite HERE (above main / arriba de main)
class Satellite {
public:
    string name;
    double battery;

    void print_status() {
        cout << name << " Battery: " << battery << endl;
    }

    void charge(double amount) {
        battery = battery + amount;
    }
};


int main() {
    // 2) Create sat1 and sat2, give them name and battery, call print_status()
    int number;
    Satellite sat1;
    Satellite sat2;

    sat1.name = "Falcon";
    sat1.battery = 80;
    sat1.print_status();

    sat2.name = "Dragon";
    sat2.battery = 45;
    sat2.print_status();

    return 0;
}

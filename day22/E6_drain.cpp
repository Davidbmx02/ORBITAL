// Mission 15: drain() (descargar la bateria)
// TODO: add a method drain(double amount) to the class.
// It lowers the battery. If the battery goes below 0, set it to 0.

#include <iostream>
#include <string>
using namespace std;

class Satellite {
public:
    string name;
    double battery;

    Satellite(string n, double b) {
        name = n;
        battery = b;
    }

    void print_status() {
        cout << name << " Battery: " << battery << endl;
    }

    // Write drain() here
    void drain(double amount) {
        battery = battery - amount;
        if(battery < 0) {
            battery = 0;
        }
    }

    bool is_low() {
        return battery < 20;
    }

};

int main() {
    Satellite sat("Falcon", 30);
    sat.print_status();   // 30
    // sat.drain(20);     // expected: 10
    sat.drain(20);
    // sat.print_status();
    sat.print_status();
    // sat.drain(50);     // expected: 0 (not -40!)
    sat.drain(50);
    // sat.print_status();
    sat.print_status();

    if(sat.is_low()) {
        cout << "LOW POWER!" << endl;
    }

    return 0;
}

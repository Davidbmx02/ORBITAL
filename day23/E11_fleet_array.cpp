// New topic: array of objects (arreglo de objetos)
// One list, many satellites. A loop talks to each one: fleet[i]
//
// 1. Make an array of 3 satellites:
//      Falcon 50, Starlink 80, Dragon 20
// 2. Loop and print each one (i < 3)
// 3. Loop again and charge each one by 10
// 4. Loop and print again
// Expect after charge: 60, 90, 30

#include <iostream>
#include <string>
using namespace std;

class Satellite {
private:
    double battery;

public:
    string name;

    Satellite(string n, double b) {
        name = n;
        battery = b;
    }

    void print_status() {
        cout << name << " Battery: " << battery << endl;
    }

    void charge(double amount) {
        battery = battery + amount;
        if (battery > 100) {
            battery = 100;
        }
    }
};

int main() {
    // TODO: create the array and write the three loops

    Satellite fleet[3] = {
        Satellite("Falcon", 50),
        Satellite("Starlink", 80),
        Satellite("Dragon", 20)
    };

    for (int i = 0; i < 3; i++) {
        fleet[i].print_status();
    }

    for(int i = 0; i < 3; i++) {
        fleet[i].charge(10);
        fleet[i].print_status();
    }

    return 0;
}

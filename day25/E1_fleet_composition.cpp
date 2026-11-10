// Nov 9 - ORBITAL: a Fleet has Satellites (composition)
// The Satellite class stays as it is in the project.
// Write class Fleet and use it in main.

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

    bool is_low() const {
        return battery < 20;
    }

    double get_battery() const {
        return battery;
    }

    void charge(double amount) {
        battery += amount;
        if (battery > 100) {
            battery = 100;
        }
    }

    void print_status() const {
        cout << name << " Battery: " << battery << '\n';
    }
};

// TODO: write class Fleet
class Fleet {
private:
    Satellite sats[4];
    int size;

public:
    Fleet ()
        : sats{
            Satellite("Falcon", 6),
            Satellite("Starlink", 20),
            Satellite("Dragon", 18),
            Satellite("Orion", 75)
        }{
        size = 4;
    }

    void print_all() const {
        for(int i = 0; i < size; i++) {
            sats[i].print_status();
        }
    }

    int count_low() const {
        int low_count = 0;
        for(int i = 0; i < size;i++) {
            if(sats[i].is_low()) {
                low_count = low_count + 1;
            }
        }
        return low_count;
    }

    int charge_low(double amount) {
        int satellite_charged = 0;
        for(int i = 0; i < size; i++) {
            if(sats[i].is_low()) {
                sats[i].charge(5);
                satellite_charged = satellite_charged + 1;
            }
        }
        return satellite_charged;

    }
};


// private: Satellite sats[4]; and int size;
// constructor builds the ORBITAL fleet:
//   Falcon 6, Starlink 20, Dragon 18, Orion 75
// methods: print_all, count_low, charge_low(double amount)

int main() {
    // TODO: create a Fleet

    Fleet my_fleet;

    my_fleet.print_all();
    cout << "Low Satellites: " << my_fleet.count_low() << endl;
    // print_all and how many are low
    int rounds = 0;
    while(my_fleet.count_low()) {
        my_fleet.charge_low(5);
        rounds = rounds + 1;
    }
    cout << "Rounds: " << rounds << endl;
    my_fleet.print_all();
    // while any are low, charge them by 5 and count the rounds
    // print rounds, then print_all again

    return 0;
}

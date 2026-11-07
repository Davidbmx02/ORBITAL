// Nov 6 - Solo fleet decisions. Do not look at E0.
// Keep the provided class unchanged.
// Write two helper functions before main:
// 1. Count low satellites without modifying them; return the count.
// 2. Charge only low satellites by the supplied amount; return how many charged.
// In main, repeat charging by 5 while any satellite is low.
// Count and print the rounds, then print all final battery levels.

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

// TODO: write your two helper functions here.
double charge_low_satellites(Satellite fleet [], int size, double amount) {
    int low_count = 0;
    for (int i = 0; i < size; i++){
        if(fleet[i].is_low()) {
            low_count ++;
            fleet[i].charge(amount);
        }
    }
    return low_count;
}

int count_low_satellites(Satellite fleet [], int size) {
    int low_count = 0;
    for(int i = 0; i < size; i++) {
        if(fleet[i].is_low()) {
            low_count++;
        }
    }
    return low_count;
}


int main() {
    Satellite fleet[4] {
        Satellite("Falcon", 6),
        Satellite("Starlink", 20),
        Satellite("Dragon", 18),
        Satellite("Orion", 75)
    };

    // TODO: write the charging while loop and round counter.
    int low_count = count_low_satellites(fleet, 4);
    cout << "Low satellites: " << low_count << endl;
    // TODO: print total rounds and all final battery levels.

    int rounds = 0;
    while (count_low_satellites(fleet, 4) > 0) {
        int charged = charge_low_satellites(fleet, 4, 5);
        rounds++;
        cout << "Satellites charged: " << charged << endl;
    }
    
    cout << "Total rounds: " << rounds << endl;

    for (int i = 0; i < 4; i++) {
        fleet[i].print_status();
    }

    return 0;
}
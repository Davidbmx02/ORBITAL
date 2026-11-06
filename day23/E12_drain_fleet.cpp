// Short practice: drain every satellite in the fleet
// Same array idea as E11.
// Fleet: Falcon 50, Starlink 80, Dragon 20
// Print, then drain each by 15, then print again.
// Expect after drain: 35, 65, 5

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

    void drain(double amount) {
        battery = battery - amount;
        if (battery < 0) {
            battery = 0;
        }
    }
};

int main() {
    // TODO: create the fleet array
    Satellite fleet[3] {
        Satellite("Falcon", 50),
        Satellite("Starlink", 80),
        Satellite("Dragon", 20)
    };
    // print all, drain each by 15, print all again
    for(int i = 0; i < 3; i++){
        fleet[i].drain(15);
        fleet[i].print_status();
    }

    return 0;
}

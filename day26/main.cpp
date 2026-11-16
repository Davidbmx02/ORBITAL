#include <iostream>
#include "Fleet.h"
using namespace std;

int main() {
    Fleet my_fleet;

    my_fleet.print_all();
    cout << "Low Satellites: " << my_fleet.count_low() << endl;
    int rounds = 0;
    while(my_fleet.count_low()) {
        my_fleet.charge_low(5);
        rounds = rounds + 1;
    }
    cout << "Rounds: " << rounds << endl;
    my_fleet.print_all();

    return 0;
}

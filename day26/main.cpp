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

    Satellite comet("Comet", 50);
    comet.run_command("CHARGE 30");
    comet.print_status();
    comet.run_command("DRAIN 45");
    comet.print_status();

    return 0;
}

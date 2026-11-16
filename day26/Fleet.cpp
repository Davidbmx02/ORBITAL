#include <iostream>
#include "Fleet.h"
using namespace std;

void Fleet::print_all() const {
    for (int i = 0; i < size; i++) {
        sats[i].print_status();
    }

}

int Fleet::count_low() const {
    int count_low = 0;
    for (int i = 0; i < size; i++) {
        if(sats[i].is_low()){
            count_low = count_low + 1;
        }
    }
    return count_low;
}

int Fleet::charge_low(double amount) {
    int charged = 0;
    for (int i = 0; i < size; i++) {
        if(sats[i].is_low()) {
            sats[i].charge(amount);
            charged = charged + 1;
        }
    }
    return charged;
}

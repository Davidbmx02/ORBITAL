#pragma once
#include "Satellite.h"
using namespace std;

class Fleet{
private:
    Satellite sats[4];
    int size;

public:
    Fleet ()
        : sats {
            Satellite("Falcon", 6),
            Satellite("Starlink", 20),
            Satellite("Dragon", 18),
            Satellite("Orion", 75)
        }{
        size = 4;
    }

    void print_all() const;
    int count_low() const;
    int charge_low(double amount);
    

};

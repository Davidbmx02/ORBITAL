// ORBITAL V0.3: Fuel class (clase de combustible)
// Copy the IDEA of Battery, but write it yourself. Don't paste.
#include <iostream>
using namespace std;

// TODO 1: class Fuel {
class Fuel {
private:
    double kg;
public:
    Fuel (double startkg) {
        kg = startkg;
    }

    void refuel(double amount) {
        kg = kg + amount;
        if ( kg > 100) {
            kg = 100;
        }
    }
    void burn(double amount) {
        kg = kg - amount;
        if ( kg < 0) {
            kg = 0;
        }
    }

    bool isLow() const {
        return kg < 10;
    }

    double getKg() const {
        return kg;
    }
    
};
//   private:  double kg;
//   public:
//     constructor Fuel(double startKg)
//     void refuel(double amount)  -> add, but never above 100 (tope / cap)
//     void burn(double amount)    -> subtract, but never below 0 (piso / floor)
//     bool isLow() const          -> true if kg < 10
//     double getKg() const        -> returns kg
// };   <- remember the ;

int main() {

    Fuel f(50);
    for (int i = 1; i <= 6; i++) {
        f.burn(9);
        cout << "Maneuver " << i << ": "<< f.getKg() << " kg";
        if (f.isLow()) {
            cout << " LOW FUEL";
        }
        cout << endl;
    }
    // TODO 2: Fuel f(50);
    // TODO 3: 6 maneuvers (maniobras): each one burns 9 kg.
    //         After each burn print "Maneuver X: Y kg", and "LOW FUEL" if isLow().
    // Expected: 41, 32, 23, 14, 5 LOW FUEL, 0 LOW FUEL
    return 0;
}

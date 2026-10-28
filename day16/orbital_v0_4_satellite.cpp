// ORBITAL V0.4: Satellite struct (estructura) - a small fleet (flota)
// Write everything yourself. Reuse what you learned: struct, functions, & reference, array + loop.
//
// TODO 1: #include <iostream>, <string>, using namespace std
#include <iostream>
using namespace std;
#include <string>
// TODO 2: struct Satellite { string name; double fuel; double battery; };
struct Satellite{
    string name;
    double fuel;
    double battery;
};
    // TODO 3: void printSatellite(Satellite s)   -> "ORB-A | fuel: 60 kg | battery: 88 %"
    void printSatellite(Satellite s) {
        cout << s.name << " Fuel: " << s.fuel << " kg " << "Battery: " << s.battery << " %" << endl;
    }
    // TODO 4: void burnFuel(Satellite &s, double kg)   -> subtract kg, but never below 0 (floor / piso)
    void burnFuel (Satellite &s, double kg) {
        s.fuel = s.fuel - kg;
        if(s.fuel < 0) {
            s.fuel = 0;
        }
    }

// TODO 5: bool isLowFuel(Satellite s)   -> true if fuel < 10
    bool isLowFuel(Satellite s) {
        if(s.fuel < 10){
            return true;
        }
        return false;
    }
// TODO 6: main:    
    int main () {
//    Satellite fleet[3]:  ORB-A 60 kg 88 % | ORB-B 14 kg 52 % | ORB-C 8 kg 30 %
        Satellite fleet[3];
        fleet[0].name = "ORB-A";
        fleet[0].fuel = 60;
        fleet[0].battery = 88;
        fleet[1].name = "ORB-B";
        fleet[1].fuel = 14;
        fleet[1].battery = 52;
        fleet[2].name = "ORB-C";
        fleet[2].fuel = 8;
        fleet[2].battery = 30;
//    print the whole fleet with a loop
        for(int i = 0; i < 3; i++) {
            printSatellite(fleet[i]);
        } 
//    every satellite burns 5 kg (loop + burnFuel)
        for(int i =0; i < 3; i++) {
            burnFuel(fleet[i], 5);
            printSatellite(fleet[i]);
            if(isLowFuel(fleet[i])) {
            cout << " LOW FUEL" << endl;
        }
        }
//    print the fleet again; after each low one print "  LOW FUEL"
// Expected after burn:
//    ORB-A | fuel: 55 kg | battery: 88 %
//    ORB-B | fuel: 9 kg | battery: 52 %
//      LOW FUEL
//    ORB-C | fuel: 3 kg | battery: 30 %
//      LOW FUEL

    }


// Then: git add, commit "ORBITAL V0.4: Satellite struct fleet", push (from the ORBITAL folder!)

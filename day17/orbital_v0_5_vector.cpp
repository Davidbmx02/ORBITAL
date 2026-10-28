// ORBITAL V0.5: the fleet becomes a std::vector (branch vector-fleet)
// Started as a copy of V0.4. We change it TOGETHER, step by step.
// Write everything yourself. Reuse what you learned: struct, functions, & reference, array + loop.
//
// TODO 1: #include <iostream>, <string>, using namespace std
#include <iostream>
#include <string>
#include <vector>
// TODO 2: struct Satellite { string name; double fuel; double battery; };
struct Satellite{
    std::string name;
    double fuel;
    double battery;
};
    // TODO 3: void printSatellite(Satellite s)   -> "ORB-A | fuel: 60 kg | battery: 88 %"
    void printSatellite(Satellite s) {
        std::cout << s.name << " Fuel: " << s.fuel << " kg " << "Battery: " << s.battery << " %" << "\n";
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

    bool isLowBattery(Satellite s) {
        if(s.battery < 40){
            return true;
        }
        return false;
    }
// TODO 6: main:    
    int main () {
//    Satellite fleet[3]:  ORB-A 60 kg 88 % | ORB-B 14 kg 52 % | ORB-C 8 kg 30 %

        std::vector<Satellite> fleet;

        fleet.push_back({"ORB-A", 60, 88});
        fleet.push_back({"ORB-B", 14, 52});
        fleet.push_back({"ORB-C", 8, 30});
        fleet.push_back({"ORB-D", 25, 35});

//    print the whole fleet with a loop
        for(int i = 0; i < fleet.size(); i++) {
            printSatellite(fleet[i]);
        } 
//    every satellite burns 5 kg (loop + burnFuel)
        for(int i =0; i < fleet.size(); i++) {
            burnFuel(fleet[i], 5);
            printSatellite(fleet[i]);
            if(isLowFuel(fleet[i])) {
            std::cout << " LOW FUEL" << "\n";
            }
            if(isLowBattery(fleet[i])) {
            std::cout << " LOW BATTERY" << "\n";
            }
            
        }
 }
//    print the fleet again; after each low one print "  LOW FUEL"
// Expected after burn:
//    ORB-A | fuel: 55 kg | battery: 88 %
//    ORB-B | fuel: 9 kg | battery: 52 %
//      LOW FUEL
//    ORB-C | fuel: 3 kg | battery: 30 %
//      LOW FUEL



// Then: git add, commit "ORBITAL V0.4: Satellite struct fleet", push (from the ORBITAL folder!)


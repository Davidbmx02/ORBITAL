// Day 21 - Full review: build one program with everything, little by little
// Step 1: includes + struct Satellite
// Day 21 - reviewed and pushed
#include <iostream>
#include <string>
#include <vector>

struct Satellite {
    std::string name;
    int fuel;
    int battery;
};


// const & = read only, no copy
void printSatellite(const Satellite& s) {
    std::cout << s.name << " Fuel: " << s.fuel << " kg Battery: " << s.battery << " %\n";
}

// returns how many satellites have low fuel
int countLowFuel(const std::vector<Satellite>& fleet) {
    int count = 0;
    for (int i = 0; i < fleet.size(); i++) {
        if (fleet[i].fuel < 10) {
            count++;
        }
    }
    return count;
}
// returns the index of the satellite or -1 if not found
int findSatellite(const std::vector<Satellite>& fleet, std::string name) {
    for (int i = 0; i < fleet.size(); i++) {
        if (fleet[i].name == name) {
            return i;
        }
    }
    return -1;
}
// returns only the satellite with fuel < 10
std::vector<Satellite> getLowFuel(const std::vector<Satellite>& fleet) {
    std::vector<Satellite> result;
        for (int i = 0; i < fleet.size(); i++) {
        if(fleet[i].fuel < 10) {
            result.push_back(fleet[i]);
        }
    }
    return result;
}

void refuel(Satellite& s, int kg) {
    s.fuel = s.fuel + kg;
}


int main () {

    std::vector<Satellite> fleet = {
        {"ORB-A", 40, 80}, // index 0
        {"ORB-B", 9, 52}, // index 1
        {"ORB-C", 3, 30}  // index 2
    };
    
   
    for(int i = 0; i < fleet.size(); i++) {
        printSatellite(fleet[i]);
    }

    int low = countLowFuel(fleet);
    std::cout << "Low fuel: " << low << "\n";

    int idx = findSatellite(fleet, "ORB-C");
    if (idx == -1) {
        std::cout << "ORB-C not found\n";
    } else {
        std::cout << "ORB-C found at index " << idx << "\n";
    }

    int idx2 = findSatellite(fleet, "ORB-X");
    if(idx2 == -1) {
        std::cout << "ORB-X not found\n";
    } else {
        std::cout << "ORB-X found at index " << idx2 << "\n";
    }
    
    std::vector<Satellite> lowList = getLowFuel(fleet);
    std::cout << " --- LOW FUEL REPORT ---\n";
    std::cout << "Satellites to refuel: " << lowList.size() << "\n";


    for(int i = 0; i < lowList.size(); i++) {
        printSatellite(lowList[i]);
    }

    refuel(fleet[1], 20);
    printSatellite(fleet[1]);

    return 0;

}



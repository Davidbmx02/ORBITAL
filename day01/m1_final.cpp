#include <iostream>
using namespace std;
#include <string>

int main (){
    string satellite_name = "ORBITAL-1";
    char mode = 'N';
    int timestamp_sec = 45296;
    double bus_voltage_v = 28.4;
    double battery_charge_pct = 87.5;
    double battery_capacity_wh = 100.0;
    double obc_temperature_c = 21.5;
    double solar_panel_current_a = 3.2;
    bool in_eclipse = false;

    cout << "Satellite: " << satellite_name << endl;
    cout << "Mode: " << mode << endl;
    cout << "Timestamp: " << timestamp_sec << " s" << endl;
    cout << "Bus voltage: " << bus_voltage_v << " V" << endl;
    cout << "Battery: " << battery_charge_pct << " %" << endl;
    cout << "Battery capacity: " << battery_capacity_wh << " Wh" << endl;
    cout << "OBC temperature: " << obc_temperature_c << " C" << endl;
    cout << "Solar current: " << solar_panel_current_a << " A" << endl;
    cout << "In eclipse: " << boolalpha << in_eclipse << endl;
}

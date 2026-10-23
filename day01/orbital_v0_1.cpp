// ORBITAL INTELLIGENCE V0.1 (Day 1 slice): one telemetry snapshot
// Only Day 1 topics: variables, types, constexpr, arithmetic, / and %, comparisons stored in bool.
#include <iostream>
#include <string>
using namespace std;

int main() {
    // ---- Limits and constants (M2, M4) ----
    constexpr double kMinBusVoltageV = 24.0;
    constexpr double kMaxObcTempC = 85.0;
    constexpr double kMinBatteryPct = 20.0;
    constexpr double kCelsiusToKelvin = 273.15;
    constexpr double kPercentScale = 100.0;
    constexpr int kSecondsPerMinute = 60;

    // ---- M1: one telemetry snapshot ----
    string satellite_name = "ORBITAL-1";
    char mode = 'N';                    // N = nominal
    int timestamp_s = 45296;            // seconds since start of the mission
    double bus_voltage_v = 28.4;
    double battery_percent = 87.5;
    double battery_capacity_wh = 100.0;
    double obc_temp_c = 21.5;
    double solar_current_a = 3.2;
    bool is_in_eclipse = false;

    // ---- M2: derived values ----
    double battery_energy_wh = battery_capacity_wh * battery_percent / kPercentScale;
    double solar_power_w = bus_voltage_v * solar_current_a;
    double obc_temp_k = obc_temp_c + kCelsiusToKelvin;

    // ---- M3: ground station pass time ----
    int pass_duration_s = 587;          // how long the ground station can see the satellite
    int pass_min = pass_duration_s / kSecondsPerMinute;
    int pass_sec = pass_duration_s % kSecondsPerMinute;

    // ---- M4: limit checks (a comparison gives a bool) ----
    bool voltage_ok = bus_voltage_v >= kMinBusVoltageV;
    bool temp_ok = obc_temp_c <= kMaxObcTempC;
    bool battery_ok = battery_percent >= kMinBatteryPct;

    // ---- M4: telemetry report ----
    cout << boolalpha;
    cout << "===== ORBITAL INTELLIGENCE V0.1 =====" << endl;
    cout << "Satellite        : " << satellite_name << endl;
    cout << "Mode             : " << mode << endl;
    cout << "Timestamp        : " << timestamp_s << " s" << endl;
    cout << "In eclipse       : " << is_in_eclipse << endl;
    cout << "--- Power (EPS) ---" << endl;
    cout << "Bus voltage      : " << bus_voltage_v << " V" << endl;
    cout << "Solar current    : " << solar_current_a << " A" << endl;
    cout << "Solar power      : " << solar_power_w << " W" << endl;
    cout << "Battery          : " << battery_percent << " %" << endl;
    cout << "Battery capacity : " << battery_capacity_wh << " Wh" << endl;
    cout << "Battery energy   : " << battery_energy_wh << " Wh" << endl;
    cout << "--- Thermal (OBC) ---" << endl;
    cout << "OBC temperature  : " << obc_temp_c << " C = " << obc_temp_k << " K" << endl;
    cout << "--- Ground pass ---" << endl;
    cout << "Pass duration    : " << pass_duration_s << " s = "
         << pass_min << " min " << pass_sec << " s" << endl;
    cout << "--- Checks ---" << endl;
    cout << "voltage_ok (>= " << kMinBusVoltageV << " V) : " << voltage_ok << endl;
    cout << "temp_ok    (<= " << kMaxObcTempC << " C) : " << temp_ok << endl;
    cout << "battery_ok (>= " << kMinBatteryPct << " %) : " << battery_ok << endl;
    cout << "=====================================" << endl;
    return 0;
}

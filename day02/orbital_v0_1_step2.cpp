#include <iostream>
#include <string>
using namespace std;

int main() {
    // ---- Constants (known at compile time) ----
    constexpr double kPercentScale = 100.0;
    constexpr double kCelsiusToKelvin = 273.15;
    constexpr int kSecondsPerMinute = 60;
    // CRITICAL limits (step 1)
    constexpr double kMinBusVoltageV = 24.0;
    constexpr double kMaxObcTempC = 85.0;
    constexpr double kMinBatteryPct = 20.0;
    // WARNING limits (step 2)
    constexpr double kWarningBusVoltageV = 26.0;
    constexpr double kWarningObcTempC = 70.0;
    constexpr double kWarningBatteryPct = 40.0;

    // ---- Snapshot ----
    string satellite_name = "ORBITAL-1";
    char mode = 'N';
    int timestamp_sec = 45296;
    double bus_voltage_v = 28.4;
    double battery_charge_pct = 0.0;
    double battery_capacity_wh = 100.0;
    double obc_temperature_c = 0.0;
    double solar_panel_current_a = 3.2;
    bool in_eclipse = false;
    int pass_duration_s = 587;

    // ---- M1: read two values at run time ----
    cout << "Battery (%) and OBC temp (C): ";
    cin >> battery_charge_pct >> obc_temperature_c;

    // ---- Derived values (after cin!) ----
    double battery_energy_wh = battery_capacity_wh * battery_charge_pct / kPercentScale;
    double solar_power_w = bus_voltage_v * solar_panel_current_a;
    double obc_temp_k = obc_temperature_c + kCelsiusToKelvin;
    int pass_min = pass_duration_s / kSecondsPerMinute;
    int pass_sec = pass_duration_s % kSecondsPerMinute;

    // ---- Step 1 checks ----
    bool voltage_ok = bus_voltage_v >= kMinBusVoltageV;
    bool temp_ok = obc_temperature_c <= kMaxObcTempC;
    bool battery_ok = battery_charge_pct >= kMinBatteryPct;

    // ---- M2: EPS statuses ----
    string battery_status = "NOMINAL";
    if (battery_charge_pct < kMinBatteryPct) {
        battery_status = "CRITICAL";
    } else if (battery_charge_pct < kWarningBatteryPct) {
        battery_status = "WARNING";
    } else {
        battery_status = "NOMINAL";
    }

    string voltage_status = "NOMINAL";
    if (bus_voltage_v < kMinBusVoltageV) {
        voltage_status = "CRITICAL";
    } else if (bus_voltage_v < kWarningBusVoltageV) {
        voltage_status = "WARNING";
    } else {
        voltage_status = "NOMINAL";
    }

    // ---- M3: thermal status + system status ----
    string thermal_status = "NOMINAL";
    if (obc_temperature_c > kMaxObcTempC) {
        thermal_status = "CRITICAL";
    } else if (obc_temperature_c > kWarningObcTempC) {
        thermal_status = "WARNING";
    } else {
        thermal_status = "NOMINAL";
    }

    bool any_critical = !voltage_ok || !temp_ok || !battery_ok;
    bool any_warning = bus_voltage_v < kWarningBusVoltageV || obc_temperature_c > kWarningObcTempC ||
                       battery_charge_pct < kWarningBatteryPct;

    string system_status = "NOMINAL";
    if (any_critical) {
        system_status = "CRITICAL";
    } else if (any_warning) {
        system_status = "WARNING";
    } else {
        system_status = "NOMINAL";
    }

    // ---- M4: action ----
    string action = "none";
    bool payload_on = true;
    if (system_status == "CRITICAL") {
        mode = 'S';
        payload_on = false;
        action = "SAFE MODE: payload OFF, keep EPS, OBC and COMMS only";
    } else if (system_status == "WARNING") {
        action = "reduce load and monitor";
    } else {
        action = "none";
    }

    // ---- Report ----
    cout << "===== ORBITAL INTELLIGENCE V0.1 =====" << endl;
    cout << "Satellite        : " << satellite_name << endl;
    cout << "Mode             : " << mode << endl;
    cout << "Timestamp        : " << timestamp_sec << " s" << endl;
    cout << "In eclipse       : " << boolalpha << in_eclipse << endl;
    cout << "--- Power (EPS) ---" << endl;
    cout << "Bus voltage      : " << bus_voltage_v << " V" << endl;
    cout << "Solar current    : " << solar_panel_current_a << " A" << endl;
    cout << "Solar power      : " << solar_power_w << " W" << endl;
    cout << "Battery          : " << battery_charge_pct << " %" << endl;
    cout << "Battery capacity : " << battery_capacity_wh << " Wh" << endl;
    cout << "Battery energy   : " << battery_energy_wh << " Wh" << endl;
    cout << "--- Thermal (OBC) ---" << endl;
    cout << "OBC temperature  : " << obc_temperature_c << " C = " << obc_temp_k << " K" << endl;
    cout << "--- Ground pass ---" << endl;
    cout << "Pass duration    : " << pass_duration_s << " s = " << pass_min << " min " << pass_sec << " s" << endl;
    cout << "--- Checks ---" << endl;
    cout << "voltage_ok (>= " << kMinBusVoltageV << " V) : " << voltage_ok << endl;
    cout << "temp_ok    (<= " << kMaxObcTempC << " C) : " << temp_ok << endl;
    cout << "battery_ok (>= " << kMinBatteryPct << " %) : " << battery_ok << endl;
    cout << "--- Status ---" << endl;
    cout << "Battery (EPS)    : " << battery_status << endl;
    cout << "Voltage (EPS)    : " << voltage_status << endl;
    cout << "Thermal (OBC)    : " << thermal_status << endl;
    cout << "SYSTEM STATUS    : " << system_status << endl;
    cout << "Action           : " << action << endl;
    cout << "Payload ON       : " << payload_on << endl;
    cout << "=====================================" << endl;
    return 0;
}

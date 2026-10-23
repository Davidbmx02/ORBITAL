// ORBITAL V0.1 - day05: snapshots until a stop value (valor de parada)
//
// Day04 read EXACTLY 5 OBC temps. Real telemetry (telemetria) doesn't know
// how many readings will come, so now we read until the operator types -999.
//
// For each snapshot: read OBC temp (C).
// Track: count, min, max, average, warning_count (>70 and <=85), critical_count (>85)
//
// After the loop (after! not inside):
//   if count > 0:
//      print Snapshots, Min, Max, Average, Warning, Critical
//      SYSTEM STATUS (old topic: if / else if / else):
//         critical_count > 0  -> "STATUS: SAFE MODE"   (modo seguro)
//         warning_count  > 0  -> "STATUS: WATCH"       (vigilar)
//         otherwise           -> "STATUS: NOMINAL"     (normal)
//   else:
//      "No telemetry received"
//
// Test 1: 40 72 90 65 88 -999 -> 5 snapshots, Min 40, Max 90, Avg 71, W 1, C 2, SAFE MODE
// Test 2: 50 75 60 -999       -> 3 snapshots, Min 50, Max 75, Avg 61.6667, W 1, C 0, WATCH
// Test 3: -999                -> No telemetry received

#include <iostream>
using namespace std;

int main() {
    constexpr double kWarningObcTempC = 70.0;
    constexpr double kMaxObcTempC = 85.0;
    constexpr double kSentinel = -999.0;
    double temp_c;
    cout << "Temperature: ";
    cin >> temp_c;
    double min_temp = temp_c;
    double max_temp = temp_c;
    int count = 0;
    int warning_count = 0;
    int critical_count =0;
    double sum_temp_c = 0;

    // Your code here (you already did this shape in E0_sentinel_full!)
    while(temp_c != kSentinel){

        if(temp_c > max_temp){
            max_temp = temp_c;
        }
        if(temp_c < min_temp){
            min_temp = temp_c;
        }

        if(temp_c > kMaxObcTempC){
            critical_count = critical_count + 1;
        }
        else if(temp_c > kWarningObcTempC){
            warning_count = warning_count + 1;
        }
        sum_temp_c = sum_temp_c + temp_c;
        count = count + 1;
        cout << "Temperature: ";
        cin >> temp_c;

    }

    if (count > 0){
        double average = sum_temp_c / count;
        cout << "Average: " << average << endl;
        cout << "Snapshots: " << count << endl;
        cout << "Min: " << min_temp << endl;
        cout << "Max: " << max_temp << endl;
        cout << "Warning: " << warning_count << endl;
        cout << "Critical: " << critical_count << endl;
        if(critical_count > 0){
            cout << "STATUS: SAFE MODE" << endl;
        }else if(warning_count > 0){
            cout << "STATUS: WATCH" << endl;
        }else{
            cout << "STATUS: NOMINAL" << endl;
        }
    }
    else{
        cout << " No telemetry received";
    }
    return 0;
}
// Test 1: 40 72 90 65 88 -999 -> 5 snapshots, Min 40, Max 90, Avg 71, W 1, C 2, SAFE MODE
// Test 2: 50 75 60 -999       -> 3 snapshots, Min 50, Max 75, Avg 61.6667, W 1, C 0, WATCH
// Test 3: -999         // After the loop (after! not inside):
//   if count > 0:
//      print Snapshots, Min, Max, Average, Warning, Critical
//      SYSTEM STATUS (old topic: if / else if / else):
//         critical_count > 0  -> "STATUS: SAFE MODE"   (modo seguro)
//         warning_count  > 0  -> "STATUS: WATCH"       (vigilar)
//         otherwise           -> "STATUS: NOMINAL"     (normal)
//   else:
//      "No telemetry received"
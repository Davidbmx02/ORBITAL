// ORBITAL V0.1 - Day 4: telemetry over several snapshots
// Uses ONLY today's ideas: loop + accumulators + min/max
//
// STEP 1 (now): read 5 OBC temperatures (C), one per snapshot.
//   Print: Min, Max, Average, how many WARNING (> 70), how many CRITICAL (> 85)
//   Test: 40 72 90 65 88 -> Min 40, Max 90, Average 71, Warning 1, Critical 2
//
// STEP 2 (later): add battery % per snapshot

#include <iostream>
using namespace std;

int main() {
    constexpr double kWarningObcTempC = 70.0;
    constexpr double kMaxObcTempC = 85.0;
    constexpr int kNumSnapshots = 5;
    double obc_temp_c;
    cout << "Temp 1:";
    cin >> obc_temp_c;            // current reading
    double min_temp_c = obc_temp_c;      // lowest so far
    double max_temp_c = obc_temp_c;        // highest so far
    double sum_temp_c = obc_temp_c;        // total of all readings
    int count = 1;            // how many readings
    int warning_count = 0;    // how many WARNING
    int critical_count = 0;   // how many CRITICAL

    if (obc_temp_c > kMaxObcTempC){
        critical_count = critical_count + 1;
    }else if(obc_temp_c > kWarningObcTempC){
        warning_count = warning_count +1;
    }

    for(int i = 2; i <= kNumSnapshots; i++){
        cout << "Temp " << i << ": ";
        cin >> obc_temp_c;

        sum_temp_c = sum_temp_c + obc_temp_c;
        count = count + 1;

        if(obc_temp_c > max_temp_c){
            max_temp_c = obc_temp_c;
        }
        if(obc_temp_c < min_temp_c){
            min_temp_c = obc_temp_c;
        }

        if (obc_temp_c > kMaxObcTempC){
        critical_count = critical_count + 1;
        }else if(obc_temp_c > kWarningObcTempC){
        warning_count = warning_count +1;
    }

    }

    cout << "Min: " << min_temp_c << endl;
    cout << "Max: " << max_temp_c << endl;
    cout << "Average: " << static_cast<double>(sum_temp_c) / count << endl;
    cout << "Warning: " << warning_count << endl;
    cout << "Critical: " << critical_count << endl;

    // write your code here

    return 0;
}

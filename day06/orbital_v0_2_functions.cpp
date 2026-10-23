// ORBITAL V0.1 - day06: same program as day05, organized with FUNCTIONS
//
// Your day05 code is copied below. It already works. Now REFACTOR it
// (reorganizar sin cambiar lo que hace): same output, cleaner code.
//
// Write these functions ABOVE main, then USE them in main:
//   1. bool is_critical(double temp_c)          -> temp_c > kMaxObcTempC
//   2. bool is_warning(double temp_c)           -> temp_c > kWarningObcTempC && !is_critical(temp_c)

//
// Constants must move ABOVE the functions (outside main), so the functions can see them (scope!).
//
// Same 3 tests as day05 must still pass:
// Test 1: 40 72 90 65 88 -999 -> Avg 71, W 1, C 2, SAFE MODE
// Test 2: 50 75 60 -999       -> Avg 61.6667, W 1, C 0, WATCH
// Test 3: -999                -> No telemetry received

#include <iostream>
using namespace std;

constexpr double kMaxObcTempC = 85.0;
constexpr double kWarningObcTempC = 70.0;
constexpr double kSentinel = -999.0;


//   1. bool is_critical(double temp_c)          -> temp_c > kMaxObcTempC
bool is_critical(double temp_c){
    return temp_c > kMaxObcTempC;
}
//   2. bool is_warning(double temp_c)           -> temp_c > kWarningObcTempC && !is_critical(temp_c)
bool is_warning(double temp_c){
    return temp_c > kWarningObcTempC && !is_critical(temp_c);
}
//   3. double average(double sum, int count)    -> sum / count
double average(double sum, int count){
    return sum / count;
}
//   4. void print_system_status(int warning_count, int critical_count)
//         -> prints SAFE MODE / WATCH / NOMINAL (move that if/else if/else here)
void print_system_status(int warning_counts, int critical_counts){
    if(critical_counts > 0){
        cout <<"STATUS: SAFE MODE" << endl;
    }
    else if(warning_counts > 0){
        cout << "STATUS: WATCH" << endl;
    }
    else{
        cout << "STATUS: NOMINAL" << endl;
    }
}



int main() {
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

        if(is_critical(temp_c)){
            critical_count = critical_count + 1;
        }
        else if(is_warning(temp_c)){
            warning_count = warning_count + 1;
        }

        sum_temp_c = sum_temp_c + temp_c;
        count = count + 1;
        cout << "Temperature: ";
        cin >> temp_c;

    }

    if (count > 0){
        cout << "Average: " << average(sum_temp_c, count) << endl;
        cout << "Snapshots: " << count << endl;
        cout << "Min: " << min_temp << endl;
        cout << "Max: " << max_temp << endl;
        cout << "Warning: " << warning_count << endl;
        cout << "Critical: " << critical_count << endl;
        print_system_status(warning_count, critical_count);
    }
    else{
        cout << " No telemetry received";
    }
    return 0;
}

// ORBITAL V0.3: telemetry array (telemetría)
// A satellite sends temperature readings (lecturas). We store 10 of them in an array.
#include <iostream>
using namespace std;

// TODO 1: void printReadings(double arr[], int size) -> prints "Reading 1: 21.5 C" ... one per line
void printReadings(double arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << "Reading " << i+1 << ": " << arr[i] << " C" << endl;
    }

}
// TODO 2: double sumReadings(double arr[], int size) -> returns the sum
double sumReadings(double arr[], int size) {
    double sum = 0;
    for(int i = 0; i < size; i++) {
        sum = sum + arr[i];
    }
    return sum;
}
// TODO 3: double averageReadings(double arr[], int size) -> returns sum / size (reuse sumReadings!)
double averageReadings(double arr[], int size) {
    return sumReadings(arr, size) / size;
}
// TODO 8:  double maxReading(double arr[], int size)  -> hottest value   (start from arr[0]!)
double maxReading(double arr[], int size) {
    double max  = arr[0];
    for (int i = 0; i < size; i++){
        if ( arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
// TODO 9:  double minReading(double arr[], int size)  -> coldest value
double minReading(double arr[], int size) {
    double min = arr[0];
    for (int i = 0; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
// TODO 10: int findReading(double arr[], int size, double target) -> index or -1
int findReading(double arr[], int size, double target) {
    for(int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void sortReadings(double arr[], int size) {
    for(int pass = 0; pass < size; pass++) {
        for(int i = 0; i < size - 1; i++) {
            if(arr[i] > arr[i+1]) {
                double temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}



int main() {
    double temps[10] = {21.5, 22.0, 23.4, 25.1, 27.8, 30.2, 28.6, 26.0, 24.3, 22.9};
    // TODO 4: call printReadings
    printReadings(temps, 10);
    // TODO 5: print "Sum: " + sumReadings          expected: 251.8
    cout << "Sum: " << sumReadings(temps, 10) << endl;
    // TODO 6: print "Average: " + averageReadings  expected: 25.18
    double avg = averageReadings(temps,10);
    cout << "Average: " << avg << endl;
    // TODO 7: if average > 25, print "THERMAL WATCH", else "THERMAL NOMINAL"   expected: THERMAL WATCH
    if(avg > 25){
        cout << "THERMAL WATCH" << endl;
    }
    else {
        cout << "THERMAL NOMINAL" << endl;
    }
    double max = maxReading(temps,10);
    cout << "Max: " << max << " C" << endl;
    cout << "Min: " << minReading(temps, 10) << " C" << endl;
    
    int index = findReading(temps, 10,26);
    if (index != -1 ) cout << "Found 26 at reading " << index + 1 << endl;
    if (findReading(temps, 10, 35) == -1) cout << "35 not found" << endl;

    if(max > 30){
        cout << "OVERHEAT ALERT" << endl;
    }

    
    sortReadings(temps,10);
    cout << "Sorted:" << endl;
    printReadings(temps, 10);
    cout << endl;




    return 0;
}

// ===== PART 2 (Oct 27 content, done early) =====
// TODO 11: in main print:
//   Max: 30.2 C
//   Min: 21.5 C
//   26 found at reading 8      (index 7 + 1)
//   35 not found
// TODO 12: if max > 30, print "OVERHEAT ALERT"   expected: OVERHEAT ALERT

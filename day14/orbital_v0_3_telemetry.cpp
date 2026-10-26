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

int main() {
    double temps[10] = {21.5, 22.0, 23.4, 25.1, 27.8, 30.2, 28.6, 26.0, 24.3, 22.9};
    // TODO 4: call printReadings
    printReadings(temps, 10);
    // TODO 5: print "Sum: " + sumReadings          expected: 251.8
    cout << "Sum: " << sumReadings(temps, 10) << endl;
    // TODO 6: print "Average: " + averageReadings  expected: 25.18
    double avg = averageReadings(temps,10);
    cout << "Average: " << avg << endl;
    if(avg > 25){
        cout << "THERMAL WATCH" << endl;
    }
    else {
        cout << "THERMAL NOMINAL" << endl;
    }


    // TODO 7: if average > 25, print "THERMAL WATCH", else "THERMAL NOMINAL"   expected: THERMAL WATCH
    return 0;
}

// ORBITAL day13 - Rebuild Battery ALONE (don't look at day10)
// class Battery:
//   - private: double percent
//   - constructor(double start)
//   - void charge(double amount)   -> goes up, cap (maximo) 100
//   - void drain(double amount)    -> goes down, floor (minimo) 0
//   - bool isLow() const           -> true if percent < 20
//   - double getPercent() const
// main: Battery starting at 50%. Simulate 3 orbits of 90 minutes:
//   minutes 1-60 (sun / sol): charge(0.6) every minute
//   minutes 61-90 (shadow / sombra): drain(0.3) every minute
//   Print the percent at the end of each orbit; show LOW POWER if isLow().

#include <iostream>
using namespace std;

// your Battery class here
class Battery {
private:
    double percent;
public:

    Battery (double amount) {
        percent = amount;
    }

    void charge(double amount) {
        percent = percent + amount;
        if (percent > 100) {
            percent = 100;
        }
    }

    void drain(double amount) {
        percent = percent - amount;
        if ( percent < 0) {
            percent = 0;
        }
    }

    bool isLow() const{
        return percent < 20;
    }

    double getPercent() const {
        return percent;
    }

};

int main() {
    // your code here
    Battery b(50);
    for (int orbit = 1; orbit <=3; orbit++) {
        for (int minute = 1; minute <= 90; minute++) {
            if (minute <= 60) {
                b.charge(0.6);
            }else{
                b.drain(0.3);
            }
        }
        cout << "Percent: " << b.getPercent() << endl;
        if(b.isLow()) cout << "LOW POWER" << endl;
    }


    return 0;
}

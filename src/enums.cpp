#include <iostream>
using namespace std;

// Monday Wednesday onward is now 4, 5, 6...
enum day_of_week {MO = 1, TU = 3, WE, TH, FR, SA, SU};

string get_day(day_of_week);

int main() {
    // Prints out the index of the item
    day_of_week d = SU;
    cout << d << endl;

    // Allow us to get the value quickly without a declaration
    cout << day_of_week(SA) << endl;

    // Switch statements with enums
    cout << get_day(day_of_week(2)) << endl;
    cout << get_day(d) << endl;

    return 0;
} 

string get_day(day_of_week d) {
    switch (d) {
        case MO: 
            return "Monday";
        case TU:
            return "Tuesday";
        case WE: 
            return "Wednesdsay";
        case TH: 
            return "Thursday";
        case FR:
            return "Friday";
        case SA: 
            return "Saturday";
        case SU: 
            return "Sunday";
        default:
            return "Invalid day!";
    }
}
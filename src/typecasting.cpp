#include <iostream> 
using namespace std;

int main() {
    /* You can typecast using (type) operator */
    double var = 5.5;
    cout << "5.5 cast to int: " << (int) var << endl;

    /* Sometimes this may be useful for you if you need to collect additional 
    information from a calculation than was originally available. Note that 
    the value of 'k' is being IMPLICITLY cast to match 'j's type of double. */
    int k = 5;
    int j = 4;
    cout << "Without casting: " << j / k << endl;
    // C explicit casting
    cout << "With casting: " << (double) j / k << endl;

    /* More examples of implicit casting. We lose information in 'y' since we 
    are defining a smaller type than x. This may lead to unexpected results, as 
    the type will interpret the remaining information in its own way. */
    int x = 10000000;
    short y = x; 
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;

    /* More examples of explicit casting: */
    // C way 
    cout << "5.5 cast to int: " << int(var) << endl;
    // C++ way using a generic function
    cout << "5.5 cast to int: " << static_cast<int>(var) << endl;
    // Casting a char to its ASCII representation 
    cout << "'k' to ASCII: " << (int) 'k' << endl;

    return 0;
}
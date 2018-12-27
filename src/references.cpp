#include <iostream>
using namespace std;

int main() {
    // Get a reference to num
    int num = 12;
    int &num_ref = num;

    // Both have the same value
    cout << num << endl;
    cout << num_ref << endl;

    // Both have the same address in memory
    cout << &num << endl;
    cout << &num_ref << endl;

    num_ref = 45;

    // Both now have 45
    cout << num << endl;
    cout << num_ref << endl;

    int k = 435;
    num_ref = k;

    // Both now have the value of k
    cout << num << endl;
    cout << num_ref << endl;

    // Can't reassign reference variables (wont' compile)
    // &num_ref = k;

    // Essentially, references are just constant pointers
    return 0;
}
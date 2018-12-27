#include <iostream>

using namespace std;

int main() {
    // Init the array with 0's
    int bi_array[3][4] = {0};

    // Get addresses
    cout << "Address of array is " << bi_array << endl;
    cout << "Address of first row " << &bi_array[0] << endl;
    cout << "Address of first row first element " << &bi_array[0][0] << endl;
    cout << "Address of first row second element " << &bi_array[0][1] << endl;
    cout << "Address of second row " << &bi_array[1] << endl;

    // Get sizes
    cout << "Size of each row " << sizeof(bi_array[0]) << endl;
    cout << "Size of array " << sizeof(bi_array) << " bytes" << endl;
    return 0;
} 
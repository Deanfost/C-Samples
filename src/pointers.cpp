#include <iostream>
using namespace std;

int main() {
    int arr[5] = {0, 1, 2, 3, 4};

    // Remember that we can use the arr name as the pointer to first element
    int *p = arr;
    cout << *p << endl;

    // Grab the address of the 3rd item in the array
    p = &arr[2];
    cout << *p << endl;

    // We can combine unary operators:
    // Increment the value in the address
    cout << ++*p << endl;

    // Increment the pointer and then dereference
    cout << *++p << endl;

    // Dereference the pointer and then increment
    cout << *p++ << endl;
    cout << *p << endl;

    return 0;
}
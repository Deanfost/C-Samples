#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
    int amount;

    cout << "How many integers would you like to store?" << endl;
    cin >> amount;

    int *arr = new (nothrow) int[amount];

    if (arr != NULL) {
        cout << "Address of array: " << arr << endl;

        for (int i = 0; i < amount; i++) {
            cout << "Enter a value: " << endl;
            int value;
            cin >> value;
            arr[i] = value;
        }

        for (int i = 0; i < amount; i++) {
            cout << "Value at index " << i << ": " << arr[i] << endl;
        }
    } else {
        cout << "Not enough memory." << endl;
    }

    return 0;
}

/* Note that above might not work in terms of the memory handling, depending
on the machine you're using. You may still end up getting an address, and things
will start to break. */

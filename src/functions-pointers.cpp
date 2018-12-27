#include <iostream>
using namespace std;

// We can also say int * as the param - same thing
void pointer_func(int []); 
void fixed_func(int *, int);

int main() {
    int ints[] = {1, 2, 3, 4, 5};
    /* Notice that we can use 'sizeof()' to find the size of arrays */
    cout << "Bytes allocated: " << sizeof(ints) << endl;
    cout << "Num of elements " << sizeof(ints) / sizeof(ints[0]) << endl;

    pointer_func(ints);
    fixed_func(ints, sizeof(ints) / sizeof(ints[0]));
    return 0;
}

void pointer_func(int arr[]) {
    // Won't even compile
    // cout << "Bytes allocated: " << sizeof(arr) << endl;
}

/* We NEED to pass in the size with the array since we only have the pointer to
the first element, with all size info gone */
void fixed_func(int *arr, int size) {
    cout << "Bytes allcoated: " << size * sizeof(arr[0]) << endl;
    cout << "Num of elements: " << size << endl;
}
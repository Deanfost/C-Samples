#include <iostream>
using namespace std;

int main() {
    string s = "hello";

    // Accessible using indices of array in string
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
    }
    cout << endl;

    // Traditional string representation
    char s_arr[5] = "1234"; // Null-terminated
    cout << s_arr << endl;
    // Can't do s_arr = "395394893759357"; b/c of length constraints

    // Pointer arithmetic with strings
    char *p = s_arr;
    cout << *p << endl;
    cout << *p++ << endl;
    cout << *p << endl;
    p += 2;
    cout << *p++ << endl;
    cout << *p << endl; // Null character 

    // Can't do string s_arr2 = s_arr;

    /* If you grab a char pointer to a string object, you can't use it to modify
    the string */ 
    const char *tp = s.c_str();
    cout << *tp << endl;
    cout << tp[2] << endl;
    // tp[2] = 'd'; won't compile

    /* HOWEVER, if you use a char array, you CAN modify the values */
    char s2[] = "This is a string";
    s2[2] = 'k';
    cout << s2 << endl;

    /* This is because the char pointer returned by 'c_str()' actually points
    to the internal array used by the string object (and I guess they didn't 
    want you to be able to modify the array like that). */

    /* IMPORTANT NOTE: If you dynamically create a char array, you CAN'T assign a
    string literal to it, otherwise you won't be able to properly free it. */
    char *dynamic_array = new char[50];
    dynamic_array[0] = 'k';
    dynamic_array[1] = '\0';
    cout << dynamic_array << endl;
    delete [] dynamic_array; // Note that you can free entire arrays as well

    return 0;
}
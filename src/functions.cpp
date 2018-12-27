#include <iostream>
using namespace std;

void enter_input();
int is_number(string);

int main() {
    while (true) {
        enter_input();
    }
    return 0;
}

/* Grabs input from stdin, checks if it is a number */
void enter_input() {
    string input;
    cout << "Enter a number " << endl;
    cin >> input;
    is_number(input);
}

/* Checks given string if it represents a proper number */
int is_number(string s) {
    s = s.c_str(); // Make it null-terminated 

    char *temp = &s[0];
    while (*temp != '\0'){
        // Check if everything in the string is a number
        if (*temp < 48 || *temp > 57) {
            cout << "Not a number!" << endl;
            return 1;
        }
        temp ++;
    }

    cout << "Number entered!" << endl;
    return 0;
}

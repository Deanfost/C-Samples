#include <iostream>
using namespace std;

void print_string(char str[]);
void print_string(string);

int main() {
    char c_string[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    string string_obj = "Hello from C++!";

    print_string(c_string);
    print_string(string_obj);
    return 0;
}

/* Overload using traditional C-style strings */
void print_string(char str[]) {
    cout << "C string: " << endl;
    char *c = str;
    while (*c != '\0') {
        cout << *c;
        c++;
    }
    cout << endl;
}

/* Overload using C++ string objects */
void print_string(string s) {
    cout << "String object: " << endl;
    cout << s << endl;
}
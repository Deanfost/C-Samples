#include <iostream>

using namespace std; // Standard namespace

int main() {
    double var1, var2, result = 0;
    char operation;

    // Get two numbers from stdin
    cout << "Enter two numbers: \n";
    cin >> var1;
    cin >> var2;   

    // Get the operation
    cout << "What do you want to do?\n";
    cout << "+ - Add\n";
    cout << "- - Sub\n";
    cout << "* - Mul\n";
    cout << "/ - Div\n";
    cin >> operation;

    // Perform operation
    switch (operation) {
        case '+': 
            result = var1 + var2;
            break;
        case '-': 
            result = var1 - var2;
            break;
        case '*': 
            result = var1 * var2;
            break;
        case '/':
            result = var1 / var2;
            break;
        default:
            cout << "Invalid instruction." << endl; 
    }

    // Print out result
    cout << "The result is: " << result << endl;

    return 0;
}
 
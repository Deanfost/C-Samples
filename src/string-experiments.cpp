#include <iostream>
using namespace std;

int main() {
    string *dyn_str = new string("help");
    cout << *dyn_str << endl;
    cout << (*dyn_str).length() << endl;
    delete dyn_str;

    return 0;
}
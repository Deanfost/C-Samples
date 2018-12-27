#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // Get the arguments given to the program
    cout << "Arg count: " << argc << endl;
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    // Remember that we can use the C string library to compare C strings
    // Also remember that the first argument passed in is the name of the cmd
    cout << strcmp(argv[1], argv[2]) << endl;
    return 0;
}
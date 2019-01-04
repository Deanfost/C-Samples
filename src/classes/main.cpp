#include "personal-data.h"

int main() {
    // Create two new instances of the class in the stack
    char name1[] = "Dean";
    char name2[] = "Kara";

    Personal_data dean(-12, name1);
    Personal_data kara(20, name2);

    int age;
    string name;

    cout << "Enter a new name :" << endl;
    cin >> name;

    cout << "Enter a new age: " << endl;
    cin >> age;
    cout << endl;

    cout << "Previous 'kara' values: " << endl;
    cout << "Name: " << kara.get_name() << " at " << (int *) kara.get_name() << endl;
    cout << "Age: " << kara.get_age() << endl << endl;

    // Note that its a lot easier to use the string class if we're using cin
    char new_name[strlen(name.c_str())];
    strcpy(new_name, name.c_str());
    kara.set_name(new_name);
    kara.set_age(age);

    cout << "New 'kara' values: " << endl;
    cout << "Name: " << kara.get_name() << " at " << (int *) kara.get_name() << endl;
    cout << "Age: " << kara.get_age() << endl;

    return 0;
}
#include <iostream>
using namespace std;

struct personal_data {
    string name;
    string surname;
    string phone_number;
    int age;
} a;

void modify_data(personal_data *);

int main() {
    /* We can use a struct to associate data */
    personal_data data;
    data.name = "Dean";
    data.surname = "Foster";
    data.phone_number = "3905379024";
    data.age = 245;

    cout << data.name << endl;
    cout << data.surname << endl;
    cout << data.phone_number << endl;
    cout << data.age << endl;

    /* An array of structs */
    personal_data arr[5];
    arr[0].name = "Dean";
    arr[1].name = "Kyle";
    arr[2].name = "Emilia";
    arr[3].name = "Jennifer";
    arr[4].name = "Leonardo";

    /* We can use the arrow operator for pointers to structs */
    cout << arr -> name << endl;
    cout << (arr + 2) -> name << endl;

    /* Now we can just pass in one variable, and with it comes 20 pieces of data */
    modify_data(arr);
    for (int i = 0; i < 5; i++) {
        cout << arr[i].name << endl;
    }

    return 0;
}

void modify_data(personal_data *data) {
    for (int i = 0; i < 5; i ++) {
        data[i].name = "John Cena";
    }
}
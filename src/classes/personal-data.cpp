#include "personal-data.h"

Personal_data::Personal_data(short age, char name[]) {
    set_age(age);
    set_name(name);

    static int i = 0; 
    cout << "Constructor invocation " << ++i << endl;
}

void Personal_data::set_age(short age) {
    if (age < 0) 
        this -> age = 0;
    else 
        this -> age = age;
}

short Personal_data::get_age() {
    return age;
}

void Personal_data::set_name(char name[]) {
    delete this -> name;
    this -> name = new char[strlen(name) + 1];
    strcpy(this -> name, name);
}

char * Personal_data::get_name() {
    char * deep_copy = new char[strlen(this -> name) + 1];
    strcpy(deep_copy, this -> name);
    return deep_copy;
}

Personal_data::~Personal_data() {
    delete this -> name;

    static int i = 0; 
    cout << "Destructor invocation " << ++i << endl;
}
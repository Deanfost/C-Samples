#ifndef PERSONAL_DATA_INCLUDED
#define PERSONAL_DATA_INCLUDED

#include <iostream>
using namespace std;

// The class prototype goes in the header file; defns are in a sperate one
class Personal_data {
    private: 
        short age;
        char *name;
    public:
        Personal_data(short, char []);
        ~Personal_data(); // Invoked when program exits, or during deallocation
        void set_age(short);
        short get_age();
        void set_name(char []);
        char * get_name();
};

#endif
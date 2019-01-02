#include <iostream>
#include "library.h"

using namespace std;

int main() {
    Expandable_array arr;
    arr.add_value(12);
    arr.add_value(12);
    arr.add_value(12);
    arr.add_value(12);
    arr.add_value(143);
    arr.add_value(13);

    arr.print_list();

    return 0;
}
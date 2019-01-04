#include <iostream>
#include <assert.h>
#include "library.h"

using namespace std;

int main() {
    Linked_list list;
    Expandable_array arr;

    list.add_item("Hello", 2);
    list.add_item("World!", 4);

    arr.add_value(2);
    arr.add_value(4);

    list.print_list();
    arr.print_list();

    list.edit_item("Hello", 100);
    arr.edit_value(0, 100);

    cout << arr.get_item_count() << endl;
    cout << arr.get_capacity() << endl;

    arr.add_value(12);
    arr.add_value(14);
    arr.add_value(16);
    arr.add_value(20);

    cout << arr.get_item_count() << endl;
    cout << arr.get_capacity() << endl;

    list.print_list();
    arr.print_list();

    list.free_list();

    return 0;
}
#include "library.h"

/**
 * Contains implementations of Array List of int functions.
 */

/* Default constructor for the list. */
Expandable_array::Expandable_array() {
    this -> array = NULL;
    this -> item_count = 0;
    this -> capacity = 0;
}

Expandable_array::Expandable_array(int initial_size) {
    this -> array = new int[initial_size];
    this -> item_count = 0;
    this -> capacity = initial_size;
}

/* Destructor for the array. */
Expandable_array::~Expandable_array() {
    delete [] this -> array;
}

/* Appends a value to the Array List. */
void Expandable_array::add_value(int item) {
    if (!this -> array) {
        // First item in the list, init the array
        this -> array = new int[ARR_INCR_SIZE];
        this -> capacity = ARR_INCR_SIZE;
        // Add the item
        this -> array[0] = item;
        this -> item_count = 1;
    } else {
        // Check if we need to reallocate
        if (this -> capacity == this -> item_count) {
            int new_cap = this -> capacity + ARR_INCR_SIZE;
            this -> array = (int *) realloc(this -> array, new_cap * sizeof(int));
            this -> capacity = new_cap;
        }
        // Add the item
        this -> array[item_count] = item;
        item_count++;
    }
}

/* Removes a value at the given index. */
void Expandable_array::remove_value(int index) {
    if (this -> array) {
        if (index >= 0 && index < this -> item_count) {
            this -> array[index] = 0;
            for (int i = index; i < item_count; i++) {
                
            }
        }   
    }
}

/* Edits the value at the given index. */
void Expandable_array::edit_value(int index, int new_value){
    
}

/* Returns the size of the Array List. */
int Expandable_array::get_size() {
    return this -> item_count;
}

/* Returns the current capacity of the Array List. */
int Expandable_array::get_capacity() {
    return this -> capacity;
}

/* Explicitly resizes the Array List. */
void Expandable_array::resize(int new_size) {

}

/* Returns a deep-copy of the stored array. */
int* Expandable_array::to_array() {
    return NULL;
}

/* Returns the value at the given index. */
int* Expandable_array::value_at(int index) {
    return NULL;
}

/* Returns the amount of times the given value appears in the list. */
int Expandable_array::count_similar(int value) {
    return 0;
}

/* Compares two Array List objects for structural equality. */
bool Expandable_array::equal_to(Expandable_array other) {
    return 0;
}

/* Prints the elements in the Array List. */
void Expandable_array::print_list() {
    for (int i = 0; i < item_count; i++) {
        cout << "[" << i << "] " << this -> array[i] << endl;
    }
}

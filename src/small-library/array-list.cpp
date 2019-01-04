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
    if (initial_size > 0)
        this -> array = new int[initial_size];
    else 
        this -> array = new int[ARR_INCR_SIZE];
    
    this -> item_count = 0;
    this -> capacity = initial_size;
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
            for (int i = index; i < this -> item_count - 1; i++) {
                this -> array[i] = this -> array[i + 1];
            }
            this -> item_count--;
        }   
    }
}

/* Edits the value at the given index. */
void Expandable_array::edit_value(int index, int new_value){
    if (this -> array) {
        if (index >= 0 && index < this -> item_count) {
            this -> array[index] = new_value;
        }
    }
}

/* Returns the size of the Array List. */
int Expandable_array::get_item_count() {
    return this -> item_count;
}

/* Returns the current capacity of the Array List. */
int Expandable_array::get_capacity() {
    return this -> capacity;
}

/* Explicitly resizes the Array List. */
void Expandable_array::resize(int new_size) {
    if (new_size > 0) {
        if (new_size < this -> item_count) {
            // Allocate a new array, copy over as many elems as possible
            int *new_arr = new int[new_size];
            for (int i = 0; i < new_size; i++) {
                new_arr[i] = this -> array[i];
            }
            delete this -> array;
            this -> array = new_arr;
            this -> capacity = new_size;
            this -> item_count = new_size;
        } else {
            // Normal resize
            this -> array = (int *) realloc(this -> array, new_size * sizeof(int));
            this -> capacity = new_size;
        }
    }
}

/* Returns a deep-copy of the stored array. */
int* Expandable_array::to_array(int *out_size) {
    if (this -> array) {
        int *copy = new int[this -> item_count];
        for (int i = 0; i < this -> item_count; i++) {
            copy[i] = this -> array[i];
        }
        *out_size = this -> item_count;
        return copy;
    } else {
        return NULL;
    }
}

/* Returns the value at the given index. */
int* Expandable_array::value_at(int index) {
    if (this -> array) {
        if (index >= 0 && index < this -> item_count) {
            int *i = new int;
            *i = this -> array[index];
            return i;
        }
    }
    return NULL;
}

/* Returns the amount of times the given value appears in the list. */
int Expandable_array::count_similar(int value) {
    int count = 0;
    if (this -> array) {
        for (int i = 0; i < this -> item_count; i++) {
            if (this -> array[i] == value) {
                count ++;
            }
        }
    }
    return count;
}

/* Compares two Array List objects for data equality. */
bool Expandable_array::equal_to(Expandable_array other) {
    // Check stored array existence and item count
    if ((!this -> array && other.array) || (this -> array && !other.array)) {
        return false;
    }
    if (this -> item_count != other.item_count) {
        return false;
    }
    // Compare all items
    for (int i = 0; i < this -> item_count; i++) {
        if (this -> array[i] != other.array[i]) {
            return false;
        }
    }

    return true;
}

/* Prints the elements in the Array List. */
void Expandable_array::print_list() {
    for (int i = 0; i < item_count; i++) {
        cout << "[" << i << "] " << this -> array[i] << endl;
    }
}

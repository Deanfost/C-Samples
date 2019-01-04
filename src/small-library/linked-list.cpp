#include "library.h"

/**
 * Contains implementations of Linked List class functions.
 */

/* Default constructor for the list. */
Linked_list::Linked_list() {
    this -> size = 0;
    this -> list = NULL;
}

/* Appends an item to the end of the list. No duplicate tags allowed. */
void Linked_list::add_item(string tag, int value) {
    if (this -> list == NULL) {
        // This is the first element
        Linked_inner *new_node = new Linked_inner(tag, value);
        this -> list = new_node;
        this -> size = 1;
    } else {
        // Not the first element
        Linked_inner *curr = this -> list;
        while (curr -> next) {
            string this_tag = curr -> tag;
            if (this_tag.compare(tag) == 0) {
                return;
            }
            curr = curr -> next;
        }
        Linked_inner *new_node = new Linked_inner(tag, value);
        curr -> next = new_node;
        this -> size ++;
    }
}

/* Removes the item with the given tag. */
void Linked_list::remove_item(string tag) {
    Linked_inner *curr = this -> list;
    Linked_inner *prev = NULL;
    bool found_tag = false;
    while(curr) {
        string this_tag = curr -> tag;
        if (this_tag.compare(tag) == 0) {
            found_tag = true;
            break;
        }
        prev = curr;
        curr = curr -> next;
    }
    if (found_tag) {
        if (curr && !prev) {
        // This is the first element
        Linked_inner *next = curr -> next;
        curr -> next = NULL;
        delete curr;
        this -> size--;
        this -> list = next;
    } else if (curr && prev) {
        // This is a middle element
        Linked_inner *next = curr -> next;
        curr -> next = NULL;
        delete curr;
        this -> size--;
        prev -> next = next;
    } else if (!curr && prev) {
        // This is the last element
        delete curr;
        this -> size--;
        prev -> next = NULL;
        }
    }
}

/* Changes the value assocated with the given tag */
void Linked_list::edit_item(string tag, int new_value) {
    Linked_inner *curr = this -> list;
    while (curr) {
        string this_tag = curr -> tag;
        if (this_tag.compare(tag) == 0) {
            curr -> value = new_value;
            return;
        }
        curr = curr -> next;
    }
}

/* Changes the value at the given index. */
void Linked_list::edit_index(int index, int new_value) {
    if (index >= 0) {
        Linked_inner *curr = this -> list;
        while (index-- && curr) {
            curr = curr -> next;
        }   
        if (curr)
            curr -> value = new_value;
    }
}

/* Counts the nodes in the list. */
int Linked_list::get_size() {
    return this -> size;
}

/* Counts the nodes that contain the given value. */
int Linked_list::count_similar(int value) {
    int count = 0;
    Linked_inner *curr = this -> list;
    while (curr) {
        if (curr -> value == value) {
            count ++;
        }
        curr = curr -> next;
    }
    return count;
}

/* Returns a deep-copy of the Linked List as an array of values. Puts size of
 * array into the given variable. 
 */
int* Linked_list::values_to_array(int *out_size) {
    Linked_inner *curr = this -> list;
    int *arr = new int[this -> size];
    for (int i = 0; i < this -> size; i++) {
        arr[i] = curr -> value;
        curr = curr -> next;
    }
    *out_size = this -> size;
    return arr;
}

/* Returns a deep-copy of the Linked List as an array of tags. Puts size of array
 * into the given variable. 
 */
string* Linked_list::tags_to_array(int *out_size) {
    Linked_inner *curr = this -> list;
    string *arr = new string[this -> size];
    for (int i = 0; i < this -> size; i++) {
        arr[i] = curr -> tag;
        curr = curr -> next;
    }
    *out_size = this -> size;
    return arr;
}

/* Returns the value associated with the given tag. */
int* Linked_list::from_tag(string tag) {
    Linked_inner *curr = this -> list;
    while (curr) {
        string this_tag = curr -> tag;
        if (this_tag.compare(tag) == 0) {
            int *val = new int();
            *val = curr -> value;
            return val;
        }
        curr = curr -> next;
    }
    return NULL;
}

/* Returns the value at the given position in the list. */
int* Linked_list::from_index(int index) {
    if (index >= 0) {
        Linked_inner *curr = this -> list;
        while (index-- && curr) {
            curr = curr -> next;
        }
        if (curr) {
            int *val = new int;
            *val = curr -> value;
            return val;
        }
    }
    return NULL;
}

/* Compares two Linked List objects for structural equality. */
bool Linked_list::equal_to(Linked_list other) {
    Linked_inner *curr = this -> list;
    Linked_inner *other_curr = other.list;
    // Check each element in both lists
    while (curr && other_curr) {
        string this_tag = curr -> tag;
        string other_tag = other_curr -> tag;
        if (this_tag.compare(other_tag) != 0) {
            return false;
        } 
        if (curr -> value != other_curr -> value) {
            return false;
        }
        curr = curr -> next;
        other_curr = other_curr -> next;
    }
    // Check length of both lists
    if (curr || other_curr) {
        return false;
    }
    return true;
}

/* Prints out all of the items in the list */
void Linked_list::print_list() {
    Linked_inner *curr = this -> list;
    while (curr) {
        cout << "[" << curr -> tag << "] " << curr -> value << endl;
        curr = curr -> next;
    }
}

/* Frees all nodes in the list. Must be called to ensure the list is properly
 * freed. */
void Linked_list::free_list() {
    Linked_inner *curr = this -> list;
    while (curr) {
        Linked_inner *next = curr -> next;
        delete curr;
        curr = next;
    }
}

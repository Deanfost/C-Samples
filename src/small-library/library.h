#ifndef LIB_INCLUDED
#define LIB_INCLUDED

#include <iostream>
using namespace std;

#define ARR_INCR_SIZE 5

// Definition for a singly linked-list with a dummy head (unordered)
class Linked_list {
    private: 
        class Linked_inner {
            public: 
                string tag;
                int value;
                Linked_inner *next;
                Linked_inner() {
                    this -> value = 0;
                    this -> next = NULL;
                }
                Linked_inner(string tag, int value) {
                    this -> tag = string(tag);
                    this -> value = value;
                    this -> next = NULL;
                }
        };
        int size;
        Linked_inner *list;
    public:
        Linked_list();
        void add_item(string tag, int value);
        void remove_item(string tag);
        void edit_item(string tag, int new_value);
        void edit_index(int index, int new_value);
        int get_size();
        int count_similar(int value);
        int* values_to_array(int*);
        string* tags_to_array(int*);
        int* from_tag(string tag);
        int* from_index(int index);
        bool equal_to(Linked_list other);
        void print_list();
        void free_list();
};

// Definition for a simple array-list (unordered)
class Expandable_array {
    private: 
        int *array;
        int item_count;
        int capacity;
    public:
        Expandable_array();
        Expandable_array(int initial_size);
        // ~Expandable_array();
        void add_value(int item);
        void remove_value(int index);
        void edit_value(int index, int new_value);
        int get_item_count();
        int get_capacity();
        void resize(int new_size);
        int* to_array(int *out_size);
        int* value_at(int index);
        int count_similar(int value);
        bool equal_to(Expandable_array other);
        void print_list();
};

#endif
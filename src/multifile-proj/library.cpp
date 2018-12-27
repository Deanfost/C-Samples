#include "main.h"

// Externally-referenced integer
int a = 50;

/* Add the given number to the list */
void add_to_list(Linked_list **list, int value) {
    // Is the list empty?
    if (*list == NULL){
        // Add as first element
        *list = new Linked_list;
        (*list) -> value = value;
        (*list) -> next = NULL;
    } else {
        // Append the element to the list
        Linked_list *curr = *list;
        while (curr -> next != NULL) {
            curr = curr -> next;
        }

        Linked_list *new_node = new Linked_list;
        new_node -> value = value;
        new_node -> next = NULL;
        curr -> next = new_node;
    }
}

/* Count the items in the list */
int count_list(Linked_list *list) {
    int count = 0;
    while (list != NULL) {
        count ++;
        list = list -> next;
    }
    return count;
}

/* Print out all values in the list */
void print_list(Linked_list *list) {
    while (list != NULL) {
        cout << list -> value << endl;
        list = list -> next;
    }
}

/* Free the list from memory */
void free_list(Linked_list **list) {
    Linked_list *curr = *list;
    while (curr != NULL) {
        Linked_list *temp = curr -> next;
        delete curr;
        curr = temp;
    }
    *list = NULL;
}
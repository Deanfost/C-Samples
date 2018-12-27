#ifndef MAIN_H
#define MAIN_H

/* All header file definitions are defined only once because of this check */
#include <iostream>
#include <string>
using namespace std;

#define PI 3.1415
#define GREETING "Hello there, "

extern int a;

typedef struct linked_list {
    int value;
    linked_list *next;
} Linked_list;

void add_to_list(Linked_list **, int);
int count_list(Linked_list *);
void print_list(Linked_list *);
void free_list(Linked_list **);

#endif
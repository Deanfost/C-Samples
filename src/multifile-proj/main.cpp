#include "main.h"

int main(int argc, char *argv[]) {
    // Use macros from the header file
    Linked_list *list = NULL;

    cout << GREETING << "Dean!" << endl;
    cout << "This is a macro definition: " << PI << endl;
    cout << "Here is a number :) " << a << endl;

    // Add given args to a linked-list of integers
    if (argc > 1) {
        for (int i = 0; i < argc - 1; i++) {
            add_to_list(&list, stoi(argv[i + 1]));
        }
    }

    cout << "List contents: " << endl;
    print_list(list);
    cout << "List length: " << count_list(list) << endl;

    cout << "Freeing list..." << endl;
    free_list(&list);
    cout << "List Length: " << count_list(list) << endl;

    return 0;
}
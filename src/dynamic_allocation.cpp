#include <iostream> 
using namespace std;

int main() {
    /* Remember that in C we needed to use malloc() and alloc() to grab new
    slots of memory from the heap. We can use the keyword 'new' which is very 
    much akin to that kind of function call in C++. Note that in C++, it not 
    only calls malloc(), it also calls the constructor of the object you are 
    allocating. */

    int *new_int = new int;
    cout << "Address: " << new_int << endl;
    cout << "Value: " << *new_int << endl;

    *new_int = 45;
    cout << "New value: " << *new_int << endl;

    /* Remember that if you put pointers inside of local scope, the new memory will
    be allocated in the system, but once that scope exits, you can no longer
    access that memory, even though it is still allocated. In order to ensure 
    we have no memory leaks, we need to deallocate the memory after we are done
    by using 'delete'. 
    
    Also note that after we free it, we still have a reference, but this slot
    may have already been used by another application. To avoid dangling pointers, 
    make sure to set the pointer to NULL. You can then reference new pieces of 
    memory.
    */

    {
        int *p = new int;
        cout << "Local pointer address: " << p << endl;
        delete p;

        cout << "Local freed pointer address: " << p << endl;
        cout << "Local freed pointer value: " << *p << endl;

        p = NULL;

        p = new int;
        cout << "New pointer address: " << p << endl;
    }

    return 0;
}
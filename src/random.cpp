#include <iostream>
using namespace std;

int main() {
    /* Note that everytime we run the program these numbers will be the same */
    int rd = rand();
    cout << rd << endl;
    rd = rand();
    cout << rd << endl;

    /* We need to affect the random number by changing the seed it draws from */
    srand(100);
    rd = rand();
    cout << rd << endl;

    /* It is different, but not random everytime. We need a seed that changes. 
    How about time? The time function gives us the seconds since the Epoch 
    (January 1st, 1970, 0:00:00 UTC). This number is the standard time measurement
    metric, and is always going up, so we can use it as a good seed. Note that 
    this function is periodic if initialized with time. */
    srand(time(NULL));
    rd = rand();
    cout << "Random number: " << rd << endl;

    /* To get a number between a range, use modulo */
    srand(time(NULL));
    int rd_rng = rand() % 10 + 1; // Random number between 1 and 10 inclusive
    cout << rd_rng << endl;

    rd_rng = rand() % 20; // Random number between 0 and 19 inclusive
    cout << rd_rng << endl;

    rd_rng = rand() % 21; // Random number between 0 and 20 inclusive
    cout << rd_rng << endl;

    return 0;
}
#include <iostream>
using namespace std;

int main() {
    string name;
    cout << "Give me your name" << endl;
    cin >> name;
    cin.ignore(10000, '\n');
    
    int age;
    cout << "Give me your age:" << endl;
    if (cin >> age)
        cout << "Your age is equal to:" << endl;
    else {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Give me your age name as string I dare you";
        cin >> age;
    }

    return 0;
}

/* --- DOCS ON VALIDATION TECHNIQUES AND BUFFER INFORMATION ---
When grabbing input, you may expect one type and then be given a different one. 
This causes the stdin buffer to be given an internal error state. To see the state
we used cin.rdstate() which gives us the error code int. If the value is 
implicitly true, then we have an error. 

cin.clear() is used to clear the state in the buffer, reverting it back to 0, 
which allows us to grab more input. However, while we've "silenced the alarm," 
we still need to clear out the invalid values in the buffer. 

cin.ignore(int limit, char c) is used to remove the invalid input. "Limit" is 
normally assigned a large value (such as 10000), which just means to clear out the 
next 10000 chars in the buffer. The second arg is used as a secondary limit char - 
if we hit that char (such as '\n'), then we also stop. Essentially, we clear out
the next 10000 chars, or until we hit the end of the line. Whichever comes first. 
Since data flows like a stream in a buffer, this function is often paired after
cin >> data, since it allows us to ignore everything but the first value.

Calling ignore() allows the buffer to accpet input again, and we can continue
the program. 

So essentially what we're doing, is we are grabbing the input for name. We clear
the buffer afterwards to get rid of extra inputs (delimited by spaces) to make
way for the next instruction. We then grab the (hopefully int) input for age. 
After, we check if the user gave us an int. If not, we clear the error, clear the 
invalid input, and then ask again. Of course, here if the user does the same thing, 
we are kinda screwed. A loop/function should be implemented. 

As a sidenote, you can also grab two consecutive values in a single line
using two calls to cin >> var. If you say "Dean Foster" you could collect both
parts by having two calls to cin >> var, since mentioned earlier inputs are 
delimited by spaces. 

Double sidenote - cin ignores the newline character, which means that it'll
still be in the buffer. Just keep that in mind if you use things like 
getline() afterwards, which collectes everything UPTO AND INCLUDING that char. 
So, you may end up with empty input if you call it immediately afterwards, since
it'll have what it needs to return. 

--- NOTE ---
The "<<" and ">>" operators are overloaded in the "iostream.h" header file
to correspond to the put() and get() function defintions. Just like in C, the 
function returns 1 if it was successful, and 0 if there was an error. 
So when you say: 

cout << "I love C++!" << endl;

you're really saying:

put(cout, "I love C++!");
put(cout, "\n");

*/
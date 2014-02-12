#include <iostream>

using namespace std;

/*
I don't recommend actually running this program lol.
It will run forever and overwrite your memory with all 0s.
Rewrite some of it to do something a bit more useful, like reading
20 spots in memory a bit at a time every time you hit enter. You
may also add an exit possibility.
- Justin Ead
*/

int main()
{
    int empty = 0;
    int* ptr1 = &empty;
    int* ptr2 = &empty;

    while (true)
    {
        cout << &ptr1;
        --(*ptr1) = 0;
        ++(*ptr2) = 0;
        cout << *ptr2;
    }
}

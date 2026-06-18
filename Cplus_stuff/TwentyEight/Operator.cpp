/**

Operators:

1. Post-decrement, Pre-decrement, Post-addition, Pre-addition
- For this expression, the program will read from left to right
    --b: minus b's value first then return b
    b--: return b first then minus b

**/

#include <iostream>
using namespace std;

int main()
{
    const int value = 10;
    int b = value;

    int x = --b; // x = 9, b = 9
    b = value;
    int y = b--; // y = 10, b = 9

    cout << x << endl << y << endl;
    return 0;
}

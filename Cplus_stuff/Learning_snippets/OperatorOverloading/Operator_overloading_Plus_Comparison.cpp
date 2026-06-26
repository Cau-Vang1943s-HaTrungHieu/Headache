/**

By default, we can only use operators for the basic operands such as:
    numbers (int, double, etc.), strings (5 + 5)
In order to use the operators on the custom type (class, struct), you need to overload it with a new function
So instead of function, overloading operators really reduce the amount of jargon that we made in the coding process.

Syntax:
[type] operator [operator symbol] ([custom type] [instance])
{
}

**/


#include <iostream>
using namespace std;

class Position
{
public:
    int x, y;

    Position operator + (Position other)
    {
        Position result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
    bool operator == (Position other)
    {
        return (x == other.x) and (y == other.y);
    }
};

int main()
{
    Position pos1, pos2, pos_result;
    pos1.x = 10;
    pos1.y = 20;
    pos2.x = 30;
    pos2.y = 20;

    pos_result = pos1 + pos2;

    cout << pos_result.x << " " << pos_result.y << endl;

    if (pos1 == pos2) cout << "They are the same!" << endl;
    else cout << "They are not the same!" << endl;

    return 0;
}

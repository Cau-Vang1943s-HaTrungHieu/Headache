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

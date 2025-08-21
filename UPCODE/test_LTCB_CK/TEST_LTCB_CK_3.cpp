#include <iostream>
using namespace std;

struct Coordinate
{
    int x, y;  // Đổi từ double thành int

    void getCoord()
    {
        cin >> x >> y;
    }

    bool isOnAxis()
    {
        return x == 0 || y == 0;  // Đổi từ 'or' thành '||'
    }
};

int main()
{
    int n;
    cin >> n;
    Coordinate coords[n];

    for (int i = 0; i < n; ++i) {
        coords[i].getCoord();
    }

    int pointsCounted = 0;
    for (int i = 0; i < n; ++i) {
        if (coords[i].isOnAxis()) ++pointsCounted;
    }
    cout << pointsCounted;

    return 0;
}
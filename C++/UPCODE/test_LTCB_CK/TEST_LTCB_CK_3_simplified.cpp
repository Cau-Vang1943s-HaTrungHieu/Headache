#include <iostream>
using namespace std;

int main()
{
    int x, y, n;
    cin >> n;

    int pointsCounted = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x == 0 or y == 0) ++pointsCounted;
    }

    cout << pointsCounted;

    return 0;
}
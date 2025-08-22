#include <iostream>
using namespace std;

int main()
{
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double product = a * b * c * d;
    if (product > 0) cout << 1;
    else if (product < 0) cout << -1;
    else cout << 0;

    return 0;
}
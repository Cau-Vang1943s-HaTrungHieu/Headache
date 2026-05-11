// Web: HackerRank

#include <iostream>
using namespace std;

int max_of(int a, int b, int c, int d)
{
    int result = a;
    if (b > result) result = b;
    if (c > result) result = c;
    if (d > result) result = d;
    return result;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max_of(a, b, c, d);

    return 0;
}

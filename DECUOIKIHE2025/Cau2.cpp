#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool isExisted;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0 or n % i != 0) {
            isExisted = true;
            cout << i << " ";
        }
    }

    if (!isExisted) cout << -1;

    return 0;
}
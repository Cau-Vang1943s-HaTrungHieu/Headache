#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int product = 1;
    if (n <= 0) cout << "N phai la so nguyen duong";
    else {
        for (int i = 1; i <= n; ++i) {
            if (i % 3 != 0) product *= i;
        }
    }

    cout << product;

    return 0;
}
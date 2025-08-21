#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if (num == 2) return true;
    if (num < 2) return false;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (isPrime(a[i])) sum += a[i];
    }
    cout << sum;

    return 0;
}
#include <iostream>
using namespace std;

bool isPrime(int num)
{
    if (num == 2) return true;
    if (num < 2 or num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isFutureNum(int num)
{
    bool existDivisor = false;
    if (num <= 2) return false;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) {
            existDivisor = true;
            if (!isPrime(i)) return false;
        }
    }
    return existDivisor;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (isFutureNum(a[i])) ++total;
    }

    cout << total;

    return 0;
}
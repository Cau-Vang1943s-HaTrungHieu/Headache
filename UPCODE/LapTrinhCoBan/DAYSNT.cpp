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

int main()
{
    int k, arrSize = 0;
    int a[100];
    cin >> k;

    int value;
    while (cin >> value) {
        a[arrSize++] = value;
    }

    int maxPrime = -1;
    for (int i = 0; i < arrSize; ++i) {
        if (isPrime(a[i]) and a[i] > maxPrime and a[i] <= k) {
            maxPrime = a[i];
        }
    }

    cout << maxPrime << endl;
    return 0;
}
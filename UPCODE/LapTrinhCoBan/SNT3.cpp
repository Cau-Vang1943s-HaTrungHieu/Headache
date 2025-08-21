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
    int a, b;
    cin >> a >> b;

    for (;a <= b; ++a) {
        if (isPrime(a)) cout << a << endl;
    }
    return 0;
}
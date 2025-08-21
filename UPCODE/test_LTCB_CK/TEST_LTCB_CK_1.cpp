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

int sumOfDigits(int num)
{
    int result = 0;
    while (num > 0) {
        int digit = num % 10;
        result += digit;
        num /= 10;
    }
    return result;
}

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        if (isPrime(sumOfDigits(i))) {
            cout << i << " ";
        }
    }

    return 0;
}
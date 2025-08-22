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
    int k;
    cin >> k;
    
    for (int i = 1; i <= k; ++i) {
        if (isPrime(i)) cout << i << endl;
    }

    return 0;
}
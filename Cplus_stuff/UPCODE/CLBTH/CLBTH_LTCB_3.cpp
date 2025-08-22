#include <iostream>
using namespace std;

long power(long base, long exponent)
{
    long result = 1;
    for (long i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main()
{
    long a, n;
    cin >> a >> n;
    cout << power(a, n);
    
    return 0;
}
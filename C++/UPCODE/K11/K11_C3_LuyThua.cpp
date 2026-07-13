#include <iostream>
using namespace std;

int power(int base, int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main()
{
    int x, n;
    cin >> x >> n;
    
    if (n < 0) {
        cout << 1;
        return 0;
    } else {
        cout << power(x, n);
    }
    return 0;
}
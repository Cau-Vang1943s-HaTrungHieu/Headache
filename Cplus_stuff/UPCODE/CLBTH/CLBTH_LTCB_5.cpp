#include <iostream>
using namespace std;

long factorial(int num)
{
    long result = 1;
    for (int i = 2; i <= num; ++i) {
        result *= i;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    
    return 0;
}
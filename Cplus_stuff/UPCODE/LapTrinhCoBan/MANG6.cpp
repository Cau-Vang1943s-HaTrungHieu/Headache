
#include <iostream>
#include <cmath>
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

bool isPerfectSqr(int num)
{
    int sqrNum = sqrt(num);
    return sqrNum * sqrNum == num;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (isPerfectSqr(a[i]))
            cout << a[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < n; ++i) {
        if (isPrime(a[i])) 
            cout << a[i] << " ";
    }
    
    
    return 0;
}
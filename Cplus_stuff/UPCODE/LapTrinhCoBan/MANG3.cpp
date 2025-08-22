#include <iostream>
#include <cmath>
using namespace std;

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
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (isPerfectSqr(a[i])) sum += a[i];
    }
    cout << sum;
    
    return 0;
}
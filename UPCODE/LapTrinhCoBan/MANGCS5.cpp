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
    int arrSize = 0;
    int a[100];
    
    while (cin >> a[arrSize]) {
        arrSize++;
    }
    
    int sumOfPerfectSqr = 0;
    for (int i = 0; i < arrSize; ++i) {
        if (isPerfectSqr(a[i])) {
            sumOfPerfectSqr += a[i];
        }
    }
    cout << sumOfPerfectSqr;
    
    return 0;
}
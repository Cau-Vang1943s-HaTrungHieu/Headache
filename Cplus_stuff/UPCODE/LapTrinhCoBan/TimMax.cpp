#include <iostream>
using namespace std;

int main()
{
    int arrSize = 0;
    int a[100];
    
    while (cin >> a[arrSize]) {
        arrSize++;
    }
    
    int maxVal = a[0];
    for (int i = 0; i < arrSize; ++i) {
        if (a[i] > maxVal) maxVal = a[i];
    }
    cout << maxVal;
    
    return 0;
}
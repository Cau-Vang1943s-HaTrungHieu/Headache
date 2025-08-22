#include <iostream>
using namespace std;

void inputArray(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; ++i) {
        cin >> a[i];
    }
}

int sumOfArray(int a[], int arrSize)
{
    int result = 0;
    for (int i = 0; i < arrSize; ++i) {
        result += a[i];
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    
    inputArray(a, n);
    cout << sumOfArray(a, n);
    
    
    return 0;
}
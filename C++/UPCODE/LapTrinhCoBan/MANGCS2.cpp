#include <iostream>
using namespace std;

int main()
{
    int arrSize = 0;
    int a[100];
    
    int value;
    while (cin >> value) {
        a[arrSize++] = value;
    }
    
    for (int i = 0; i < arrSize; ++i) {
        cout << a[i] << " ";
    }
    
    return 0;
}
#include <iostream>
using namespace std;

void insertElement(int a[], int& arrSize, int element, int index)
{
    for (int i = arrSize; i > index - 1; --i) {
        a[i] = a[i - 1];
    }
    a[index - 1] = element;
    ++arrSize;
}

void printArray(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; ++i) {
        cout << a[i] << " ";
    }
}

int main()
{
    int n, v, T;
    cin >> n >> v >> T;
    int a[n];
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    insertElement(a, n, T, v);
    printArray(a, n);
    return 0;
}
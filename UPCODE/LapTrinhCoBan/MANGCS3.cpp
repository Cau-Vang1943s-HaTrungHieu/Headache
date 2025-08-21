#include <iostream>
using namespace std;

void removeElement(int a[], int& arrSize, int index)
{
    a[index] = 0;
    for (int i = index; i < arrSize - 1; ++i) {
        a[i] = a[i + 1];
    }
    --arrSize;
}

void outputArray(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; ++i) {
        cout << a[i] << " ";
    }
}

int main()
{
    int arrSize = 0;
    int a[100], indexPos;

    cin >> indexPos;

    int value;
    while (cin >> value) {
        a[arrSize++] = value;
    }

    removeElement(a, arrSize, indexPos);
    outputArray(a, arrSize);

    return 0;
}

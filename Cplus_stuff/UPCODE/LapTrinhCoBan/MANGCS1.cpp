#include <iostream>
using namespace std;

void insertArray(int a[], int& arrSize, int indexPos, int element);
void outputArray(int a[], int arrSize);

int main()
{
    int arrSize = 0;
    int a[100];

    int indexPos, element;
    cin >> indexPos >> element;

    int value;
    while (cin >> value) {
        a[arrSize++] = value;
    }

    insertArray(a, arrSize, indexPos, element);
    outputArray(a, arrSize);

}

void insertArray(int a[], int& arrSize, int indexPos, int element)
{
    for (int i = arrSize; i > indexPos; --i) {
        a[i] = a[i - 1];
    }
    a[indexPos] = element;
    ++arrSize;
}

void outputArray(int a[], int arrSize)
{
    for (int i = 0; i < arrSize; ++i) {
        cout << a[i] << " ";
    }
}

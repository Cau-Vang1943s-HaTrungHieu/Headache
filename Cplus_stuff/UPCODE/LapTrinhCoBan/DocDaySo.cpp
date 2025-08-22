#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arrSize = 0;
    int a[100];

    int value;
    while (cin >> value) {
        a[arrSize++] = value;
    }

    if (arrSize < 3) cout << "NO";
    else {
        cout << arrSize << endl;

        int sum = 0;
        for (int i = 0; i < arrSize; ++i) {
            sum += a[i];
        }
        cout << sum << endl;

        for (int i = 0; i < arrSize - 1; ++i) {
            for (int j = i + 1; j < arrSize; ++j) {
                if (a[i] > a[j]) swap(a[i], a[j]);
            }
        }
        for (int i = 0; i < arrSize; ++i) {
            cout << a[i] << " ";
        }
    }
    
    
    return 0;
}
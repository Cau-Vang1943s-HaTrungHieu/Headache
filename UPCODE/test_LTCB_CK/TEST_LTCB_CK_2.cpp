#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int a[300];

    while (cin >> a[n]) {
        n++;
    }

    for (int i = 0; i < n; ++i) {
        bool isDuplicate = false;
        for (int j = 0; j < i; ++j) {
            if (a[j] == a[i]) {
                isDuplicate = true;
                break;
            }
        }
        
        if (!isDuplicate) {
            cout << a[i] << " ";
        }
    }


    return 0;
}
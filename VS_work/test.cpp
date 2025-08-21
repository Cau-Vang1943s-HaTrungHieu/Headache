#include <iostream>
using namespace std;

int main()
{   
    int n, q;
    cin >> n >> q;

    int** a = new int*[n];
    int* sizes = new int[n];

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        sizes[i] = k;
        a[i] = new int[k];
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }

    for (int qi = 0; qi < q; ++qi) {
        int i, j;
        cin >> i >> j;
        cout << a[i][j] << endl;    
    }

    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
    delete[] sizes;

    return 0;
}
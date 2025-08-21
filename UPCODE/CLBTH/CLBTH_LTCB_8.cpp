#include <iostream>
using namespace std;

int main()
{
    double a[7];

    for (int i = 0; i < 7; ++i) {
        cin >> a[i];
    }

    double hottest = a[0];
    double coldest = a[0];
    for (int i = 0; i < 7; ++i) {
        if (a[i] < 10) cout << a[i] << " ";
        if (a[i] > hottest) hottest = a[i];
        else if (a[i] < coldest) coldest = a[i];
    }
    cout << endl;

    cout << coldest << endl << hottest;

    return 0;
}
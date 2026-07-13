#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    if (n < 0) {
        cout << "NHAP SAI";
        return 0;
    } else {
        for (int i = 1; i <= n; ++i) {
            sum += i;
        }
    }
    cout << sum;
    
    return 0;
}
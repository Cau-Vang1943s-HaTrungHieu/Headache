/*
Tính S(n) = 1/2 + 1/4 + 1/6 + ... + 1/2n;
Lấy 3 chữ số sau dấu phẩy

Ví dụ:

Input
4
Output
3.858
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    double s = 0.0;
    for (int i = 1; i <= n; ++i) {
        s += 1.0 / (2 * i);
    }
    cout << fixed << setprecision(3) << s << endl;
    return 0;
}
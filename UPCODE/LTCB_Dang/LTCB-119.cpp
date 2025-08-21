/*Liệt kê tất cả các số nguyên tố nhỏ hơn n
Nhập n từ bàn phím với n là số nguyên dương

Ví dụ:

Input
7
Output
2 3 5
*/
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    for (int i = 2; i < n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    return 0;
}
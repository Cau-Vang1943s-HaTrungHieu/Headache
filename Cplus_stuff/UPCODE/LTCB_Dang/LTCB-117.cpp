/*Viết hàm nhập giá trị x (có thể là số thực) và n (số nguyên dương). Hãy xuất ra tổng theo công thức sau:

S(n) = x + x^2 + x^3 + ... + x^n

*/
#include <iostream>
#include <cmath>    
using namespace std;
double tinhTong(double x, int n) {
    double S = 0;
    for (int i = 1; i <= n; i++) {
        S += pow(x, i); 
    }
    return S;
}

int main() {
    double x;
    int n;
    cin >> x;
    cin >> n;
    cout << tinhTong(x, n) << endl;
    return 0;
}

/*Tính S(n) = x + x3 + x5 ... + x^2n+1. Với x là số thực, n là số nguyên được nhập từ bàn phím (in ra đến 2 chữ số thập phân).
Ví dụ:
Input: 3.2 4
Output: 38991.87*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    double x;
    int n;
    cin >> x >> n;
    if(n < 0) cout << -1;
    double tong = 0.0;
    for(int i = 0; i <= n; i++){
        tong += pow(x, 2 * i + 1); 
    }
    cout << fixed << setprecision(2) << tong;
    return 0;
}
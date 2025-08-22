/*
Tính S(n) = 1 + x + x^3 / 3! + ... + x^(2n+1) / (2n+1)!.
-Nhập số nguyên dương x
-Nhập số nguyên dương n
LƯU Ý:Tổng S(n) lấy  3 SỐ SAU DẤU PHẨY THẬP PHÂN 
             Nhập x trước, n sau.
VD:
Input:1 
         1
Output:2.167
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int n;
    float x;
    cin >> x >> n;
    if(n < 1) {
        cout << -1; 
        return 0;
    }
    
    float tong = 0.0;
    float giaiThua = 1.0; 
    
    for(int i = 0; i <= n; i++){
        if(i > 0) {
            giaiThua *= (2 * i + 1); 
        }
        tong += pow(x, 2 * i + 1) / giaiThua; 
    }
    cout << fixed << setprecision(3) << tong; 
    return 0;
}
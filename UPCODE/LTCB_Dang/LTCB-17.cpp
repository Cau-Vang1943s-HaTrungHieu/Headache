/*
Yêu cầu bài toán: Nhập vào số tự nhiên n (n>=1) và số thực x. Tính S(n)=x+((x^2)/(2!))+((x^3)/(3!))+...+((x^n)/(n!))

Chú ý: khai báo kiểu float

Ví dụ:

Input
4 8
Output
296
*/
#include <iostream>
#include <cmath>    
using namespace std;
int main(){
    int n;
    float x;
    cin >> n >> x;
    if(n < 1) {
        cout << -1; 
        return 0;
    }
    
    float tong = 0.0;
    float giaiThua = 1.0; 
    
    for(int i = 1; i <= n; i++){
        giaiThua *= i; 
        tong += pow(x, i) / giaiThua;
    }
    cout << tong; 
    return 0;
}
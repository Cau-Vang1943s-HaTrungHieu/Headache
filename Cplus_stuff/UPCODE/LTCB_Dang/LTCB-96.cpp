/*
Viết chương trình nhập vào một số thực x.
Yêu cầu: Tính giá trị của hàm số sau:
f(x) = { 2x^2 + 5x + 9 nếu x >= 5
         -2x^2 + 4x - 9 nếu x < 5
         }
x nhập vào là số thực và kết quả làm tròn đến chữ số thập phân thứ 2
input
1
output
-7.00

*/
#include <bits/stdc++.h>
using namespace std;
void tinhtoan(float a){
    if(a >= 5){
        cout << fixed << setprecision(2) << 2*a*a + 5*a+9;
    }
    else{
        cout << fixed << setprecision(2) << -2*a*a + 4*a-9;
    }
}

int main(){
    float x;
    cin >> x;
    tinhtoan(x);
}
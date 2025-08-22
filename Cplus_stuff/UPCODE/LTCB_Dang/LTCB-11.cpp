/*-Nhập số nguyên n

-Tính tổng S(n)=1+1*2+1*2*3+...+1*2*3*....*n


INPUT:5

OUTPUT:153
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n < 0) cout << -1;
    long long tong = 0;
    long long tich = 1;
    for(int i = 1; i <= n; i++){
        tich *= i; // VD: i=1: tich = 1; i=2: tich = 2; i=3: tich = 6; i=4: tich = 24; i=5: tich = 120
        // Tích này là 1*2*3*...*i
        tong += tich; // VD: i=1: tong = 1; i=2: tong = 3; i=3: tong = 9; i=4: tong = 33; i=5: tong = 153
    }  
    cout << tong;
    return 0;
}
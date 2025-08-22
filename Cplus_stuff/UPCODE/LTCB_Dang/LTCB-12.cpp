/*
Tính S(n) = x + x^2 +   ... + x^n.
Nhập vào x và n.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long x,n;
    cin >> x >> n;
    float tong =0;
    for (long long i=1; i<=n; i++){
        tong+=pow(x,i); // Sử dụng hàm pow để tính lũy thừa
    }
    cout << tong;
    return 0;
}
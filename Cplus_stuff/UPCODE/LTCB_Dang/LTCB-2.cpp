/*
Nhập số nguyên dương n; Tính tổng
S(n) = 1^2 + 2^2 + 3^2+...+n^2
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int tong = 0;
    for(int i = 1; i <= n; i++){
        tong += i * i; // Tính bình phương của i và cộng vào tổng
    }
    cout << tong;
    return 0;
}
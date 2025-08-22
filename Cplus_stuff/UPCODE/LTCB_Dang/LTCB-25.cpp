/*
Tính tổng tất cả “ước số chẵn” của số nguyên dương n. 
Yêu cầu bài toán: tính tổng các ước số CHẴN của số nguyên dương n



Ví dụ:

Input
1
Output
0*/
#include <iostream>
using namespace std;
int main(){
    int n, tong = 0;
    cin >> n;
    if(n <= 0) cout << -1;
    else {
        for(int i = 1; i <= n; i++){
            if(n % i == 0 && i % 2 == 0){
                tong += i;
            }
        }
    }
    cout << tong;
    return 0;
}
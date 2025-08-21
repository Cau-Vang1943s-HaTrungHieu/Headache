/*
Nhập số nguyên dương x và n. 
S(n) = 1/ 1 x 2 + 1 / 2 x 3 + ... + 1/ n x (n + 1)
In ra kết quả chỉ lấy 3 chữ số thập phân. Nếu giá trị đầu vào không hợp lệ in ra -1
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, n;
    cin >> x >> n;
    if(x <= 0 || n <= 0){
        cout << -1;
        return 0;
    }
    double tong = 0.0;
    for(int i = 1; i <= n; i++){
        tong += 1.0 / (i * (i + 1));
    }
    cout << round(tong * 1000) / 1000;
    return 0;
}
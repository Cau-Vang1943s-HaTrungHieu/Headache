/*
Tính tổng tất cả “ước số” của số nguyên dương n. 
Yêu cầu bài toán: Tính tổng tất cả “ước số” của số nguyên dương n.
Ví dụ:

Input
12
Output
28

*/
#include <iostream>
using namespace std;
int TongUS(int n){
    int s = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) s += i;
    }
    return s;
}

int main(){
    int n;
    cin >> n;
    if(n < 0) cout << -1;
    else cout << TongUS(n);
    return 0;
}
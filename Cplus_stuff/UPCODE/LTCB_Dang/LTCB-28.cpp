/*
Cho số nguyên dương n. tính tổng các ước số nhỏ hơn chính nó
*/
#include <iostream>
using namespace std;
int main(){
    int n, tong = 0;
    cin >> n;
    if(n <= 0) cout << -1;
    else {
        for(int i = 1; i < n; i++){
            if( n%i == 0) tong += i;
        }
    }
    cout << tong;
    return 0;
}
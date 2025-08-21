/*
Tính S(n) = 1 + 2 + 3 + ... + n. 
Nhập vào n. 
INPUT : 3.
OUTPUT: 6.
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int tong = 0;
    for(int i = 1; i <= n; i++){
        tong += i;
    }
    cout << tong;
    return 0;
}
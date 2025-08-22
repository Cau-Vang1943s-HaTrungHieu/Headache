/*
Tính tích tất cả “ước số lẻ” của số nguyên dương n.
*/
#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int tich = 1;
    if(n <= 0) cout << -1;
    else {
        for(int i = 1; i <= n; i++){
            if(n % i == 0 && i % 2 != 0) tich *= i;
        }
    }
    cout << tich;
    return 0;
}
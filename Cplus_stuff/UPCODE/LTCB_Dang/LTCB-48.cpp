/*-Nhập n
-Tính tích các chữ số lẻ của số nguyên dương n
-Nếu không có số lẻ,in ra -1
-Nếu có 1 số lẻ,in ra chính nó

INTPUT:123
OUTPUT:3

INPUT:100
OUTPUT:1
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int tich = 1;
    bool ktra = false;
    while(n > 0){
        int cs = n % 10;
        if(cs % 2 != 0){
            tich *= cs;
            ktra = true;
        }
        n /= 10;
    }
    if(ktra == true) cout << tich;
    else cout << -1;
    return 0;
}
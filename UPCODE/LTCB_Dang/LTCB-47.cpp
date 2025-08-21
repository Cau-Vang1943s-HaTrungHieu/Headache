/*- Nhap vao so nguyen duong n. Tinh tong cac chu so chan cua n.*/
#include <iostream>
using namespace std;
int Tongcsc(int n){
    int tong = 0;
    while(n > 0){
        int cs = n % 10;
        if(cs % 2 == 0) tong += cs;
        n /= 10;
    }
    return tong;
}
int main(){
    int n; cin >> n;
    cout << Tongcsc(n);
    return 0;
}
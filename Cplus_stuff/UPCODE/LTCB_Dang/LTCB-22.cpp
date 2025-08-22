/*Tính tích tất cả “ước số” của số nguyên dương n.*/
#include <iostream>
using namespace std;
int TichUS(int n){
    int tich = 1;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) tich *= i;
    }
    return tich;
}
int main(){
    int n;
    cin >> n;
    if(n <= 0) cout << -1;
    else cout << TichUS(n);
    return 0;
}
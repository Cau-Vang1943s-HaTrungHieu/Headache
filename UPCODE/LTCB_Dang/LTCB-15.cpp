/*
-Đếm số lượng "ước số" của số nguyên dương n

INPUT:5
OUTPUT:2
*/
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n <= 0) cout << -1;
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) dem++;
    }
    cout << dem;
    return 0;
}
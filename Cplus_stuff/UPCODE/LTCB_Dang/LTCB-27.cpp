/*-Đếm số lượng "ước số chẵn" của số nguyên dương n

INPUT:36
OUTPUT:6
*/
#include <iostream>
using namespace std;
int USC(int n){
    int dem = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0 && i % 2 == 0) dem++;
    }
    return dem;
}
int main(){
    int n;
    cin >> n;
    if(n <= 0) cout << -1;
    else cout << USC(n);
    return 0;
}
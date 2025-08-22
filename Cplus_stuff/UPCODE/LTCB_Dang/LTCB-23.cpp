/*-Nhập số nguyên dương n
-Đếm số lượng "ước số" của số nguyên dương n.


INPUT:5
OUTPUT:2
*/
#include <iostream>
using namespace std;
int main(){
    int n, dem = 0;
    cin >> n;
    if(n <= 0) cout << -1;
    else {
        for(int i = 1; i <= n; i++){
            if(n % i == 0) dem ++;
        }
    }
    cout << dem;
    return 0;
}
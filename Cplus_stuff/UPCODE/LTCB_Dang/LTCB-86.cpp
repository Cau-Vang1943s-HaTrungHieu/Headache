/*Viết chương trình nhập vào số nguyên n.
Tính S(n) = 1^3 + 2^3 + 3^3 + ... + n^3.
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long S = 0;
    for(int i = 1; i <= n; i++){
        S += i * i * i;
    }
    cout << S;
    return 0;
}
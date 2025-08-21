/*Cho số nguyên dương n. Kiểm tra số dương n có phải là số hoàn thiện
hay không?
Số hoàn thiện là số có tổng các ước số của nó (không bao gồm chính nó) bằng chính nó.
*/
#include <iostream>
using namespace std;
int SHH(int n){
    int tong = 0;
    for(int i = 1; i < n; i++){
        if(n % i == 0) tong +=i;
    }
    return tong == n ? 1 : 0;
}
int main(){
    int n; cin >> n;
    if(n <= 0) cout << -1;
    else {
        if(SHH(n)) cout << "YES";
        else cout << "NO";
    }
}

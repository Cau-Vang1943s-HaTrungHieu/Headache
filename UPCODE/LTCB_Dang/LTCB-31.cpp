/*-Cho số nguyên tố n
-Kiểm tra số nguyên dương n có phải là số nguyên tố hay không?

INPUT:2
OUTPUT:Yes
*/
#include <iostream>
#include <cmath>
using namespace std;
int SNT(int n){
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    int n; cin >> n;
    if(SNT(n)) cout << "Yes";
    else cout << "No";
    return 0;
}
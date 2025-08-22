/*
Nhập vào một số nguyên bất kỳ. 
Yêu cầu: Kiểm tra số đó có phải là số nguyên tố hay không. 

Input: Nhập vào một số nguyên a (-2147483648 ≤ a ≤ 2147483647)
Output: Xuất ra "Yes" nếu đó là số nguyên tố, "No" nếu đó không phải là số nguyên tố


Ví dụ:
input
5
11
-36
128
8931
255

output
Yes
Yes
No
No
No
No
*/
#include <bits/stdc++.h>
using namespace std;
int SNT(int n){
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}
int main(){
    int n;
    while(cin >> n){
        if(SNT(n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
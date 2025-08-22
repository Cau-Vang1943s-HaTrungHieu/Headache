/*
Viết hàm đếm số lượng số nguyên tố nhỏ hơn 100 trong mảng.
Nhập vào mảng gồm n phần tử (với n <= 10) với n là số nguyên dương và mảng cũng chỉ bao gồm số nguyên dương.
Khi nhập thì nhập n trước sau đó mới nhập mảng.

Ví dụ:

Input
5 239 240 31 47 50
Output
2
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
    int n;
    cin >> n;
    int a[10];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int dem = 0;
    for(int i = 0; i < n;i++){
        if(SNT(a[i]) && a[i] < 100){
            dem++;
        }
    }
    cout << dem;
    return 0;
}
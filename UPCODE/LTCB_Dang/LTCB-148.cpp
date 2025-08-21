/*
Tìm số nguyên tố cuối cùng trong mảng một chiều có 5 phần tử các số nguyên. Nếu mảng không có số nguyên tố thì trả về giá trị -1.
ví dụ:
input:
5
7
98
2
9
output:
2
*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n = 5; 
    int a[5];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--){
        if(a[i] < 2) continue;
        bool SNT = true;
        for(int j = 2; j <= sqrt(a[i]); j++){
            if(a[i] % j == 0){
                SNT = false;
                break;
            }
        }
        if(SNT){
            cout << a[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
/*

Tìm “số hoàn thiện cuối cùng” trong mảng một chiều có 5 phần tử các số nguyên. Nếu mảng không có số hoàn thiện thì hàm sẽ trả về giá trị -1.
input:
3
7
9
6
2
output:
6

*/
#include <iostream>
using namespace std;
int main(){
    int n = 5;
    int a[5];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--){
        if(a[i] <= 1) continue;
        int tong = 0;
        for(int j = 1; j < a[i]; j++){
            if(a[i] % j == 0) tong += j;
        }
        if(tong == a[i]){
            cout << a[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
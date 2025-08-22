/*

Tìm “số dương cuối cùng” trong mảng có 5 phần tử số thực. Nếu mảng không có giá trị dương thì trả về giá trị - 1.
ví dụ: 
input: 
6
0
3
-2
9.5
output:
9.5

*/
#include <iostream>
using namespace std;
int main(){
    int n = 5;
    double a[5];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--){ // Duyệt từ cuối mảng về đầu
        if(a[i] > 0) {
            cout << a[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
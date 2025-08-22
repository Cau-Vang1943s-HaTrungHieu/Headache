/*
Nhập vào mảng số thực dương. (số phần tử <= 20)
Tìm “giá trị dương đầu tiên” trong mảng một chiều các số thực
Nếu mảng không có giá trị dương thì trả về giá trị -1.
Input:
Dòng đầu nhập n chỉ số phần tử của mảng. 
Dòng hai nhập giá các phần tử trong mảng.
*/
#include <iostream>
using namespace std;
int main(){
    float a[20];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] > 0) {
            cout << a[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
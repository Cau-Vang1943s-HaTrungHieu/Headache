/*
Nhập vào số lượng phần tử mảng n(n<=100) (n là số nguyên)
Nhập lần lượt các giá trị mảng (số thực)
Xuất ra giá trị nhỏ nhất
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    double min = 1e9;
    double a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < min) min = a[i];
    }
    cout << min;
    return 0;
}
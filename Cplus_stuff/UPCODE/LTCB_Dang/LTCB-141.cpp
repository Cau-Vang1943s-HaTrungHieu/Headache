/*
Nhập vào số lượng mảng 1 chiều n (n<=100) (n là số nguyên)
Nhâp lần lượt cac giá trị của mảng (là các số thực)
Xuất ra vị trí có giá trị dương nhỏ nhất, nếu không có giá trị dương nào xuất ra -1.
*/
#include <iostream>
#include <climits>
using namespace std;
int main(){
    int n;
    cin >> n;
    double a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    double min_duong = 1e9;
    int vi_tri = -1;

    for(int i = 0; i < n; i++){
        if(a[i] > 0 && a[i] < min_duong){
            min_duong = a[i];
            vi_tri = i;
        }
    }

    cout << vi_tri;
    return 0;
}
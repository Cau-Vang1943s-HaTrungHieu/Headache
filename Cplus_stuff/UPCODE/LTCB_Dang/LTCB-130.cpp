/*
Viết hàm xuất mảng một chiều các số thực. 
Dòng đầu nhập số nguyên dương n là số phần tử trong mảng
Dòng thứ 2 gồm n số thực (có thể âm)
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    double a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
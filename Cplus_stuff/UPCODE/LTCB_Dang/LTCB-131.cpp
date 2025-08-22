/*
Viết hàm xuất mảng một chiều các số nguyên. 
Dòng đầu nhập số nguyên dương n là số phần tử trong mảng
Dòng thứ 2 gồm n số nguyên (có thể âm).
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}
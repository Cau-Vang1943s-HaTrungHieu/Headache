/*
Tìm “số chẵn cuối cùng” trong mảng một chiều các số nguyên.
Nếu mảng không có giá trị chẵn thì trả về giá trị -1.
Dòng đầu nhập vào số n
Dòng 2 nhập mảng
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
    int VT = -1;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0) VT = i;      
    }
    if(VT == -1) cout << -1;
    else cout << a[VT];
    return 0;
}
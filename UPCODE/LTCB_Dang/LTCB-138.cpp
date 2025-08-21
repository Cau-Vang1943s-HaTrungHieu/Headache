/*
Tìm “vị trí của giá trị chẵn đầu tiên” trong mảng một chiều các số nguyên. 
Nếu mảng không có giá trị chẵn thì hàm sẽ trả về giá trị là – 1.
Input: 
 Hàng đầu là số n. 
 Hàng hai là mảng
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
    int Vt = -1;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            Vt = i;
            break;
        }
    }
    if(Vt == -1) cout << -1;
    else cout << Vt;
    return 0;
}
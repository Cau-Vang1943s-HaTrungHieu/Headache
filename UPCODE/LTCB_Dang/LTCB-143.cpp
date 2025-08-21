/*

Nhap số lượng phần tử n (n<100) (số nguyên)
Nhập giá trị mảng
Xuất số chẵn đầu tiên
Không có số chẵn xuất -1

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
        if(a[i] % 2 == 0){
            cout << a[i];
            return 0;
        }
    }
    cout << -1;
    return 0;
}
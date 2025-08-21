/*
Viết hàm liệt kê các giá trị chẵn trong mảng một chiều các số nguyên. 
(Số 0 được tính là số chẵn). 
Nếu mảng không có số chẵn nào thì xuất ra -1.
Dòng đầu nhập số nguyên dương n là số phần tử trong mảng.
Dòng thứ 2 gồm n số nguyên lớn hơn 0.
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
    bool ktra = false;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0) {
            cout << a[i] << " ";
            ktra = true;
        }
    }
    if(ktra == false) cout << -1;
    return 0;
}
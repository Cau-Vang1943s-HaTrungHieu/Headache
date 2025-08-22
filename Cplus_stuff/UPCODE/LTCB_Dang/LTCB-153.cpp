/*

Xuất giá trị chẵn nhỏ nhất trong mảng 1 chiều các số nguyên. Nếu mảng không có giá trị chẵn thì trả về -1
Input
Dòng 1: nhập số lượng phần tử
Dòng 2: nhập vào các phần tử có trong mảng (cách nhau bởi khoảng trắng)
Output: xuất ra kết quả
Mẫu :
input                                      output
5                                            4
1 4 9 8 5

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
    int min = 1e9;
    bool ktra = false;
    int Vt= -1;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0 && a[i] < min){
            min = a[i];
            Vt = i;  // Lưu vị trí nếu cần
            ktra = true;
        }
    }
    if(ktra == true) cout << min << " " << Vt;  // In giá trị chẵn nhỏ nhất và vị trí của nó
    else cout << -1;
    return 0;
}
// Bổ sung thêm nếu in vị trí của giá trị chẵn nhỏ nhất
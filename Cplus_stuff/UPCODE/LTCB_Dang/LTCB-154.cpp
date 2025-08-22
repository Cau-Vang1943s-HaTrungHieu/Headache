/*

Xuất vị trí chứa giá trị âm nhỏ nhất trong mảng 1 chiều các số nguyên. Nếu không có số âm nào thì xuất ra -1
Input
Dòng 1: nhập số lượng phần từ có trong mảng
Dòng 2: nhập các phần tử có trong mảng (cách nhau bằng khoảng trắng)
Output : xuất ra kết quả
Mẫu:
input                                            
4                                                 
-2 4 8 -8
output:
3

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
    int min_neg = 1e9;  // Thay đổi từ max thành min_neg
    bool ktra = false;
    int Vtri = -1;
    for(int i = 0; i < n; i++){
        if(a[i] < 0 && a[i] < min_neg) {  // Thay đổi điều kiện từ > thành <
        min_neg = a[i];
        Vtri = i;  // Bỏ + 1 để tính từ index 0
        ktra = true;
        }
    }
    if(ktra == true) cout << Vtri;
    else cout << -1;
    return 0;
}
/* - Nhap so nguyen duong n. Dem so luong chu so cua n.*/\
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dem = 0;
    while(n > 0){
        n /= 10; // Chia n cho 10 để loại bỏ chữ số cuối
        // Mỗi lần chia, ta tăng biến đếm lên 1
        dem++;
    }
    cout << dem;
}
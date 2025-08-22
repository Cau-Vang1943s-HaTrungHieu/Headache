/*-Nhập số nguyên dương n
-Tính tổng các chữ số của số nguyên dương n
*/
#include <iostream>
using namespace std;
int main() {
    int n, tong = 0;
    cin >> n;
    while(n > 0){
        int cs = n % 10; // Lấy chữ số cuối
        // Cộng chữ số cuối vào tổng
        // Sau đó loại bỏ chữ số cuối bằng cách chia n cho 10
        tong += cs;
        n /= 10; // Loại bỏ chữ số cuối
    }
    cout << tong;
    return 0;
}
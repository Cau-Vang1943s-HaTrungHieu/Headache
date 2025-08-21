/*
Nhập số nguyên n.
Tính S(n) = 1+1/2+1/3+...+1/n.
Chú ý: Kết quả làm tròn đến chữ số thập phân thứ 2.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n < 0) {
        cout << -1;
        return 0;
    }
    
    double tong = 0.0;
    for(int i = 1; i <= n; i++){
        tong += 1.0 / i;  // Dùng 1.0 để đảm bảo phép chia là số thực
    }
    
    cout << round(tong * 100) / 100; // Làm tròn đến 2 chữ số thập phân mà ko dùng fixed << setprecision(2) bởi vì nó sẽ làm tròn theo quy tắc thông thường
    return 0;
}
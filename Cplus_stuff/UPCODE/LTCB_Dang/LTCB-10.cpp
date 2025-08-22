/*Nhập vào số thực x và số nguyên dương n từ bàn phím (cách nhau bởi dấu ' ').
In ra màn hình kết quả của phép tính xn  (lấy đến chữ số thập phân thứ 3).
Ví dụ:
Input: 3 2
Output: 9.000
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float x;
    int n;
    cin >> x >> n;
    float lt = 1;

    if (n < 0) {
        cout << -1;  
    } else {
        for (int i = 1; i <= n; i++) {
            lt *= x;
        }
        cout << fixed << setprecision(3) << lt;  
    }

    return 0;
}
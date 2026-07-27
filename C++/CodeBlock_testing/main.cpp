#include <iostream>
#include <cmath>
using namespace std;
bool laSoNguyen(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhập số nguyên n: ";
    cin >> n;

    if (n <= 2) {
        cout << "Không có số nguyên tố nào nhỏ hơn " << n << endl;
    } else {
        cout << "Các số nguyên tố nhỏ hơn " << n << " là: ";
        for (int i = 2; i < n; i++) {
            if (laSoNguyen(i)) {
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    // Nếu không có bóng đỏ, không thể chắc chắn lấy được bóng đỏ
    if (A == 0) {
        cout << -1 << endl; // hoặc thông báo không thể thực hiện
    } else {
        cout << B + 1 << endl;
    }

    return 0;
}
// nay ham
// mai ktra qua trinh
// thu 5 mang va cau truc
// tuan sau thu 5 thi cuoi ky (sang)
/*
Liệt kê tất cả số chính phương nhỏ hơn n
Nhập vào n
Nếu n không hợp lệ thì in ra -1
Ví dụ:

Input

Output

Input mẫu

120

Output mẫu

1 4 9 16 25 36 49 64 81 100
Ví dụ:

Input

Output

Input mẫu

1

Output mẫu

-1
*/
#include <iostream>
#include <cmath>    
using namespace std;
bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return (root * root == n);
}
int main(){
    int n;
    cin >> n;
    if(n <= 1) cout << -1;
    else {
        for(int i = 1; i < n; i++) {
            if(isPerfectSquare(i)) {
                cout << i << " ";
            }
        }
    }
}

// Cách 2: Sử dụng vòng lặp for
/*#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n <= 1) {
        cout << -1;
    } else {
        for (int i = 1; i * i < n; i++) {
            cout << i * i << " ";
        }
    }
    return 0;
}*/
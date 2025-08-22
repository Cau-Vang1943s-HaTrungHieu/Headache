/*
Viết chương trình nhập 3 số thực a b c. Hãy thay tất cả các số âm bằng trị
tuyệt đối của nó và xuất ra màn hình

ví dụ
input
1 2 -2.3
output
1 2 2.3

*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    a = abs(a);
    b = abs(b);
    c = abs(c);
    cout << a << " " << b << " " << c;
}
// Cách 2: Sử dụng hàm fabs
/*#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    a = fabs(a);
    b = fabs(b);
    c = fabs(c);
    cout << a << " " << b << " " << c;
}*/
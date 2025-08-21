/*
Nhập vào 2 số nguyên dương 

Yêu cầu: Xuất ra ước chung lớn nhất của 2 số nguyên dương này

Input: Dòng đầu tiên sẽ chứa hai số nguyên dương a và b (1 ≤ a , b ≤ 4294967295)
Output: Ước chung lớn nhất của hai số nguyên dương này

Ví dụ: 
input
2 3
3 12
48 10
64 568
718 6897
1024 720
6555 15555
16598 8299

output
1
3
2
8
1
16
15
8299
*/
#include <iostream>
using namespace std;
int UCLN(int a, int b){
    a = abs(a);
    b = abs(b);
    while(b != 0){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int main(){
    unsigned long long a, b;
    while(cin >> a >> b) cout << UCLN(a, b) << endl;
    return 0;
}
// Cách 2: Sử dụng hàm __gcd từ thư viện <algorithm>
/*#include <iostream>
#include <algorithm>   
using namespace std;
int main(){
    unsigned long long a, b;
    while(cin >> a >> b) cout << __gcd(a, b) << endl;
    return 0;
}*/
/*
Cho n là số nguyên dương. Hãy tìm giá trị nguyên dương k lớn nhất sao cho S(k) < n. Trong đó chuỗi S(k) được định nghĩa như sau : S(k) = 1 + 2 + 3 + ... + k. 
 Yêu cầu bài toán: nhập số nguyên dương n xuất k là số hạn cuối cùng của chuỗi S(k) = 1+2+3+4+...+k sao cho S(k)



Ví dụ:

Input
4
Output
2

*/
#include <iostream>
using namespace std;
int main(){
    int n; cin >> n;
    int k = 0;
    int S = 0;
    while(S < n){
        k++;
        S += k;
    }
    cout << k - 1;
    return 0;
}
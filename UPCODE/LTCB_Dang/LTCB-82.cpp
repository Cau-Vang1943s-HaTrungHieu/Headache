/*
Viết chương trình tìm số lớn nhất trong ba số thực a, b, c. Nhập 3 số thực a, b, c. Xuất số lớn nhất trong 3 số.
*/
#include <iostream>
using namespace std;
int main(){
    double a,b,c;
    cin >> a >> b >> c;
    double max = a;
    if(b > max) max = b;
    if(c > max) max = c;
    cout << max;
    // Cách 2: Sử dụng hàm max
    /*
    cout << max({a, b, c}); 
    */
    return 0;
}
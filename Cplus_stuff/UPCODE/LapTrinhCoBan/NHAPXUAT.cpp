/***********************************************
    Viết chương trình nhập vào 2 số nguyên a,b, yêu cầu xuất ra tổng 2 số nguyên đó theo định dạng
    a+b = tổng.

    ví dụ:
    input:
    2 3

    output
    2+3=5
***********************************************/

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    cout << a << "+" << b << "=" << a + b << endl;

    return 0;
}
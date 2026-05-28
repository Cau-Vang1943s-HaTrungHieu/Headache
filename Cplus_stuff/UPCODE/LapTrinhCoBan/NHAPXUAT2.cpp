/***********************************************
    Nhập vào 2 số a và b
    Yêu cầu hoán vị giá trị của a và b, sau đó xuất kết quả ra màn hình

    ví dụ:

    input:
    2 3

    output
    3 2
***********************************************/

#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    cin >> a >> b;
    swap(a, b);
    cout << a << " " << b << endl;

    return 0;
}
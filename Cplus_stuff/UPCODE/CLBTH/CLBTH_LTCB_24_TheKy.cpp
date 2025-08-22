#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int n;
    cin >> n;

    cout << (n + 99) / 100;

    return 0;
}

/*
Thêm 99 để xử lý đúng cho các năm nằm chính xác đầu thế kỷ, ví dụ:

Năm 200 → (200 + 99)/100 = 299/100 = 2

Năm 201 → (201 + 99)/100 = 300/100 = 3
*/
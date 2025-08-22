/*
Viết chương trình nhập vào n và in ra tất cả các số lẻ từ 1 đến n, trừ các số 5, 7, 93. mỗi số cách nhau 1 khoảng trắng
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i += 2){
        if(i == 5 || i == 7 || i == 93) continue;
        cout << i << " ";
    }
    return 0;
}
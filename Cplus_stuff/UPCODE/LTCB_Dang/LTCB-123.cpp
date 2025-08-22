/*
Viết hàm tìm một vị trí mà giá trị tại vị trí đó là một giá trị nhỏ nhất trong mảng một chiều các số nguyên
Input: nhập vào n là số phần tử trong mảng
       nhập vào các giá trị trong mảng( cách nhau bởi một dấu cách)
Output: xuất ra vị trí chứa giá trị nhỏ nhất
Ví dụ:

Input
3
5 3 -5
Output
2
*/
#include <iostream>
using namespace std;
int findMinIndex(int a[], int n){
    int min = 0;
    for(int i = 1; i < n; i++){
        if(a[i] < a[min]) min = i;
    }
    return min;
}
int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << findMinIndex(a, n);
    return 0;
}
/*Tìm “một vị trí mà giá trị tại vị trí đó là giá trị nhỏ nhất” trong mảng một chiều các số thực.
Input:
Dòng đầu là số n chỉ số phần tử của mảng.
Dòng hai là các giá trị của mảng.
*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    float a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int min = {0};
    for(int i = 1; i < n; i++){
        if(a[i] < a[min]) min = i;
    }
    cout << min;
    return 0;
}
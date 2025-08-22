/*
Viết hàm tính tổng các giá trị âm trong mảng một chiều các số thực.
Với n là số phần tử của mảng được nhập vào từ bản phím (n <= 10), n là số nguyên dương và mảng là tập hợp nhiều phần tử số thực.
Thứ tự nhập dữ liệu: nhập n rồi mới tới nhập mảng.
Kết quả làm tròn đến số thập phân thứ 2.
Ví dụ:

Input
4 -1.145 3 -145 0
Output
-146.15
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    double a[10];
    double tong = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0) tong += a[i];
    }
    cout << round(tong * 100) / 100 << endl; 
    return 0;
}

// Cách 2:
/* #include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>
using namespace std;

void nhap(float a[], int& n){
    cin >>n; 
    if (n<0) cout <<-1;
    for (int i=0; i<n; i++){
        cin >>a[i];
    }
}

int main (){
    int n;
    float a[10];
    nhap(a,n);
    
    float tong=0;
    for (int i=0; i<n; i++){
        if (a[i]<0) tong+=a[i];
    }
  
    cout <<(round(tong * 100))/100;
    return 0;
}
*/
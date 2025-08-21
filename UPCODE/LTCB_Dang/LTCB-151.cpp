/*
Hãy tìm “số nguyên tố lớn nhất” trong mảng một chiều các số nguyên; 
Nếu mảng không có số nguyên tố thì trả về giá trị 0.
Dòng thứ nhất nhập số phần tử của mảng.
Dòng thứ 2 nhập mảng.
 Ví dụ:
Input:
4
3 6 9 11

Output:
11

*/
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int maxSNT = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 2) continue;
        bool SNT = true;
        for(int j = 2; j <= sqrt(a[i]); j++){
            if(a[i] % j == 0){
                SNT = false;
                break;
            }
        }
        if(SNT && a[i] > maxSNT){
            maxSNT = a[i];
        }
    }
    cout << maxSNT;
    return 0;
}
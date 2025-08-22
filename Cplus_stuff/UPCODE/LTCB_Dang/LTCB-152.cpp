/*

Hãy tìm “hoàn thiện nhỏ nhất” trong mảng một chiều các số nguyên; 
Nếu mảng không có số hoàn thiện thì trả về giá trị 0.
Dòng thứ nhất nhập số lượng phần tử của mảng.
Dòng thứ hai nhập mảng.
Ví dụ:
Input:
4
6 28 7 3

Output:
6

*/
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[1000];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int min = 0;
    for(int i = 0; i < n; i++){
        if(a[i] <= 1) continue;
        int tong = 0;
        for(int j = 1; j <a[i]; j++){
            if(a[i] % j == 0){
                tong += j;
            }
        }
        if(tong == a[i] && (min == 0 ||a[i] < min)){
            min = a[i];
        }
    }
    cout << min;
    return 0;
}